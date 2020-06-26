module exp_taylor_pp (
    input clk,    // Clock
    input rst_n,  // Asynchronous reset active low
    input [11:0] iData, // input is {integer,faction}, 4-bit signed integer, 8-bit fraction
    input iDataValid,
    output [19:0] oData, // output is {integer, fraction}, 12-bit integer and 4-bit fraction
    output oDataValid
);
    
    assign oDataValid = 0;
    // watershed decision
    // 0.75 => 0.11, better and easier
    // 0.625 => 0.101
    // asserted if input is larger than 0.75
    logic sign2Kernel;
    assign sign2Kernel = (&iData[7:6]);

    // when iData is less than 0.75 (sign2Kernel deasserted), keep origin
    // when iData is larger than 0.75, use (idata-1) as input, which is negtive.
    logic [7:0] data2Kernel;
    logic [8:0] iData_neg;
    assign iData_neg = (9'd256-{1'b0,iData});
    assign data2Kernel = sign2Kernel ? iData_neg[7:0] : iData;

    // computing kernel takes an 8-bit all-fraction input.
    logic [9:0] kernelOut; // {integer, fraction}, {2,8}, unsigned
    computing_kernel_pp U_computing_kernel(
        .clk(clk),
        .rst_n(rst_n),
        .iData(data2Kernel),
        .iSign(sign2Kernel),
        .oData(kernelOut)
        );

    // LUT for final result
    // input to the LUT is extended by 1 bit from original 4 bits to 5 bits.
    logic [4:0] lutIn;
    assign lutIn = sign2Kernel ? ({iData[11],iData[11:8]} + 4'b1) : {iData[11],iData[11:8]};

    logic [15:0]lutOut; // {integer, fraction}, {12, 4}, unsigned
    lut_exp_integer U_lut_exp_integer(
        .iData(lutIn),
        .oData(lutOut)
        );

    logic [15:0] lutOutBuf [4:0];
    always_ff @(posedge clk or negedge rst_n) begin : proc_lutOutBuf
        if(~rst_n) begin
            lutOutBuf[0] <= 0;
            lutOutBuf[1] <= 0;
            lutOutBuf[2] <= 0;
            lutOutBuf[3] <= 0;
            lutOutBuf[4] <= 0;
        end else begin
            lutOutBuf[0] <= lutOut;
            lutOutBuf[1] <= lutOutBuf[0];
            lutOutBuf[2] <= lutOutBuf[1];
            lutOutBuf[3] <= lutOutBuf[2];
            lutOutBuf[4] <= lutOutBuf[3];
        end
    end

    // final result
    // buffer is 10+16 bit long, need 4 8x8 multiplier
    logic [25:0] oDataBuf;
    always_ff @(posedge clk or negedge rst_n) begin : proc_
        if(~rst_n) begin
            oDataBuf <= 0;
        end else begin
            oDataBuf <= lutOutBuf[4] * kernelOut;
        end
    end
    assign oData = {2'b0,oDataBuf[25:8]};

endmodule