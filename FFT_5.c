#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int Generate_N(int p);
int Bit_Increase5(int *D, int b, int N);
int Bit_Reverse5(int *D, int b, int N);
int Bit_Reverse_Integer5(int N);
//int Initial(double *x, double *y, int N);
//int FFT3(double *x_r, double *x_i, double *y_r, double *y_i,double *z_r,double *z_i, int N);
//int Print_Complex_Vector(double *y_r, double *y_i, int N);
double angle(int p, int n);

int main()
{
	int p, N, D[2];
	double *y_r, *y_i, *x_r, *x_i,*z_r,*z_i;
	//Bit_Reverse_Integer5(25);
	//Bit_Increase5(D, 5, 2);
	//Bit_Reverse5(D, 5, 2);
	printf("Please input p:");
	scanf("%d", &p);
	N = Generate_N(p);
	printf("5^%d=%d\n", p,N);
	x_r = (double *) malloc(N*sizeof(double));
	x_i = (double *) malloc(N*sizeof(double));
	y_r = (double *) malloc(N*sizeof(double));
	y_i = (double *) malloc(N*sizeof(double));
	z_r = (double *) malloc(N*sizeof(double));
	z_i = (double *) malloc(N*sizeof(double));
	
	Initial(x_r, x_i, N);
	FFT3(x_r, x_i, y_r, y_i,z_r,z_i, N);
	Print_Complex_Vector(y_r, y_i, N);
	return 0;
}

int Generate_N(int p)
{
	int i, N = 1;
	for (i=0;i<p;++i)
	{
		N = N * 5;
	}
	return N;
}

int Bit_Increase5(int *D, int b, int N)
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

int Bit_Reverse5(int *D, int b, int N)
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

int Bit_Reverse_Integer5(int N)
{
	int i, j , M;
	i = 0;
	j = 0;
	
	while(i<N)
	{
		printf("%d <-> %d", i,j);
		M = N / 5;
		while(j >= 4*M & M > 0)
		{
			j = j - 4*M;
			M = M / 5;
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

int FFT3(double *x_r, double *x_i, double *y_r, double *y_i,double *z_r,double *z_i, int N)
{
	int a,i, j, n, M, k, p, q, q1, q2,q3,q4;
	double t_r, t_i, t_r1, t_r2, t_i1, t_i2,t_r3,t_i3,t_r4,t_i4;
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
		M = N / 5;
		while(j >= 4*M & M > 0)
		{
			j = j - 4*M;
			M = M / 5;
		}
			j = j + M;
			i = i + 1;
	}
	/*for(n=0;n<N;n++)
	{
		printf("%f %f\n", y_r[n],y_i[n]);
	}*/
	
	double theta, w_r, w_i,w_r1,w_i1,w_r2,w_i2,w_r3,w_i3,w_r4,w_i4;
	n = 5;
	while(n <= N)
	{
		for(k=0;k<n/5;k++)
		{
			for(p=k;p<N;p+=n)
			{
				q1 = p + n/5;
				q2 = p + 2*n/5;
				q3 = p + 3*n/5;
				q4 = p + 4*n/5;
				w_r = cos(angle(0*p,n));
				w_i = sin(angle(0*p,n));
				t_r = w_r*y_r[p]-w_i*y_i[p];
				t_i = w_r*y_i[p]+w_i*y_r[p];
				w_r1 = cos(angle(1*p,n));
				w_i1 = sin(angle(1*p,n));
				t_r1 = w_r1*y_r[q1]-w_i1*y_i[q1];
				t_i1 = w_r1*y_i[q1]+w_i1*y_r[q1];
				w_r2 = cos(angle(2*p,n));
				w_i2 = sin(angle(2*p,n));
				t_r2 = w_r2*y_r[q2]-w_i2*y_i[q2];
				t_i2 = w_r2*y_i[q2]+w_i2*y_r[q2];
				w_r3 = cos(angle(3*p,n));
				w_i3 = sin(angle(3*p,n));
				t_r3 = w_r3*y_r[q3]-w_i3*y_i[q3];
				t_i3 = w_r3*y_i[q3]+w_i3*y_r[q3];
				w_r4 = cos(angle(4*p,n));
				w_i4 = sin(angle(4*p,n));
				t_r4 = w_r4*y_r[q4]-w_i4*y_i[q4];
				t_i4 = w_r4*y_i[q4]+w_i4*y_r[q4];
				z_r[p] = t_r+t_r1+t_r2+t_r3+t_r4;
				z_i[p] = t_i+t_i1+t_i2+t_i3+t_i4;

				/*for(a=0;a<N;a++)
				{printf("\ny_r[%d]=%f , y_i[%d]=%f \n",a,y_r[a],a,y_i[a]);}	*/			
				//printf("w_r=%f,w_i=%f,w_r1=%f,w_i1=%f,w_r2=%f,w_i2=%f. \n",w_r,w_i,w_r1,w_i1,w_r2,w_i2);
				//printf("\n%f %f %f %f %f\n", t_r,t_r1,t_r2,t_r3,t_r4);
				//printf("\nz_r[%d]=%f ,z_i[%d]=%f\n", p,z_r[p],p,z_i[p]);
				//printf("\ny_r[%d]=%f ,y_r[%d]=%f\n", p,y_r[p],p,y_i[p]);
				
				w_r = cos(angle(0*q1,n));
				w_i = sin(angle(0*q1,n));
				t_r = w_r*y_r[p]-w_i*y_i[p];
				t_i = w_r*y_i[p]+w_i*y_r[p];
				w_r1 = cos(angle(1*q1,n));
				w_i1 = sin(angle(1*q1,n));
				t_r1 = w_r1*y_r[q1]-w_i1*y_i[q1];
				t_i1 = w_r1*y_i[q1]+w_i1*y_r[q1];
				w_r2 = cos(angle(2*q1,n));
				w_i2 = sin(angle(2*q1,n));
				t_r2 = w_r2*y_r[q2]-w_i2*y_i[q2];
				t_i2 = w_r2*y_i[q2]+w_i2*y_r[q2];
				w_r3 = cos(angle(3*q1,n));
				w_i3 = sin(angle(3*q1,n));
				t_r3 = w_r3*y_r[q3]-w_i3*y_i[q3];
				t_i3 = w_r3*y_i[q3]+w_i3*y_r[q3];
				w_r4 = cos(angle(4*q1,n));
				w_i4 = sin(angle(4*q1,n));
				t_r4 = w_r4*y_r[q4]-w_i4*y_i[q4];
				t_i4 = w_r4*y_i[q4]+w_i4*y_r[q4];
				z_r[q1] = t_r+t_r1+t_r2+t_r3+t_r4;
				z_i[q1] = t_i+t_i1+t_i2+t_i3+t_i4;

//				printf("w_r=%f,w_i=%f,w_r1=%f,w_i1=%f,w_r2=%f,w_i2=%f. \n",w_r,w_i,w_r1,w_i1,w_r2,w_i2);
				//printf("\n%f %f\n", z_r[q1],z_i[q1]);
//				printf("\n%f %f %f\n",t_i,t_i1,t_i2);
				w_r = cos(angle(0*q2,n));
				w_i = sin(angle(0*q2,n));
				t_r = w_r*y_r[p]-w_i*y_i[p];
				t_i = w_r*y_i[p]+w_i*y_r[p];
				w_r1 = cos(angle(1*q2,n));
				w_i1 = sin(angle(1*q2,n));
				t_r1 = w_r1*y_r[q1]-w_i1*y_i[q1];
				t_i1 = w_r1*y_i[q1]+w_i1*y_r[q1];
				w_r2 = cos(angle(2*q2,n));
				w_i2 = sin(angle(2*q2,n));
				t_r2 = w_r2*y_r[q2]-w_i2*y_i[q2];
				t_i2 = w_r2*y_i[q2]+w_i2*y_r[q2];
				w_r3 = cos(angle(3*q2,n));
				w_i3 = sin(angle(3*q2,n));
				t_r3 = w_r3*y_r[q3]-w_i3*y_i[q3];
				t_i3 = w_r3*y_i[q3]+w_i3*y_r[q3];
				w_r4 = cos(angle(4*q2,n));
				w_i4 = sin(angle(4*q2,n));
				t_r4 = w_r4*y_r[q4]-w_i4*y_i[q4];
				t_i4 = w_r4*y_i[q4]+w_i4*y_r[q4];
				z_r[q2] = t_r+t_r1+t_r2+t_r3+t_r4;
				z_i[q2] = t_i+t_i1+t_i2+t_i3+t_i4;
				
				w_r = cos(angle(0*q3,n));
				w_i = sin(angle(0*q3,n));
				t_r = w_r*y_r[p]-w_i*y_i[p];
				t_i = w_r*y_i[p]+w_i*y_r[p];
				w_r1 = cos(angle(1*q3,n));
				w_i1 = sin(angle(1*q3,n));
				t_r1 = w_r1*y_r[q1]-w_i1*y_i[q1];
				t_i1 = w_r1*y_i[q1]+w_i1*y_r[q1];
				w_r2 = cos(angle(2*q3,n));
				w_i2 = sin(angle(2*q3,n));
				t_r2 = w_r2*y_r[q2]-w_i2*y_i[q2];
				t_i2 = w_r2*y_i[q2]+w_i2*y_r[q2];
				w_r3 = cos(angle(3*q3,n));
				w_i3 = sin(angle(3*q3,n));
				t_r3 = w_r3*y_r[q3]-w_i3*y_i[q3];
				t_i3 = w_r3*y_i[q3]+w_i3*y_r[q3];
				w_r4 = cos(angle(4*q3,n));
				w_i4 = sin(angle(4*q3,n));
				t_r4 = w_r4*y_r[q4]-w_i4*y_i[q4];
				t_i4 = w_r4*y_i[q4]+w_i4*y_r[q4];
				z_r[q3] = t_r+t_r1+t_r2+t_r3+t_r4;
				z_i[q3] = t_i+t_i1+t_i2+t_i3+t_i4;
				
				w_r = cos(angle(0*q4,n));
				w_i = sin(angle(0*q4,n));
				t_r = w_r*y_r[p]-w_i*y_i[p];
				t_i = w_r*y_i[p]+w_i*y_r[p];
				w_r1 = cos(angle(1*q4,n));
				w_i1 = sin(angle(1*q4,n));
				t_r1 = w_r1*y_r[q1]-w_i1*y_i[q1];
				t_i1 = w_r1*y_i[q1]+w_i1*y_r[q1];
				w_r2 = cos(angle(2*q4,n));
				w_i2 = sin(angle(2*q4,n));
				t_r2 = w_r2*y_r[q2]-w_i2*y_i[q2];
				t_i2 = w_r2*y_i[q2]+w_i2*y_r[q2];
				w_r3 = cos(angle(3*q4,n));
				w_i3 = sin(angle(3*q4,n));
				t_r3 = w_r3*y_r[q3]-w_i3*y_i[q3];
				t_i3 = w_r3*y_i[q3]+w_i3*y_r[q3];
				w_r4 = cos(angle(4*q4,n));
				w_i4 = sin(angle(4*q4,n));
				t_r4 = w_r4*y_r[q4]-w_i4*y_i[q4];
				t_i4 = w_r4*y_i[q4]+w_i4*y_r[q4];
				z_r[q4] = t_r+t_r1+t_r2+t_r3+t_r4;
				z_i[q4] = t_i+t_i1+t_i2+t_i3+t_i4;				
				
				//printf("w_r=%f,w_i=%f,w_r1=%f,w_i1=%f,w_r2=%f,w_i2=%f. \n",w_r,w_i,w_r1,w_i1,w_r2,w_i2);
				//printf("\n%f %f %f\n", t_i,t_i1,t_i2);
				/*for(i=0;i<N;i++)
				{
				printf("%f %f\n",y_r[i],y_i[i]);
				}*/
			}
		}
			for (i=0;i<N;i++)
			{
				y_r[i] = z_r[i];
		        y_i[i] = z_i[i];
			}

			/*for(i=0;i<N;i++)
				{
				printf("%f %f\n",y_r[i],y_i[i]);
				}*/
	n = n*5;
	//printf("\n%d\n", n);
	//system("pause");
	}

	return 0;
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

double angle(int p, int n)
{
	double a;
	a = -2.0*p*M_PI/n;
	//printf("a=%f",a);
	return a;	
}
