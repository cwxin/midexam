#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int*, int*);
void portion(int*, int, int);
void quick_sort(int*, int);
int *v, N, i, temp, pivot, side;

int main(void)
{
	printf("Input number of the term N of a array(please input N is odd):");
    scanf("%d", &N);
	
	if (N%2 != 0)
	{
	time_t T=1;
	srand(time(&T));
	v=(int*)malloc(N*sizeof(int));
	printf("Sort method:Quick_Sort\n");
	for(i=0;i<N;++i)
		{ 
			v[i]=rand()%100;
			printf("%d,", v[i]);
		}
	//quick_sort(v,N);
	}
	else
	{
		printf("please run this program again!");
	}	
} 

void swap(int *a, int *b)
{
	temp = *a;
	*b = *a;
	*a =temp;
}

void portion(int *v, int New, int pivot_k)
{
	side=pivot;
	pivot=v[pivot_k];
	swap(&v[pivot_k],&v[pivot_k+(New-1)]);
	/*for(i=0,i<New,i++)
	{
		
	}*/
}

