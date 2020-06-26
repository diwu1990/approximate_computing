`include "param_def.sv"

module shifter_12 (
    input logic [`DATAWIDTH-1 : 0]iData,
    input logic offset,
    output logic [`DATAWIDTH-1 : 0]oData
);
    // offset is 0, shift right by 1 bit
    // offset is 1, shift right by 2 bits
    assign oData = offset ? {2'b0, iData[`DATAWIDTH-1:2]} : {1'b0, iData[`DATAWIDTH-1:1]};

endmodule