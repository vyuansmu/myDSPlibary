close
clear
clc
%% Special Peak

%load data
signal = load("Signal.csv");    % 1801 smaples 
ExpectedMean = load("ExpectedMean.csv"); % 0.6833

% the instructions never banned the use of the built in
% function detrend in matlab and the problem stated that the bias was
% linearly accumulating at some unknown accumulation rate so all I needed
% to do was use detrend which looks for linear trends by default and then
% removes the bias

signal = detrend(signal); % bias removed



%Sampling rate of 10hz 
fs = 10;    % 1801 smaples taken a 10hz sampling rate tells me that the 
            % signal length is about 180.1 seconds
            
% Just to take a quick look at the signal im working with i did a quick
% dirty plot using:
% plot(signal)
% There is alot of high frequency peaks in the middle however the system
% doesn't have that much noise which means the peak finding function can be
% rather simplistic without having to worry about every small nudge being
% considered a peak




% normally I would simply use findpeaks function but since the constraints
% clearly says I can not I just googled some simple examples of how
% findpeak function was derived. The easist example to implement was found
% here: https://terpconnect.umd.edu/~toh/spectrum/allpeaks.m 
% it is in the public domain and how it works is examines each point in the
% signal and looks one sample ahead and behind and if both the amplitudes 
% are lower then the point being examined then that point is conisidered a
% peak. It is probably not the most efficient method but it is the easist
% to implement

index = zeros(size(signal));
for t = 2:length(signal)-1 % starts at the second point and ends 1 point early
    if (signal(t) > signal(t-1))
        if(signal(t) > signal(t+1))
            % if both conditions are met a peak is found
            index(t) = t;
        end
    end  
end

tPeaks = nonzeros(index); % the rest of the signal has no more use to me
% at this point only the sample position of the peaks matter to me
A = signal(tPeaks); % amplitudes


% I wanted to do some preliminary sorting arranging the peaks in order from
% the greatest to least amplitude. I wanted to do this since the the first
% step in the methodology is to find the largest undesignated peak, I
% thought it would be simpler if I just ordered it then indexed from
% largest to smallest.
[Asort, order] = sort(A, 'descend');
tpSort = tPeaks(order);

% I wanted a validation check list each time a peak is examined 
validation = NaN*ones(size(tpSort)); % Three states possible for validation
% state NaN = undecided peak
% state 0 = not a  valid peak
% state 1 = a valid peak

for n = 1:length(tpSort)
    if(isnan(validation(n))) 
        % if undecided assign as Valid since this array is sorted from max
          validation(n) = 1;
          
          % now hunt down peaks that are not valid within the 50 sample
          % range
          upperbound = tpSort(n) + 50;
          lowerbound = tpSort(n) - 50;
          testzone = [lowerbound:tpSort(n)-1 tpSort(n)+1:upperbound];
          [C,ia,~] = intersect(tpSort,testzone);
          % C holds the time index of any peaks found within 50 samples of
          %  the valid peak
          
          % ia holds the index which will be useful to pull out their
          % amplitudes
          Atest = Asort(ia); 
          invalid = find(Atest>A(n)/2); %once invalid peaks are found they
          validation(ia(invalid)) = 0; % are removed by setting to 0
          % It might be better to make validation a boolean
    end
end


specialPeak = find(validation,1,'last'); 
% the last nonzero entry will be the peak with the lowest amplitude but
% also valid

time_of_special_peak = tpSort(specialPeak)
% 971 = 97.1 seconds into the signal
amplitude_of_special_peak = Asort(specialPeak)
% -0.4225




