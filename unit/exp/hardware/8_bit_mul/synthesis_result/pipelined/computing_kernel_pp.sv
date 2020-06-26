`include "multiplier.sv"
module computing_kernel_pp (
    input clk,    // Clock
    input rst_n,  // Asynchronous reset active low
    input [7:0] iData, // input is {faction}, 8-bit are all fraction, always positive. this value is |t| (t=x when x <0.75; t=x-1 when x > 0.75)
    input iSign, // 0 indicate a positive iData
    output [9:0] oData // output is {2, 8}, 2-bit integer and 8-bit fraction
);
    // 0~4 refer to level 0~4;
    // sum from all levels are {2, 8}
    logic [9:0] sum_0;
    logic [9:0] sum_1;
    logic [9:0] sum_2;
    logic [9:0] sum_3;
    logic [9:0] sum_4;
    // prod from all levels are {0, 8}
    logic [7:0] prod_0;
    logic [7:0] prod_1;
    logic [7:0] prod_2;
    logic [7:0] prod_3;
    // data from all levels are {0, 8}
    logic [7:0] data [1:0];
    // sign from all levels are 1-bit
    logic [1:0] sign;
    // multiplication result
    logic [15:0] mul0Out;
    logic [15:0] mul1Out;
    logic [15:0] mul2Out;
    logic [15:0] mul3Out;

    // pipeline
    // input data and sign are directly pipeline
    always_ff @(posedge clk or negedge rst_n) begin : proc_data_sign
        if(~rst_n) begin
            data[0] <= 0;
            data[1] <= 0;
            sign[0] <= 0;
            sign[1] <= 0;
        end else begin
            data[0] <= iData;
            data[1] <= data[0];
            sign[0] <= iSign;
            sign[1] <= sign[0];
        end
    end

    // sum generation
    always_ff @(posedge clk or negedge rst_n) begin : proc_sum
        if(~rst_n) begin
            sum_0 <= 0;
            sum_1 <= 0;
            sum_2 <= 0;
            sum_3 <= 0;
            sum_4 <= 0;
        end else begin
            sum_0 <= iSign ? (10'd256 - iData) : (10'd256 + iData);
            sum_1 <= sum_0 + prod_0;
            sum_2 <= sign[1] ? (sum_1 - prod_1) : (sum_1 + prod_1);
            sum_3 <= sum_2 + prod_2;
            sum_4 <= sum_3 + prod_3;
        end
    end

    // prod generation
    always_ff @(posedge clk or negedge rst_n) begin : proc_prod
        if(~rst_n) begin
            prod_0 <= 0;
            prod_1 <= 0;
            prod_2 <= 0;
            prod_3 <= 0;
        end else begin
            prod_0 <= mul0Out[15:8];
            prod_1 <= mul1Out[15:8];
            prod_2 <= mul2Out[15:8];
            prod_3 <= {1'b0,prod_2[7:1]};
        end
    end

    multiplier U_multiplier_0(
        .A(iData),
        .B({1'b0,iData[7:1]}),
        .O(mul0Out)
        );

    multiplier U_multiplier_1(
        .A(data[0]),
        .B({2'b0,prod_0[7:2]}),
        .O(mul1Out)
        );

    multiplier U_multiplier_2(
        .A(data[1]),
        .B({1'b0,prod_1[7:1]}),
        .O(mul2Out)
        );

    assign oData = sum_4;

endmodule
