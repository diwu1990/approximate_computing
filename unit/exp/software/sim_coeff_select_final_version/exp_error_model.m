clear
% 8 bit, uniform
% coeff = {1,   1,   0.5, 0.25,    -0.125,  0.0625,  0.03125};
% order = {0,   1,     2,    3,         4,       4,        4};

% iWMRE_8 = 0
% iWMRE_8 = 0.00052
% iWMRE_8 = 0.0018
% iWMRE_8 = 0.0051
% iWMRE_8 = 0.019
% iWMRE_8 = 0.0473
% iWMRE_8 = 0.1214
% iWMRE_8 = 0.2842
% iWMRE_8 = 0.5781
% iWMRE_8 = 1

% iFracWidth_8 = 8;
% iThreshold_8 = 0.875;
% cnt_8 = 2^8;
% in_8 = (0:(1/cnt_8):(1-1/cnt_8)) - (1-iThreshold_8);
% final_cycle_pos_8 = ones(1,cnt_8);
% final_cycle_neg_8 = ones(1,cnt_8);
% for i=1:cnt_8
%     if in_8(i)<0
%         final_cycle_pos_8(i) = 1+iWMRE_8;
%         final_cycle_neg_8(i) = 1-iWMRE_8;
%     else
%         final_cycle_pos_8(i) = 1;
%         final_cycle_neg_8(i) = 1;
%     end
% end
% 
% appr_pos_8 = (1 + in_8 ...
%     + round(in_8.^2*(2^iFracWidth_8))/(2^iFracWidth_8)*0.5*(1+iWMRE_8) ...
%     + round(in_8.^3*(2^iFracWidth_8))/(2^iFracWidth_8)*0.25*(1+iWMRE_8)^2 ...
%     + round(in_8.^4*(2^iFracWidth_8))/(2^iFracWidth_8)*(-0.125*(1-iWMRE_8)^3 + 0.0625 + 0.03125)).*final_cycle_pos_8;
% appr_neg_8 = (1 + in_8 ...
%     + round(in_8.^2*(2^iFracWidth_8))/(2^iFracWidth_8)*0.5*(1-iWMRE_8) ...
%     + round(in_8.^3*(2^iFracWidth_8))/(2^iFracWidth_8)*0.25*(1-iWMRE_8)^2 ...
%     + round(in_8.^4*(2^iFracWidth_8))/(2^iFracWidth_8)*(-0.125*(1+iWMRE_8)^3 + 0.0625 + 0.03125)).*final_cycle_neg_8;
% err_pos_8 = abs(appr_pos_8./exp(in_8) - 1);
% err_neg_8 = abs(appr_neg_8./exp(in_8) - 1);
% oWMRE_mean_8 = (mean(err_pos_8) + mean(err_neg_8)) / 2
% oWMRE_max_8 = max(mean(err_pos_8), mean(err_neg_8))


% 12 bit, uniform
% coeff = {1,  1,   0.5, 0.125,   -0.0625, -0.03125,    -0.015625,   -0.007812};
% order = {0,  1,     2,     3,         4,        5,            5,           5};

% iWMRE_12 = 0
% iWMRE_12 = 0.0000062
% iWMRE_12 = 0.00005
% iWMRE_12 = 0.00026
% iWMRE_12 = 0.0012
% iWMRE_12 = 0.0046
% iWMRE_12 = 0.0189
% iWMRE_12 = 0.0784
% iWMRE_12 = 0.2671
iWMRE_12 = 0.8798

iFracWidth_12 = 12;
iThreshold_12 = 0.25;
cnt_12 = 2^12;
in_12 = (0:(1/cnt_12):(1-1/cnt_12)) - (1-iThreshold_12);
final_cycle_pos_12 = ones(1,cnt_12);
final_cycle_neg_12 = ones(1,cnt_12);
for i=1:cnt_12
    if in_12(i)<0
        final_cycle_pos_12(i) = 1+iWMRE_12;
        final_cycle_neg_12(i) = 1-iWMRE_12;
    else
        final_cycle_pos_12(i) = 1;
        final_cycle_neg_12(i) = 1;
    end
end

appr_pos_12 = (1 + in_12 ...
    + round(in_12.^2*(2^iFracWidth_12))/(2^iFracWidth_12)*0.5*(1+iWMRE_12) ...
    + round(in_12.^3*(2^iFracWidth_12))/(2^iFracWidth_12)*0.125*(1+iWMRE_12)^2 ...
    + round(in_12.^4*(2^iFracWidth_12))/(2^iFracWidth_12)*(-0.0625)*(1-iWMRE_12)^3 ...
    + round(in_12.^5*(2^iFracWidth_12))/(2^iFracWidth_12)*(-0.03125*(1-iWMRE_12)^4 - 0.015625 - 0.007812)).*final_cycle_pos_12;
appr_neg_12 = (1 + in_12 ...
    + round(in_12.^2*(2^iFracWidth_12))/(2^iFracWidth_12)*0.5*(1-iWMRE_12) ...
    + round(in_12.^3*(2^iFracWidth_12))/(2^iFracWidth_12)*0.125*(1-iWMRE_12)^2 ...
    + round(in_12.^4*(2^iFracWidth_12))/(2^iFracWidth_12)*(-0.0625)*(1+iWMRE_12)^3 ...
    + round(in_12.^5*(2^iFracWidth_12))/(2^iFracWidth_12)*(-0.03125*(1+iWMRE_12)^4 - 0.015625 - 0.007812)).*final_cycle_neg_12;
err_pos_12 = abs(appr_pos_12./exp(in_12) - 1);
err_neg_12 = abs(appr_neg_12./exp(in_12) - 1);
oWMRE_mean_12 = (mean(err_pos_12) + mean(err_neg_12)) / 2
oWMRE_max_12 = max(mean(err_pos_12), mean(err_neg_12))


% 16 bit, uniform
% coeff = {1, 1,  0.5,    0.125,  0.0625, 0.03125,    0.015625};
% order = {0, 1,    2,        3,       4,       4,           4};

% iWMRE_16 = 0
% iWMRE_16 = 0.000000044
% iWMRE_16 = 0.00000071
% iWMRE_16 = 0.000005
% iWMRE_16 = 0.000067
% iWMRE_16 = 0.00047
% iWMRE_16 = 0.0046
% iWMRE_16 = 0.0207
% iWMRE_16 = 0.159
% iWMRE_16 = 0.8799

% iFracWidth_16 = 16;
% iThreshold_16 = 0.75;
% cnt_16 = 2^16;
% in_16 = (0:(1/cnt_16):1) - (1-iThreshold_16);
% final_cycle_16 = ones(1,cnt_16+1);
% for i=1:cnt_16+1
%     if in_16(i)<0
%         final_cycle_16(i) = 1+iWMRE_16;
%     else
%         final_cycle_16(i) = 1;
%     end
% end
% 
% appr_pos_16 = (1 + in_16 ...
%     + round(in_16.^2*(2^iFracWidth_16))/(2^iFracWidth_16)*0.5*(1+iWMRE_16) ...
%     + round(in_16.^3*(2^iFracWidth_16))/(2^iFracWidth_16)*0.125*(1+iWMRE_16)^2 ...
%     + round(in_16.^4*(2^iFracWidth_16))/(2^iFracWidth_16)*(0.0625*(1+iWMRE_16)^3 + 0.03125 + 0.015625)).*final_cycle_16;
% appr_neg_16 = (1 + in_16 ...
%     + round(in_16.^2*(2^iFracWidth_16))/(2^iFracWidth_16)*0.5*(1-iWMRE_16) ...
%     + round(in_16.^3*(2^iFracWidth_16))/(2^iFracWidth_16)*0.125*(1-iWMRE_16)^2 ...
%     + round(in_16.^4*(2^iFracWidth_16))/(2^iFracWidth_16)*(0.0625*(1-iWMRE_16)^3 + 0.03125 + 0.015625)).*final_cycle_16;
% err_pos_16 = abs(appr_pos_16./exp(in_16) - 1);
% err_neg_16 = abs(appr_neg_16./exp(in_16) - 1);
% oWMRE_mean_16 = (mean(err_pos_16) + mean(err_neg_16)) / 2
% oWMRE_max_16 = max(mean(err_pos_16), mean(err_neg_16))

