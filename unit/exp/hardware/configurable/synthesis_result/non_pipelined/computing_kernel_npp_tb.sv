`timescale 1ns/1ns
module computing_kernel_npp_tb ();

    reg clk;
    reg rst_n;
    reg [7:0] iData;
    reg iSign;
    reg iDataValid;

    wire [9:0] oData;
    wire oDataValid;

    always begin : proc_clk
        #5 clk <= ~clk;
    end

    initial begin
        clk <= 1;
        rst_n <= 0;
        #57 rst_n <= 1;
        iDataValid <= 1;
        iData <= 128;
        iSign <= 1'b0;
        #10
        iDataValid <= 0;
        iData <= 0;
        iSign <= 1;

        #100
        iDataValid <= 1;
        iData <= 63;
        iSign <= 1'b1;
        #10
        iDataValid <= 0;
        iData <= 0;
        iSign <= 0;

    end

    // initial begin
    //     #5;
    //     repeat (100) begin
    //         iData <= $random();
    //         iSign <= $random();
    //         iDataValid <= $random();
    //         #10;
    //     end
    // end

    computing_kernel_npp U_computing_kernel_npp(
        .clk(clk),
        .rst_n(rst_n),
        .iData(iData),
        .iSign(iSign),
        .iDataValid(iDataValid),
        .oData(oData),
        .oDataValid(oDataValid)
        );

endmodule