#include"fft.h"

complex x[N * 2], *W;      //  ������е�ֵ,���г��� ȫ�ֱ��� N�ǲ�������

int main()
{
	clock_t start = clock();
	double duration;
	int i, j = 0, t = 0;
	double data[N * 2] = { 0 };
	double result[N * 2] = { 0 };
	float  tx = 0;
	//dataΪ�Ӳ����ϲɼ�����������ɢ�� FS�ǲ���Ƶ�� N�ǲ�������
	for (t = 0; t < N; t++)
		data[t] = 0.5*sin(2 * PI * 15 * t/FS) + 2 * sin(2 * PI * 40 * t/FS);
	//���N���������ֵ����x�� ��һ�����и���Ҷ�任
	for (i = 0; i<N; i++)            
	{
		x[i].real = data[i];
		x[i].img  = 0;
	}
	initW(N);
	//��2�Ŀ��ٸ���Ҷ�任�����������x�ṹ����
	fftx();  
	//���㻨��ʱ��
	cout << "���õ�ʱ�䣺 ";
	clock_t end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	cout << duration << "ms";
	cout << endl;
	//��ʾ���
	//save();
	cout << "����źŵ�ģ��";
	cout << endl;
	for (i = 0; i < N; i++)
	{
		result[i] = sqrt(x[i].real*x[i].real + x[i].img*x[i].img); 
		printf("%0.4f\t", result[i]);
	}

	return 0;
}

