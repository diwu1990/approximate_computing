// input is always fixed to 8-bit
// output is always fixed to 16-bit

// module mul_precise (
module multiplier (
    input logic [7:0] A,
    input logic [7:0] B,
    output logic [15:0] O
);
    assign O = A*B;

endmodule