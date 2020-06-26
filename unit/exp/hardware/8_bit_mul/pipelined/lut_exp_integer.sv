module lut_exp_integer (
    input logic [4:0] iData, // {integer}, {5}
    output logic [15:0] oData // {integer, fraction}, {12, 4}
);
    always_comb begin : proc_oData
        case (iData)
            -5'd2: oData <= 3;
            -5'd1: oData <= 6;
            5'd0: oData <= 16;
            5'd1: oData <= 44;
            5'd2: oData <= 119;
            5'd3: oData <= 322;
            5'd4: oData <= 874;
            5'd5: oData <= 2375;
            5'd6: oData <= 6455;
            5'd7: oData <= 17547;
            5'd8: oData <= 32767;
            default : oData <= 1;
        endcase
    end

endmodule