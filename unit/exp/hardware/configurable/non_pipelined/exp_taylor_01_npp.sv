`include "param_def.sv"
`include "modules.v"
`include "multiplier.sv"
`include "shifter_12.sv"
`include "accumulator.sv"

module exp_taylor_01_npp (
    input logic clk,    // Clock
    input logic rst_n,  // Asynchronous reset active low
    
    input logic [`FRACWIDTH-1 : 0] iData, // input is FRACWIDTH-bit fraction
    input logic iDataValid, // start new calculation

    input logic oDataRead, // prepare to stop, need one more cycle after end comes, due to computing the product
    output logic [`FRACWIDTH-1 : 0] oData, // output is {integer, fraction}, 16-bit integer and 4-bit fraction
    output logic oDataValid // output valid
);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // signal definition
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // fsm cnt
    logic [3:0] cnt;
    logic cnt2;
    logic cnt3;
    logic cnt4;
    logic cntmax;

    logic bypass;
    logic sel_in_buf; // select the input to the in_buf
    logic sel_mul_a; // select the input the a port of mul
    logic sel_mul_b; // select the input the b port of mul
    logic sel_prod; // select the input to the prod register
    logic sel_sum; // select the input to the sum register

    logic oDataValid_q;
    // input data buffer
    logic largereqTh;
    logic largereqTh_q;
    logic [`FRACWIDTH-1 : 0] iData_comp; // 1 - input

    logic [`FRACWIDTH-1 : 0] in_buf_in;
    logic [`FRACWIDTH-1 : 0] in_buf;

    // multiplier
    logic [`FRACWIDTH-1 : 0] mul_a;
    logic [`FRACWIDTH-1 : 0] mul_b;
    logic [`FRACWIDTH*2-1 : 0] mul_o;

    // prod register
    logic [`FRACWIDTH-1 : 0] prod_in;
    logic [`FRACWIDTH-1 : 0] prod;

    // shifter
    logic [`FRACWIDTH-1 : 0] shift_in;
    logic shift_os;
    logic [`FRACWIDTH-1 : 0] shift_out;

    // accumulator
    logic acc_s_coeff;
    logic [`FRACWIDTH+1 : 0] acc_a;
    logic [`FRACWIDTH+1 : 0] acc_b;
    logic acc_s;
    logic [`FRACWIDTH+1 : 0] acc_o;

    // sum register
    logic [`FRACWIDTH+1 : 0] sum_in;
    logic [`FRACWIDTH+1 : 0] sum;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // FSM
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // generate all control signals
    always_ff @(posedge clk or negedge rst_n) begin : proc_cnt
        if(~rst_n) begin
            cnt <= 0;
        end else begin
            if(iDataValid) begin
                cnt <= 1;
            end else begin
                if(cntmax) begin
                    cnt <= cnt;
                end else begin
                    if(oDataRead) begin
                        cnt <= `MAXTERM;
                    end else begin
                        cnt <= cnt + 1;
                    end
                end
            end
        end
    end

    assign cnt2 = (cnt == 2);
    assign cnt3 = (cnt == 3);
    assign cnt4 = (cnt == 4);
    assign cntmax = (cnt == `MAXTERM);

    always_ff @(posedge clk or negedge rst_n) begin : proc_oDataRead_d1
        if(~rst_n) begin
            oDataValid_q <= 0;
        end else begin
            oDataValid_q <= cntmax;
        end
    end
    assign oDataValid = oDataValid_q & ~iDataValid;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // input buffer
    // store x or (1-x) according to threshold
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // check if input is larger than threshold
    // asserted if true
    assign largereqTh = (iData[`FRACWIDTH-1 : `FRACWIDTH-3] >= `THD);
    // sel_0
    assign sel_in_buf = largereqTh;
    // absolute value of (input - 1) when input is larger than threshold
    assign iData_comp = (1<<`FRACWIDTH) - iData;
    assign in_buf_in = sel_in_buf ? iData_comp : iData;
    always_ff @(posedge clk or negedge rst_n) begin : proc_in_buf
        if(~rst_n) begin
            in_buf <= 0;
        end else begin
            if(iDataValid) begin
                in_buf <= in_buf_in;
            end else begin
                in_buf <= in_buf;
            end
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin : proc_largereqTh_q
        if(~rst_n) begin
            largereqTh_q <= 0;
        end else begin
            if(iDataValid) begin
                largereqTh_q <= largereqTh;
            end else begin
                largereqTh_q <= largereqTh_q;
            end
        end
    end

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // multiplier
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // port a is on the left of diagram
    // sel1, change when mul bypass happens
    assign bypass = (cnt >= `MULBYPASS);
    assign sel_mul_a = bypass;
    // when mul bypass, change to `EXP1
    assign mul_a = iDataValid ? in_buf_in : (sel_mul_a ? `EXP1 : shift_out); // the last cycle, multiplied by 1 if input is less than threshold

    // sel2, change when ready to read
    assign sel_mul_b = oDataRead;
    // when oDataRead
    assign mul_b = iDataValid ? in_buf_in : (sel_mul_b ? sum[`FRACWIDTH+1 : 2] : in_buf); // the intermediate cycle, multiplied by input

    multiplier U_mul(
        .A(mul_a), // the power term
        .B(mul_b), // the input
        .O(mul_o)); // the output, to be shifted

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // prod
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // sel3, change when 1) intit, 2) normal, 3) bypass mul
    assign sel_prod = bypass;
    assign prod_in = iDataValid ? {1'b0, mul_o[`FRACWIDTH*2-1:`FRACWIDTH+1]} : // the first cycle, for initialization
                    ((~sel_prod) ? mul_o[`FRACWIDTH*2-1:`FRACWIDTH] : // no bypass
                      shift_out); // bypass multiplication if no exponent increasing

    always_ff @(posedge clk or negedge rst_n) begin : proc_prod
        if(~rst_n) begin
            prod <= 0;
        end else begin
            prod <= prod_in;
        end
    end

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // shifter
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    assign shift_in = prod;
    // sel4
    // a prestored data array
    // for uniform input
    `ifdef BIT8UNI
        assign shift_os = 0;
    `elsif BIT12UNI
        assign shift_os = 0;
    `elsif BIT16UNI
        assign shift_os = cnt2;
    `elsif BIT8G075
        assign shift_os = 0;
    `elsif BIT8G050
        assign shift_os = 0;
    `elsif BIT8G025
        assign shift_os = 0;
    `elsif BIT12G075
        assign shift_os = cnt2;
    `elsif BIT12G050
        assign shift_os = 0;
    `elsif BIT12G025
        assign shift_os = 0;
    `endif

    shifter_12 U_shifter_12(
        .iData(shift_in),
        .offset(shift_os),
        .oData(shift_out)
        );

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // accumulator
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // port a is on the left of diagram
    assign acc_b = sum;
    assign acc_a = prod;
    // a prestored data array
    `ifdef BIT8UNI
        assign acc_s_coeff = (cnt == 3); // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? cnt2: 0); // sign of exponent of power
    `elsif BIT12UNI
        assign acc_s_coeff = (cnt == 3); // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? (cnt2 | cnt4): 0); // sign of exponent of power
    `elsif BIT16UNI
        assign acc_s_coeff = 0; // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? cnt2: 0); // sign of exponent of power
    `elsif BIT8G075
        assign acc_s_coeff = (cnt == 3); // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? cnt2: 0); // sign of exponent of power
    `elsif BIT8G050
        assign acc_s_coeff = (cnt == 4) | (cnt == 5) | (cnt == 6); // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? cnt2: 0); // sign of exponent of power
    `elsif BIT8G025
        assign acc_s_coeff = (cnt == 4); // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? cnt2: 0); // sign of exponent of power
    `elsif BIT12G075
        assign acc_s_coeff = (cnt == 3); // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? cnt2: 0); // sign of exponent of power
    `elsif BIT12G050
        assign acc_s_coeff = (cnt == 3); // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? (cnt2 | cnt4): 0); // sign of exponent of power
    `elsif BIT12G025
        assign acc_s_coeff = (cnt == 3); // sign of coeff
        assign acc_s = acc_s_coeff ^ (largereqTh_q ? cnt2: 0); // sign of exponent of power
    `endif
    
    accumulator U_accumulator(
        .A(acc_b), // from sum reg
        .B(acc_a), // from prod reg
        .S(acc_s), // substraction indicator
        .O(acc_o)); // to sum reg

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // sum
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // sum data is always {2, fraction - 2}
    // sel5, change when init, normal, final
    assign sel_sum = cntmax;
    assign sum_in = iDataValid ? (largereqTh ? {2'b00, iData}: {2'b01, iData}) : // the first cycle, when x is smaller than threshold, it is 1+x; otherwise x
                   ((~sel_sum) ? acc_o : // intermediate cycle, use the accumulation result
                   (largereqTh_q ? mul_o[`FRACWIDTH*2-3:`FRACWIDTH-4] : sum)); // the last cycle, when x is smaller than threshold, it is sum; otherwise exp1*sum

    always_ff @(posedge clk or negedge rst_n) begin : proc_sum
        if(~rst_n) begin
            sum <= 0;
        end else begin
            sum <= sum_in;
        end
    end

    assign oData = sum[`FRACWIDTH+1 : 2];
    
endmodule