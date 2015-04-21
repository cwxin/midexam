#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void MergeSort(int[]);
int *v, i, temp, j;
double N;

int main()
{
	int *v, i;
	time_t T=1;
	N=10;
	srand(time(&T));
	v=(int*)malloc(N*sizeof(int));
	
	printf("Sort method:Merge Sort\n");
	for(i=0;i<N;++i)
	{
		v[i]=rand()%100;
		printf("%d,", v[i]);
	}
	printf("\n");	
	
	MergeSort(v);	
} 

void MergeSort(int v[])
{
	N=N/2;
	printf("\n");
	printf("A part of left array:\n");
	for	(i=0;i<N;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(1) ");
	for (i=0;i<3;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\t\t");
	for (i=3;i<N;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(2) ");
	for (i=0;i<1;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\t\t");
	for (i=1;i<3;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\t\t");
	for (i=3;i<5;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(3) ");
	printf("%d,", v[0]);
	printf("\t\t");
	if(v[1]>v[2])
		{
			temp = v[1];
			v[1]=v[2];
			v[2]=temp;
		}
	for (i=1;i<3;++i)
	{
		printf("%d,", v[i]);
	}
	if(v[3]>v[4])
	{
			temp = v[3];
			v[3]=v[4];
			v[4]=temp;
	}
	printf("\t\t");
	for (i=3;i<5;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(4) ");
	for(j=3;j<N;++j)
	{
		for(i=0;i<N-j;++i)
		{	 
			if(v[i]>v[i+1])
			{
			temp = v[i];
			v[i]=v[i+1];
			v[i+1]=temp;
			}
		}
	}
	for (i=0;i<3;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\t\t");
	for (i=3;i<N;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(5) ");
	for(j=1;j<N;++j)
	{
		for(i=0;i<N-j;++i)
		{	 
			if(v[i]>v[i+1])
			{
			temp = v[i];
			v[i]=v[i+1];
			v[i+1]=temp;
			}
		}
	}
	for	(i=0;i<N;++i)
	{
		printf("%d,", v[i]);
	}
	
	printf("\n");
	printf("\nA part of right array:\n");
	for	(i=5;i<2*N;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(1) ");
	for (i=5;i<8;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\t\t");
	for (i=8;i<10;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(2) ");
	for (i=5;i<6;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\t\t");
	for (i=6;i<8;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\t\t");
	for (i=8;i<10;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(3) ");
	printf("%d,", v[5]);
	printf("\t\t");
	if(v[6]>v[7])
		{
			temp = v[6];
			v[6]=v[7];
			v[7]=temp;
		}
	for (i=6;i<8;++i)
	{
		printf("%d,", v[i]);
	}
	if(v[8]>v[9])
	{
			temp = v[8];
			v[8]=v[9];
			v[9]=temp;
	}
	printf("\t\t");
	for (i=8;i<10;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(4) ");
	for(j=3;j<N;++j)
	{
		for(i=5;i<2*N-j;++i)
		{	 
			if(v[i]>v[i+1])
			{
			temp = v[i];
			v[i]=v[i+1];
			v[i+1]=temp;
			}
		}
	}
	for (i=5;i<8;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\t\t");
	for (i=8;i<10;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	printf("(5) ");
	for(j=1;j<N;++j)
	{
		for(i=5;i<2*N-j;++i)
		{	 
			if(v[i]>v[i+1])
			{
			temp = v[i];
			v[i]=v[i+1];
			v[i+1]=temp;
			}
		}
	}
	for	(i=5;i<10;++i)
	{
		printf("%d,", v[i]);
	}
	printf("\n");
	
	for(j=1;j<2*N;++j)
	{
		for(i=0;i<2*N-j;++i)
		{	 
			if(v[i]>v[i+1])
			{
			temp = v[i];
			v[i]=v[i+1];
			v[i+1]=temp;
			}
		}
	}
	
	printf("\nFinaly,we finish:\n");
	for	(i=0;i<10;++i)
	{
		printf("%d,", v[i]);
	}
}
