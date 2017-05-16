
%x=0.5*sin(2*pi*15*t)+2*sin(2*pi*40*t)。采样频率fs=100Hz，分别绘制N=128、1024点幅频图。

clf;
tic
fs=100;N=128;   %采样频率和数据点数
n=0:N-1;t=n/fs; %时间序列
x= 0.5*sin(2*pi*15*t)+2*sin(2*pi*40*t);           
y=fft(x,N);     %对信号进行快速Fourier变换
mag=abs(y);     %求得Fourier变换后的振幅
f=n*fs/N;       %频率序列
subplot(2,2,1),plot(f,mag);   %绘出随频率变化的振幅
xlabel('频率/Hz');
ylabel('振幅');title('N=128');grid on;
subplot(2,2,2),plot(f(1:N/2),mag(1:N/2)); %绘出Nyquist频率之前随频率变化的振幅
xlabel('频率/Hz');
ylabel('振幅');title('N=128');grid on;
%对信号采样数据为1024点的处理
fs=100;N=1024;n=0:N-1;t=n/fs;
x=0.5*sin(2*pi*15*t)+2*sin(2*pi*40*t); %信号
y=fft(x,N);   %对信号进行快速Fourier变换
mag=abs(y);   %求取Fourier变换的振幅
f=n*fs/N;
subplot(2,2,3),plot(f,mag); %绘出随频率变化的振幅
xlabel('频率/Hz');
ylabel('振幅');title('N=1024');grid on;
subplot(2,2,4)
plot(f(1:N/2),mag(1:N/2)); %绘出Nyquist频率之前随频率变化的振幅
xlabel('频率/Hz');
ylabel('振幅');title('N=1024');grid on;