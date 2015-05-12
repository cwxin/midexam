#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int Generate_N(int p);
int Bit_Increase2(int *D, int b, int N);
int Bit_Reverse2(int *D, int b, int N);
int Bit_Reverse_Integer2(int N);
int Initial(double *x, double *y, int N);
int FFT2(double *x_r, double *x_i, double *y_r, double *y_i, int N);
int Print_Complex_Vector(double *y_r, double *y_i, int N);

int main()
{
	int p, N, D[4];
	double *y_r, *y_i, *x_r, *x_i;
	//Bit_Reverse_Integer2(8);
	//Bit_Increase2(D, 2, 4);
	//Bit_Reverse2(D, 2, 4);
	printf("Please input p:");
	scanf("%d", &p);
	N = Generate_N(p);
	printf("2^%d=%d\n", p,N);
	x_r = (double *) malloc(N*sizeof(double));
	x_i = (double *) malloc(N*sizeof(double));
	y_r = (double *) malloc(N*sizeof(double));
	y_i = (double *) malloc(N*sizeof(double));
	Initial(x_r, x_i, N);
	FFT2(x_r, x_i, y_r, y_i, N);
	Print_Complex_Vector(y_r, y_i, N);
	return 0;
}

int Generate_N(int p)
{
	int i, N = 1;
	for (i=0;i<p;++i)
	{
		N = N * 2;
	}
	return N;
}

int Bit_Increase2(int *D, int b, int N)
{
	int i;
	
	for(i=0;i<N;++i) D[i] = 0;
	
	while(D[N-1] < b)
	{
		for(i=N-1;i>=0;i--)
			printf("%d", D[i]); 
		{
			printf("\n");
			D[0] = D[0] + 1;
			i = 0;
			while(D[i]==b & i < N-1)
			{
				D[i] = 0;
				i = i + 1;
				D[i] = D[i] + 1;
			}
			system("pause");
		} 
	}
	return 0;
}

int Bit_Reverse2(int *D, int b, int N)
{
	int i;
	for(i=0;i<N;++i) D[i] = 0;
	
	while(D[0] < b)
	{
		for(i=N-1;i>=0;i--) printf("%d", D[i]);
		printf("\n");
		i = N-1;
		while(D[i]==b-1 & i > 0)
		{
			D[i] = 0;
			i = i - 1;
		}
		D[i] = D[i] + 1;
		system("pause");
	}
	return 0;
}

int Bit_Reverse_Integer2(int N)
{
	int i, j , M;
	i = 0;
	j = 0;
	
	while(i<N)
	{
		printf("%d <-> %d", i,j);
		M = N / 2;
		while(j >= M & M > 0)
		{
			j = j - M;
			M = M / 2;
		}
			j = j + M;
			i = i + 1;
			system("pause");		
	} 
	return 0;		
}

int Initial(double *x, double *y, int N)
{
	int n;
	for(n=0;n<N;++n)
	{
		x[n] = n;
		y[n] = 0.0;
	}
}

int Print_Complex_Vector(double *y_r, double *y_i, int N)
{
	int n;
	for(n=0;n<N;++n)
	{
		if (y_i[n] >=0) printf("%d : %f +%f i\n", n, y_r[n], y_i[n]);
		else printf("%d : %f %f i\n", n, y_r[n], y_i[n]);
	}
	return 0;
}

int FFT2(double *x_r, double *x_i, double *y_r, double *y_i, int N)
{
	int i, j, n, M, k, p, q;
	double t_r, t_i;
	i = 0;
	j = 0;
	for(n=0;n<N;++n)
	{
		y_r[n] = x_r[n];
		y_i[n] = x_i[n];
	}
	while(i<N)
	{
		if(i<j)
		{
			t_r = y_r[i];
			t_i = y_i[i];
			y_r[i] = y_r[j];
			y_i[i] = y_i[j];
			y_r[j] = t_r;
			y_i[j] = t_i; 
		}
		M = N / 2;
		while(j >= M & M > 0)
		{
			j = j - M;
			M = M / 2;
		}
			j = j + M;
			i = i + 1;
	}
	double theta, w_r, w_i;
	n = 2;
	while(n <= N)
	{
		for(k=0;k<n/2;k++)
		{
			theta = -2.0*k*M_PI/n;
			w_r = cos(theta);
			w_i = sin(theta);
			for(p=k;p<N;p+=n)
			{
				q = p+n/2;
				t_r = w_r*y_r[q]-w_i*y_i[q];
				t_i = w_r*y_i[q]+w_i*y_r[q];
				y_r[q] = y_r[p] - t_r;
				y_i[q] = y_i[p] - t_i;
				y_r[p] += t_r;
				y_i[p] += t_i;
			}
		}
		n <<= 1;
	}
	return 0;
}

