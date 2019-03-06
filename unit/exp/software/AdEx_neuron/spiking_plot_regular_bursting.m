close all
clear
% float
neuron_spiking_out_regular_bursting_float = importdata('neuron_spiking_out_regular_bursting_float.txt');
figure
plot(neuron_spiking_out_regular_bursting_float(:,1),neuron_spiking_out_regular_bursting_float(:,2));
v_regular_bursting_float = find(neuron_spiking_out_regular_bursting_float(:,4));

max_regular_bursting = max(neuron_spiking_out_regular_bursting_float(:,2));
min_regular_bursting = min(neuron_spiking_out_regular_bursting_float(:,2));
[m,n] = size(neuron_spiking_out_regular_bursting_float(:,2));

% fixed exp
neuron_spiking_out_regular_bursting_fixed_exp = importdata('neuron_spiking_out_regular_bursting_fixed_exp.txt');
figure
plot(neuron_spiking_out_regular_bursting_fixed_exp(:,1),neuron_spiking_out_regular_bursting_fixed_exp(:,2));
v_regular_bursting_fixed_exp = find(neuron_spiking_out_regular_bursting_fixed_exp(:,4));

nrmsd_regular_bursting_fixed_exp = 0;
for i=2:length(v_regular_bursting_float)-1
    pos_range_regular_bursting_fixed_exp = round((v_regular_bursting_float(i+1)-v_regular_bursting_float(i))/2);
    neg_range_regular_bursting_fixed_exp = round((v_regular_bursting_float(i)-v_regular_bursting_float(i-1))/2);
    diff_regular_bursting_fixed_exp = neuron_spiking_out_regular_bursting_fixed_exp(v_regular_bursting_fixed_exp(i)-neg_range_regular_bursting_fixed_exp:v_regular_bursting_fixed_exp(i)+pos_range_regular_bursting_fixed_exp,2)-neuron_spiking_out_regular_bursting_float(v_regular_bursting_float(i)-neg_range_regular_bursting_fixed_exp:v_regular_bursting_float(i)+pos_range_regular_bursting_fixed_exp,2);
    square_diff_regular_bursting_fixed_exp = diff_regular_bursting_fixed_exp.^2;
    sum_square_diff_regular_bursting_fixed_exp = sum(square_diff_regular_bursting_fixed_exp);
    sqrt_sum_square_diff_regular_bursting_fixed_exp = sqrt(sum_square_diff_regular_bursting_fixed_exp/(pos_range_regular_bursting_fixed_exp+neg_range_regular_bursting_fixed_exp+1));
    nrmsd_regular_bursting_fixed_exp = nrmsd_regular_bursting_fixed_exp + sqrt_sum_square_diff_regular_bursting_fixed_exp/(max_regular_bursting-min_regular_bursting);
end
nrmsd_regular_bursting_fixed_exp = nrmsd_regular_bursting_fixed_exp/(length(v_regular_bursting_float)-2)

terr_regular_bursting_fixed_exp = 0;
for i=1:length(v_regular_bursting_float)-1
    terr_regular_bursting_fixed_exp = terr_regular_bursting_fixed_exp + abs(((v_regular_bursting_float(i+1)-v_regular_bursting_float(i)) - (v_regular_bursting_fixed_exp(i+1)-v_regular_bursting_fixed_exp(i)))/(v_regular_bursting_float(i+1)-v_regular_bursting_float(i)));
end
terr_regular_bursting_fixed_exp = terr_regular_bursting_fixed_exp/(length(v_regular_bursting_float)-1)


% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% // Circuit = mul32x32_061
% // Area   (45) = 1150
% // Delay  (45) = 1.750
% // Power  (45) = 0.69
% // MAE = 10647482012080490.0
% // MRE = 19.69 %
% // WCE LIMIT = 922337203685477580800
% // WCE LIMIT % = 0.5 %
% // EP = 100.0 %
neuron_spiking_out_regular_bursting_appr_mul_061 = importdata('neuron_spiking_out_regular_bursting_appr_mul_061.txt');
figure
plot(neuron_spiking_out_regular_bursting_appr_mul_061(:,1),neuron_spiking_out_regular_bursting_appr_mul_061(:,2));
v_regular_bursting_appr_mul_061 = find(neuron_spiking_out_regular_bursting_appr_mul_061(:,4));

nrmsd_regular_bursting_appr_mul_061 = 0;
for i=2:length(v_regular_bursting_float)-1
    pos_range_regular_bursting_appr_mul_061 = round((v_regular_bursting_float(i+1)-v_regular_bursting_float(i))/2);
    neg_range_regular_bursting_appr_mul_061 = round((v_regular_bursting_float(i)-v_regular_bursting_float(i-1))/2);
    diff_regular_bursting_appr_mul_061 = neuron_spiking_out_regular_bursting_appr_mul_061(v_regular_bursting_appr_mul_061(i)-neg_range_regular_bursting_appr_mul_061:v_regular_bursting_appr_mul_061(i)+pos_range_regular_bursting_appr_mul_061,2)-neuron_spiking_out_regular_bursting_float(v_regular_bursting_float(i)-neg_range_regular_bursting_appr_mul_061:v_regular_bursting_float(i)+pos_range_regular_bursting_appr_mul_061,2);
    square_diff_regular_bursting_appr_mul_061 = diff_regular_bursting_appr_mul_061.^2;
    sum_square_diff_regular_bursting_appr_mul_061 = sum(square_diff_regular_bursting_appr_mul_061);
    sqrt_sum_square_diff_regular_bursting_appr_mul_061 = sqrt(sum_square_diff_regular_bursting_appr_mul_061/(pos_range_regular_bursting_appr_mul_061+neg_range_regular_bursting_appr_mul_061+1));
    nrmsd_regular_bursting_appr_mul_061 = nrmsd_regular_bursting_appr_mul_061 + sqrt_sum_square_diff_regular_bursting_appr_mul_061/(max_regular_bursting-min_regular_bursting);
end
nrmsd_regular_bursting_appr_mul_061 = nrmsd_regular_bursting_appr_mul_061/(length(v_regular_bursting_float)-2)

terr_regular_bursting_appr_mul_061 = 0;
for i=1:length(v_regular_bursting_float)-1
    terr_regular_bursting_appr_mul_061 = terr_regular_bursting_appr_mul_061 + abs(((v_regular_bursting_float(i+1)-v_regular_bursting_float(i)) - (v_regular_bursting_appr_mul_061(i+1)-v_regular_bursting_appr_mul_061(i)))/(v_regular_bursting_float(i+1)-v_regular_bursting_float(i)));
end
terr_regular_bursting_appr_mul_061 = terr_regular_bursting_appr_mul_061/(length(v_regular_bursting_float)-1)

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% // Circuit = mul32x32_049
% // Area   (45) = 2134
% // Delay  (45) = 2.200
% // Power  (45) = 1.39
% // MAE = 1208466017512107.8
% // MRE = 3.62 %
% // WCE LIMIT = 92233720368547758080
% // WCE LIMIT % = 0.05 %
% // EP = 100.0 %
neuron_spiking_out_regular_bursting_appr_mul_049 = importdata('neuron_spiking_out_regular_bursting_appr_mul_049.txt');
figure
plot(neuron_spiking_out_regular_bursting_appr_mul_049(:,1),neuron_spiking_out_regular_bursting_appr_mul_049(:,2));
v_regular_bursting_appr_mul_049 = find(neuron_spiking_out_regular_bursting_appr_mul_049(:,4));

nrmsd_regular_bursting_appr_mul_049 = 0;
for i=2:length(v_regular_bursting_float)-1
    pos_range_regular_bursting_appr_mul_049 = round((v_regular_bursting_float(i+1)-v_regular_bursting_float(i))/2);
    neg_range_regular_bursting_appr_mul_049 = round((v_regular_bursting_float(i)-v_regular_bursting_float(i-1))/2);
    diff_regular_bursting_appr_mul_049 = neuron_spiking_out_regular_bursting_appr_mul_049(v_regular_bursting_appr_mul_049(i)-neg_range_regular_bursting_appr_mul_049:v_regular_bursting_appr_mul_049(i)+pos_range_regular_bursting_appr_mul_049,2)-neuron_spiking_out_regular_bursting_float(v_regular_bursting_float(i)-neg_range_regular_bursting_appr_mul_049:v_regular_bursting_float(i)+pos_range_regular_bursting_appr_mul_049,2);
    square_diff_regular_bursting_appr_mul_049 = diff_regular_bursting_appr_mul_049.^2;
    sum_square_diff_regular_bursting_appr_mul_049 = sum(square_diff_regular_bursting_appr_mul_049);
    sqrt_sum_square_diff_regular_bursting_appr_mul_049 = sqrt(sum_square_diff_regular_bursting_appr_mul_049/(pos_range_regular_bursting_appr_mul_049+neg_range_regular_bursting_appr_mul_049+1));
    nrmsd_regular_bursting_appr_mul_049 = nrmsd_regular_bursting_appr_mul_049 + sqrt_sum_square_diff_regular_bursting_appr_mul_049/(max_regular_bursting-min_regular_bursting);
end
nrmsd_regular_bursting_appr_mul_049 = nrmsd_regular_bursting_appr_mul_049/(length(v_regular_bursting_float)-2)

terr_regular_bursting_appr_mul_049 = 0;
for i=1:length(v_regular_bursting_float)-1
    terr_regular_bursting_appr_mul_049 = terr_regular_bursting_appr_mul_049 + abs(((v_regular_bursting_float(i+1)-v_regular_bursting_float(i)) - (v_regular_bursting_appr_mul_049(i+1)-v_regular_bursting_appr_mul_049(i)))/(v_regular_bursting_float(i+1)-v_regular_bursting_float(i)));
end
terr_regular_bursting_appr_mul_049 = terr_regular_bursting_appr_mul_049/(length(v_regular_bursting_float)-1)

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% // Library = EvoApprox 16x16
% // Circuit = mul32x32_034
% // Area   (45) = 3129
% // Delay  (45) = 2.630
% // Power  (45) = 2.34
% // MAE = 149059810610824.8
% // MRE = 0.26 %
% // WCE LIMIT = 9223372036854775808
% // WCE LIMIT % = 0.005 %
% // EP = 100.0 %
neuron_spiking_out_regular_bursting_appr_mul_034 = importdata('neuron_spiking_out_regular_bursting_appr_mul_034.txt');
figure
plot(neuron_spiking_out_regular_bursting_appr_mul_034(:,1),neuron_spiking_out_regular_bursting_appr_mul_034(:,2));
v_regular_bursting_appr_mul_034 = find(neuron_spiking_out_regular_bursting_appr_mul_034(:,4));

nrmsd_regular_bursting_appr_mul_034 = 0;
for i=2:length(v_regular_bursting_float)-1
    pos_range_regular_bursting_appr_mul_034 = round((v_regular_bursting_float(i+1)-v_regular_bursting_float(i))/2);
    neg_range_regular_bursting_appr_mul_034 = round((v_regular_bursting_float(i)-v_regular_bursting_float(i-1))/2);
    diff_regular_bursting_appr_mul_034 = neuron_spiking_out_regular_bursting_appr_mul_034(v_regular_bursting_appr_mul_034(i)-neg_range_regular_bursting_appr_mul_034:v_regular_bursting_appr_mul_034(i)+pos_range_regular_bursting_appr_mul_034,2)-neuron_spiking_out_regular_bursting_float(v_regular_bursting_float(i)-neg_range_regular_bursting_appr_mul_034:v_regular_bursting_float(i)+pos_range_regular_bursting_appr_mul_034,2);
    square_diff_regular_bursting_appr_mul_034 = diff_regular_bursting_appr_mul_034.^2;
    sum_square_diff_regular_bursting_appr_mul_034 = sum(square_diff_regular_bursting_appr_mul_034);
    sqrt_sum_square_diff_regular_bursting_appr_mul_034 = sqrt(sum_square_diff_regular_bursting_appr_mul_034/(pos_range_regular_bursting_appr_mul_034+neg_range_regular_bursting_appr_mul_034+1));
    nrmsd_regular_bursting_appr_mul_034 = nrmsd_regular_bursting_appr_mul_034 + sqrt_sum_square_diff_regular_bursting_appr_mul_034/(max_regular_bursting-min_regular_bursting);
end
nrmsd_regular_bursting_appr_mul_034 = nrmsd_regular_bursting_appr_mul_034/(length(v_regular_bursting_float)-2)

terr_regular_bursting_appr_mul_034 = 0;
for i=1:length(v_regular_bursting_float)-1
    terr_regular_bursting_appr_mul_034 = terr_regular_bursting_appr_mul_034 + abs(((v_regular_bursting_float(i+1)-v_regular_bursting_float(i)) - (v_regular_bursting_appr_mul_034(i+1)-v_regular_bursting_appr_mul_034(i)))/(v_regular_bursting_float(i+1)-v_regular_bursting_float(i)));
end
terr_regular_bursting_appr_mul_034 = terr_regular_bursting_appr_mul_034/(length(v_regular_bursting_float)-1)

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
neuron_spiking_out_regular_bursting_precise_mul = importdata('neuron_spiking_out_regular_bursting_precise_mul.txt');
figure
plot(neuron_spiking_out_regular_bursting_precise_mul(:,1),neuron_spiking_out_regular_bursting_precise_mul(:,2));
v_regular_bursting_precise_mul = find(neuron_spiking_out_regular_bursting_precise_mul(:,4));

nrmsd_regular_bursting_precise_mul = 0;
for i=2:length(v_regular_bursting_float)-1
    pos_range_regular_bursting_precise_mul = round((v_regular_bursting_float(i+1)-v_regular_bursting_float(i))/2);
    neg_range_regular_bursting_precise_mul = round((v_regular_bursting_float(i)-v_regular_bursting_float(i-1))/2);
    diff_regular_bursting_precise_mul = neuron_spiking_out_regular_bursting_precise_mul(v_regular_bursting_precise_mul(i)-neg_range_regular_bursting_precise_mul:v_regular_bursting_precise_mul(i)+pos_range_regular_bursting_precise_mul,2)-neuron_spiking_out_regular_bursting_float(v_regular_bursting_float(i)-neg_range_regular_bursting_precise_mul:v_regular_bursting_float(i)+pos_range_regular_bursting_precise_mul,2);
    square_diff_regular_bursting_precise_mul = diff_regular_bursting_precise_mul.^2;
    sum_square_diff_regular_bursting_precise_mul = sum(square_diff_regular_bursting_precise_mul);
    sqrt_sum_square_diff_regular_bursting_precise_mul = sqrt(sum_square_diff_regular_bursting_precise_mul/(pos_range_regular_bursting_precise_mul+neg_range_regular_bursting_precise_mul+1));
    nrmsd_regular_bursting_precise_mul = nrmsd_regular_bursting_precise_mul + sqrt_sum_square_diff_regular_bursting_precise_mul/(max_regular_bursting-min_regular_bursting);
end
nrmsd_regular_bursting_precise_mul = nrmsd_regular_bursting_precise_mul/(length(v_regular_bursting_float)-2)

terr_regular_bursting_precise_mul = 0;
for i=1:length(v_regular_bursting_float)-1
    terr_regular_bursting_precise_mul = terr_regular_bursting_precise_mul + abs(((v_regular_bursting_float(i+1)-v_regular_bursting_float(i)) - (v_regular_bursting_precise_mul(i+1)-v_regular_bursting_precise_mul(i)))/(v_regular_bursting_float(i+1)-v_regular_bursting_float(i)));
end
terr_regular_bursting_precise_mul = terr_regular_bursting_precise_mul/(length(v_regular_bursting_float)-1)
