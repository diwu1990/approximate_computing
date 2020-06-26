module LUT (
    input logic [5:0] intPart,
    output logic [31:0] expInt // 14 bit integer, 18 bit fraction
);
    // input exp int is -5 to 25
    // thus in total 6 bits
    always_comb begin : proc_
        case (intPart)
            -5: expInt <= 32'd1766; // 0.006738 << 18-bit
            -4: expInt <= 32'd4801; // 0.018316 << 18-bit
            -3: expInt <= 32'd13051; // 0.049787 << 18-bit
            -2: expInt <= 32'd35477; // 0.135335 << 18-bit
            -1: expInt <= 32'd96437; // 0.367879 << 18-bit
            0: expInt <= 32'd262144; // 1.000000 << 18-bit
            1: expInt <= 32'd712581; // 2.718282 << 18-bit
            2: expInt <= 32'd1936997; // 7.389056 << 18-bit
            3: expInt <= 32'd5265303; // 20.085537 << 18-bit
            4: expInt <= 32'd14312577; // 54.598150 << 18-bit
            5: expInt <= 32'd38905619; // 148.413159 << 18-bit
            6: expInt <= 32'd105756438; // 403.428793 << 18-bit
            7: expInt <= 32'd287475803; // 1096.633158 << 18-bit
            8: expInt <= 32'd781440251; // 2980.957987 << 18-bit
            9: expInt <= 32'd2124174833; // 8103.083928 << 18-bit
            default : expInt <= 32'hFFFFFFFF;
        endcase
    end

endmodule