#include"fft.h"

complex x[N * 2], *W;      //  输出序列的值,序列长度 全局变量 N是采样点数

int main()
{
	clock_t start = clock();
	double duration;
	int i, j = 0, t = 0;
	double data[N * 2] = { 0 };
	double result[N * 2] = { 0 };
	float  tx = 0;
	//data为从波形上采集输入数据离散点 FS是采样频率 N是采样点数
	for (t = 0; t < N; t++)
		data[t] = 0.5*sin(2 * PI * 15 * t/FS) + 2 * sin(2 * PI * 40 * t/FS);
	//求出N个采样点的值放在x中 下一步进行傅里叶变换
	for (i = 0; i<N; i++)            
	{
		x[i].real = data[i];
		x[i].img  = 0;
	}
	initW(N);
	//基2的快速傅里叶变换，结果保存在x结构体中
	fftx();  
	//计算花费时间
	cout << "所用的时间： ";
	clock_t end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	cout << duration << "ms";
	cout << endl;
	//显示结果
	//save();
	cout << "输出信号的模：";
	cout << endl;
	for (i = 0; i < N; i++)
	{
		result[i] = sqrt(x[i].real*x[i].real + x[i].img*x[i].img); 
		printf("%0.4f\t", result[i]);
	}

	return 0;
}

