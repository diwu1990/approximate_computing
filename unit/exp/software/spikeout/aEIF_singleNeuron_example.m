%% aEIF single neuron example
%  This script models an adapative-exponential integrate and fire neuron
%  from Brette and Gerstner 2005. J Neurophysiology
%  Specifically, this models the neuron's response to a 500 nA and
%  800nA pulse in Figure 2C of Brette and Gerstner. 
%  The parameters set here are the default values from the bottom of Table
%  1 in Brette and Gerstnet. This code can be used as a template for
%  modeling a single neuron's response within a recurrent circuit.

%% Initialize parameters 
dT = .1; % time step, in milliseconds
t = 0:dT:1000;

% Default parameters from Brette and Gerstner 2005
Cm = 281; % membrane capacitance, picofarads
gL = 30; % leak conductance, nanoSiemens
eLeak = -70.6; % reversal potential of leak channel, millivolts
slopeFac = 2; % slope factor, millivolts
vThresh = -50.4; % threshold potential, millivolts
b = 80.5; % spike-triggered adaptation, in PICOAmps: change from paper
vPeak = 20; % maximum spike voltage, milliVolts
a = 4; % subthreshold adaptation, nanoSiemens
tW = 144; % adaptation time constant, ms
vReset = eLeak; % reset voltage after a spike, mV
% vReset = vThresh + 3; % reset voltage after a spike, mV

% comment the default parameters and uncomment these to simulate other
% neurons while preserving default values
% Cm = 281; % picofarads
% gL = 30; %nanoSiemens
% eLeak = -60; % millivolts
% slopeFac = 2; % millivolts
% vThresh = -50.4; % millivolts
% b = 80.5; % PICOAmps: change from paper!!
% vPeak = 20; % milliVolts
% a = 80; % nanoSiemens, subthreshold adaptation
% tW = 720; % ms
% vReset = eLeak;

% make the current injection
I = zeros(1, length(t));
stimStart = 10; % approximate from figure 2c
stimEnd = 200; % approximate from figure 2c
stimAmplitude = 500; % picoAmps
stim2Start = 500; 
stim2End = 1000;
stim2Amplitude = 800; % picoAmps
I(t>=stimStart&t<=stimEnd) = stimAmplitude;
I(t>=stim2Start&t<=stim2End) = stim2Amplitude;

%% run the simulation
nSteps = length(t);

V = nan(1,nSteps); % membrane potential, millivolts
w = nan(1,nSteps); % adaptation current, picoAmps

V(1) = eLeak; %mV
w(1) = 0;

for i=1:nSteps-1
    
    % Equation from table 1 of Brette and Gerstner 2005
    % note that capacitance and dT are moved to RHS
    V(i+1) = V(i) + (-gL*(V(i)-eLeak)+gL*slopeFac*exp((V(i)-vThresh)/slopeFac)-w(i)+I(i))/Cm*dT;
    % Second equation from table 1 (equation 3 from text)
    % Note that membrane time constant and dT are moved to RHS
    w(i+1) = w(i) + (a*(V(i)-eLeak)-w(i))/tW*dT;
    
    % handle spikes
    % if just spiked
    if V(i)>=vPeak
        % reset voltage
        V(i+1) = vReset;
        % increment adaptation current by b
%         w(i+1) = w(i+1)+b;
        w = w + b;
    end
    % if going to spike this time step, clip
    if V(i+1)>=vPeak
        V(i+1) = vPeak;
    end

end
%% plot figure 2C from text
figure('units', 'pix', 'outerposition', [0 50 1000 1000]);

subplot(4,1,1:3);
vPlot = plot(t,V);
xlim([t(1) t(end)]);
ylim([-80 -20])
set(gca, 'YTick', -80:20:-20);
set(gca, 'fontsize', 16);
set(gca, 'XTick', []);
ylabel('Membrane potential (mV)', 'fontweight', 'bold');

subplot(4,1,4);
stimPlot = plot(t,I./1000); % dividing here converts back to nanoAmps
xlim([t(1) t(end)]);
ylim([0 1]);
set(gca, 'fontsize', 16);
set(gca, 'TickLength', [0 0]);
set(gca, 'XTick', 0:500:1000);
ylabel('Current (nA)', 'fontweight', 'bold');
xlabel('Time (ms)');