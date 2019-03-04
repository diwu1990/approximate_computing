close all
x = [0:0.005:1];
threshold = 0.875;
% x = x - (1-0.875);
real = exp(x);
frac = 8;


% wcre = 0.0241;
% wcre_valid = wcre;

% rate1 = abs((1 + x + x.^2/2*(1+wcre_valid) + x.^3/8*(1+wcre_valid)^2) ./ real - 1);
% rate2 = abs((1 + x + x.^2/2*(1+wcre_valid) + x.^3/8*(1-wcre_valid)^2) ./ real - 1);
% rate3 = abs((1 + x + x.^2/2*(1-wcre_valid) + x.^3/8*(1+wcre_valid)^2) ./ real - 1);
% rate4 = abs((1 + x + x.^2/2*(1-wcre_valid) + x.^3/8*(1-wcre_valid)^2) ./ real - 1);
% rate5 = abs((1 + x + x.^2/2*(1+wcre_valid) + x.^3/8*(1+wcre_valid)^2) ./ real - 1);
% rate6 = abs((1 + x + x.^2/2*(1+wcre_valid) + x.^3/8*(1-wcre_valid)^2) ./ real - 1);
% rate7 = abs((1 + x + x.^2/2*(1-wcre_valid) + x.^3/8*(1+wcre_valid)^2) ./ real - 1);
% rate8 = abs((1 + x + x.^2/2*(1-wcre_valid) + x.^3/8*(1-wcre_valid)^2) ./ real - 1);

% rate1 = abs((1 + x + x.^2/2*(1+wcre_valid) + x.^3/4*(1+wcre_valid)^2 - x.^4/8*(1+wcre_valid)^3) ./ real - 1);
% rate2 = abs((1 + x + x.^2/2*(1+wcre_valid) + x.^3/4*(1-wcre_valid)^2 - x.^4/8*(1+wcre_valid)^3) ./ real - 1);
% rate3 = abs((1 + x + x.^2/2*(1-wcre_valid) + x.^3/4*(1+wcre_valid)^2 - x.^4/8*(1+wcre_valid)^3) ./ real - 1);
% rate4 = abs((1 + x + x.^2/2*(1-wcre_valid) + x.^3/4*(1-wcre_valid)^2 - x.^4/8*(1+wcre_valid)^3) ./ real - 1);
% rate5 = abs((1 + x + x.^2/2*(1+wcre_valid) + x.^3/4*(1+wcre_valid)^2 - x.^4/8*(1-wcre_valid)^3) ./ real - 1);
% rate6 = abs((1 + x + x.^2/2*(1+wcre_valid) + x.^3/4*(1-wcre_valid)^2 - x.^4/8*(1-wcre_valid)^3) ./ real - 1);
% rate7 = abs((1 + x + x.^2/2*(1-wcre_valid) + x.^3/4*(1+wcre_valid)^2 - x.^4/8*(1-wcre_valid)^3) ./ real - 1);
% rate8 = abs((1 + x + x.^2/2*(1-wcre_valid) + x.^3/4*(1-wcre_valid)^2 - x.^4/8*(1-wcre_valid)^3) ./ real - 1);

% figure
% plot(x,rate1)
% hold on
% plot(x,rate2)
% hold on
% plot(x,rate3)
% hold on
% plot(x,rate4)
% hold on
% plot(x,rate5)
% hold on
% plot(x,rate6)
% hold on
% plot(x,rate7)
% hold on
% plot(x,rate8)

mre = 0.22;
up_rate = abs((1 + x + x.^2/2*(1+mre) + x.^3/4*(1+mre)^2 - x.^4/8*(1-mre)^3) ./ real - 1);
figure
plot(x,up_rate)
mean(up_rate)

down_rate = abs((1 + x + x.^2/2*(1-mre) + x.^3/4*(1-mre)^2 - x.^4/8*(1+mre)^3) ./ real - 1);
figure
plot(x,down_rate)
mean(down_rate)

(mean(up_rate) + mean(down_rate)) / 2