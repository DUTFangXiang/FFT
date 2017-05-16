# FFT
FFT精确与快速的C++实现，与Matlab的FFT函数有对比

### C++实现
工程基于Visual Studio 2013建立，编译环境是Win32

基2的快速傅里叶变换，程序输入是一个波形函数，可在程序中自行修改

目前经过与Matlab比较，程序精度与其几乎一样，但是效率提高很多。

### Matlab实现
程序是直接调用Matlab自带函数fft实现

### 两者结果比较：
实现输入波形：x=0.5\*sin(2\*pi\*15\*t)+2*sin(2\*pi\*40\*t)

显示结果是波形每个采样点对应变换后的模

C++实现结果：

![C++实现结果](https://github.com/DUTFangXiang/FFT/blob/master/C%2B%2B-finalResult.jpg) 

Matlab实现结果：

![Matlab实现结果](https://github.com/DUTFangXiang/FFT/blob/master/matlab-finalResult.jpg) 
