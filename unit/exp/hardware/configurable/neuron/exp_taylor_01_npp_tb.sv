`timescale 1ns/1ns
`include "param_def.sv"

module exp_taylor_01_npp_tb ();

    reg clk;
    reg rst_n;
    reg [`FRACWIDTH-1 : 0] iData;
    reg iDataValid;
    reg oDataRead;

    wire [`FRACWIDTH-1 : 0] oData;
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
        oDataRead <= 0;
        #10
        iDataValid <= 0;
        iData <= 0;

        #100
        iDataValid <= 1;
        iData <= 200;
        #10
        iDataValid <= 0;
        iData <= 0;
        #20
        oDataRead <= 1;
        #100
        $finish;
    end


    exp_taylor_01_npp U_exp_taylor_01_npp(
        .clk(clk),
        .rst_n(rst_n),

        .iData(iData),
        .iDataValid(iDataValid),
        
        .oDataRead(oDataRead),
        .oData(oData),
        .oDataValid(oDataValid)
        );

endmodule