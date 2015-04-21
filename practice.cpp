#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, N, *v, temp, j;
	time_t T=1;
	
	srand(time(&T));
	N=10;
	v=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;++i)
	{
		v[i]=rand()%100;
		printf("%d,", v[i]);
	}
	printf("\n");
	
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
	for(i=0;i<N;++i)
	{
	printf("%d,", v[i]);
	}
	printf("\n");
	}

}
