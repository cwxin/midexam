#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int number, N, *v, i;
	time_t T=1;
	N=20;
	srand(time(&T));
	v=(int*)malloc(N*sizeof(int));
	
	printf("Sort method¡GMerge Sort\n");
	for(i=0;i<N;++i)
	{
		v[i]=rand()%100;
		printf("%d,", v[i]);
	}
	printf("\n");	
} 
