`include "mul_precise.sv"
module computing_kernel_npp (
    input clk,    // Clock
    input rst_n,  // Asynchronous reset active low
    input [7:0] iData, // input is {faction}, 8-bit are all fraction, always positive. this value is |t| (t=x when x <0.75; t=x-1 when x > 0.75)
    input iSign, // 0 indicate a positive iData
    input iDataValid,
    output [9:0] oData, // output is {2, 8}, 2-bit integer and 8-bit fraction
    output oDataValid
);
    // cnt for counting how many cycles has been processed
    logic [2:0]cnt;
    always_ff @(posedge clk or negedge rst_n) begin : proc_cnt
        if(~rst_n) begin
            cnt <= 0;
        end else begin
            cnt <= iDataValid ? 1 : (oDataValid ? cnt : ((cnt == 0) ? cnt : (cnt + 1)));
        end
    end
    assign oDataValid = (cnt == 5);
    
    logic [9:0] sum; // sum is {2, 8}
    logic [7:0] prod; // prod is {0, 8}
    logic [7:0] data; // data is {0, 8}
    logic sign; // sign is 1-bit
    logic [15:0] mulOut; // multiplication result
    logic [7:0] mulOutValid; // multiplication result truncated

    // pipeline
    // input data and sign are directly pipeline
    always_ff @(posedge clk or negedge rst_n) begin : proc_data_sign
        if(~rst_n) begin
            data <= 0;
            sign <= 0;
        end else begin
            data <= iDataValid ? iData : data;
            sign <= iDataValid ? iSign : sign;
        end
    end

    // sum generation
    always_ff @(posedge clk or negedge rst_n) begin : proc_sum
        if(~rst_n) begin
            sum <= 0;
        end else begin
            sum <= iDataValid ? (iSign ? (10'd256 - iData) : (10'd256 + iData)) : (oDataValid ? sum : (sign & (cnt == 2)) ? (sum - prod) : (sum + prod));
        end
    end

    // prod generation
    always_ff @(posedge clk or negedge rst_n) begin : proc_prod
        if(~rst_n) begin
            prod <= 0;
        end else begin
            prod <= mulOutValid;
        end
    end

    logic [7:0] prodShifted;
    always_comb begin : proc_prodShifted
        case (cnt)
            3'd1: prodShifted = {2'b0,prod[7:2]};
            default : prodShifted = {1'b0,prod[7:1]};
        endcase
    end

    logic [7:0] mulInA;
    logic [7:0] mulInB;
    assign mulInA = iDataValid ? iData : ((cnt == 3) ? 1 : data);
    assign mulInB = iDataValid ? {1'b0,iData[7:1]} : prodShifted;
    multiplier U_multiplier_0(
        .A(mulInA),
        .B(mulInB),
        .O(mulOut)
        );
    assign mulOutValid = mulOut[15:8];

    assign oData = sum;

endmodule
