module neuron (
    input logic clk,    // Clock
    input logic rst_n,  // Asynchronous reset active low
    input logic [36:0] in,
    output logic [36:0] wn,
    output logic [36:0] vn,
);
    logic [36:0] vn_buf;
    logic [36:0] wn_buf;

    logic [36:0] vn_vt;
    logic [36:0] vn_el;
    logic [36:0] vn_el_a;
    logic [36:0] vn_el_a_wn;
    logic [36:0] vn_el_a_wn_dt_tw;
    logic [36:0] vn_el_a_wn_dt_tw_vn_buf;
    logic [36:0] vn_el_a_wn_dt_tw_vn_buf_b;
    logic [36:0] vn_el_gl;
    logic [36:0] exp;
    logic [36:0] exp_gl_dlt;
    logic [36:0] vn_el_gl_exp_gl_dlt;
    logic [36:0] I_wn_buf;
    logic [36:0] vn_el_gl_exp_gl_dlt_I_wn_buf;
    logic [36:0] vn_el_gl_exp_gl_dlt_I_wn_buf_dt_c;
    logic [36:0] vn_el_gl_exp_gl_dlt_I_wn_buf_dt_c_vn_buf;
    logic update;
    logic [31:0] exp_in;

    assign update = vn_el_gl_exp_gl_dlt_I_wn_buf_dt_c_vn_buf > 0;


    // el is -58, subtraction become addition
    assign vn_el = vn_buf + {14'd58,23'b0};
    assign vn_el_a = {vn_el_a[36:1],1'b0};
    always_ff @(posedge clk or negedge rst_n) begin : proc_vn_el_a_wn
        if(~rst_n) begin
            vn_el_a_wn <= 0;
        end else begin
            vn_el_a_wn <= vn_el_a - wn_buf;
        end
    end

    // 1/128*1/120
    // 7 bit shift, 7 bit shift + 11b + 15b
    always_ff @(posedge clk or negedge rst_n) begin : proc_vn_el_a_wn_dt_tw
        if(~rst_n) begin
            vn_el_a_wn_dt_tw <= 0;
        end else begin
            vn_el_a_wn_dt_tw <= {14'b0,vn_el_a_wn[36:14]} + {18'b0,vn_el_a_wn[36:18]} + {22'b0,vn_el_a_wn[36:22]};
        end
    end


    assign vn_el_a_wn_dt_tw_vn_buf = vn_el_a_wn_dt_tw + vn_buf;
    assign vn_el_a_wn_dt_tw_vn_buf_b = vn_el_a_wn_dt_tw_vn_buf + {14'b100,23'b0};

    always_ff @(posedge clk or negedge rst_n) begin : proc_wn
        if(~rst_n) begin
            wn <= 0;
        end else begin
            wn <= update ? vn_el_a_wn_dt_tw_vn_buf_b : vn_el_a_wn_dt_tw_vn_buf;
        end
    end

    assign I_wn_buf = in  + wn_buf;


    // exp out
    assign exp_in = vn_buf + {14'd50, 12'b0};
    exp_taylor_npp U_exp(
        .clk(clk),    // Clock
        .rst_n(rst_n),  // Asynchronous reset active low
        
        .iData(exp_in), // input is {14,23} signed
        .exp1(), // 
        .iDataValid(), // 

        .oDataRead(), // prepare to stop, need one more cycle after end comes, due to computing the product
        .oData(), // output is {integer, fraction}, 16-bit integer and 4-bit fraction
        .oDataValid // output valid
        );



endmodule