#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int*, int*);
int portion(int*, int, int);
void quick_sort(int*, int);
int *v, N, i, temp, pivot, side, K;

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
	printf("\n");
	
	quick_sort(v,N);
	
	printf("If you want to know the median term of the sequence, please input %d\n", (N+1)/2);
	printf("Input that you want to find which term in the sequece:");
    scanf("%d", &K);
		if ((K<=N) && (K>=1))
			{
				printf("We can find the kth term of the sequence is %d", v[K-1]);
			}
		else
			{
				printf("please run this program again!");
			}
	}
	else
	{
		printf("please run this program again!");
	}	
} 

void swap(int *a, int *b)
{
	temp = *a;
	*a = *b;
	*b = temp;
}

int portion(int *v, int New, int pivot_k)
{
	side = pivot_k;
	pivot = v[pivot_k];
	swap(&v[pivot_k],&v[pivot_k+(New-1)]);
	
	for(i=0;i<New;i++)
	{
		if(v[pivot_k+i]<pivot)
		{
			swap(&v[pivot_k+i],&v[side]);
			side = side+1;
		}
	}
	
	swap(&v[pivot_k+(New-1)],&v[side]);
	return side;
}

void quick_sort(int *v, int part)
{
	if(part==0 || part==1)
	{
		return;
	}
	else
	{
		side = portion(v,part,0);
		if(side != (K-1))
		{
			quick_sort(v,side);
			quick_sort(&v[side+1],part-side-1);
		}
		else
		{
			return;
		}
	}
}

