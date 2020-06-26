// input is always fixed to 8-bit
// output is always fixed to 16-bit

// module mul_precise (
module multiplier (
    input logic [7:0] A,
    input logic [7:0] B,
    output logic [15:0] O
);
    // always_ff @(posedge clk or negedge rst_n) begin : proc_O
    //     if(~rst_n) begin
    //         O <= 0;
    //     end else begin
    //         O <= A * B;
    //     end
    // end
    assign O = A * B;

endmodule