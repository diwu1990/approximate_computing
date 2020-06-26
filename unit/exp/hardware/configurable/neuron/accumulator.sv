`include "param_def.sv"

module accumulator (
    input logic [`DATAWIDTH+1 : 0] A, // A is larger than B, {2-bit, {FRACWIDTH-2)-bit}
    input logic [`DATAWIDTH+1 : 0] B, // to be added/subed, {2-bit, {FRACWIDTH-2)-bit}, but 2-bit integer is always 0
    input logic S, // substract indication
    output logic [`DATAWIDTH+1 : 0] O // output, {2-bit, {FRACWIDTH-2)-bit}, no overflow will happen
);
    
    assign O = S ? (A - B) : (A + B);

endmodule