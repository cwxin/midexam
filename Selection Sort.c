#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Selection_Sort(int[],int N);
int *v, i, N, j, min, k, temp;

int main()
{
	printf("Input number of the term of a array:");
    scanf("%d", &N); 
	time_t T=1;
	srand(time(&T));
	v=(int*)malloc(N*sizeof(int));
	
	printf("Sort method:Selection Sort\n");
	for(i=0;i<N;++i)
	{ 
		v[i]=rand()%100;
		printf("%d,", v[i]);
	}
	printf("\n");
		
	Selection_Sort(v,N);	
} 

void Selection_Sort(int v[],int N)
{
	for (i=0;i<N-1;++i)
	{
		min=i;
		for (k=i+1;k<N;++k)
		{
			if(v[k]<v[min])
				min=k;	
		}
		if (min != i)
		{
			temp=v[min];
			v[min]=v[i];
			v[i]=temp;
		}
	}
	for(j=0;j<N;++j)
	{
		printf("%d,", v[j]);
	}
}
