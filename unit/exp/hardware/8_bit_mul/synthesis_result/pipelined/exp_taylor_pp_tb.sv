`timescale 1ns/1ns
module exp_taylor_pp_tb ();

    reg clk;
    reg rst_n;
    reg [11:0] iData;
    reg iDataValid;

    wire [19:0] oData;
    wire oDataValid;

    always begin : proc_clk
        #5 clk <= ~clk;
    end

    initial begin
        clk <= 1;
        rst_n <= 0;
        #57 rst_n <= 1;
        iDataValid <= 1;
        iData <= 384;
        #10
        iDataValid <= 0;
        iData <= 0;

        #100
        iDataValid <= 1;
        iData <= 736;
        #10
        iDataValid <= 0;
        iData <= 0;

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

    exp_taylor_pp U_exp_taylor_pp(
        .clk(clk),
        .rst_n(rst_n),
        .iData(iData),
        .iDataValid(iDataValid),
        .oData(oData),
        .oDataValid(oDataValid)
        );

endmodule