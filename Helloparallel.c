#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int num_threads, step;



void* Hello(void *arg){
int *argg= arg;
printf("argg= %d\n", *argg);
printf("step= %d\n", step);
int id = *argg;
for(int i = id*step; i<(id+1)*step; i++){
	printf("HelloWorld!!\n");
	}

}


int main (int argc, char* argv[]){

if ( argc != 3 ){

	printf("needs number of repetition\n");
	return 0;
}
	int i;
	int r= atoi(argv[1]);
	double elapsed;

	num_threads = atoi(argv[2]);
	step = r/num_threads;
	printf("num_threads from main= %d\n", num_threads);
	printf("r from main= %d\n", r);
	pthread_t *tid= malloc(num_threads*sizeof(pthread_t));
	int *idx = malloc(num_threads*sizeof(int));

	struct timeval start, end;
       
	/* https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_74/apis/gettod.htm */



        gettimeofday(&start, NULL);
		for(i=0; i<num_threads; i++){
			idx[i]=i;
			pthread_create(&tid[i], NULL, Hello, &idx[i]);
	
			}
		for(i=0; i<num_threads; i++){
			pthread_join(tid[i], NULL);
			printf("Done Joining \n");
			}
			
			
		
	gettimeofday(&end, NULL);
	elapsed = ((double)end.tv_sec + 0.000001*(double)end.tv_usec) - ((double)start.tv_sec+0.000001*(double)start.tv_usec);

printf("time elapsed = %lf \n", elapsed);
	return 0;
}
