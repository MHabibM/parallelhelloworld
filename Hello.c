#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>



void* Hello(){

	printf("HelloWorld!!\n");

}


int main (int argc, char* argv[]){

if ( argc != 2 ){

	printf("needs number of repeats\n");
	return 0;
}
	double elapsed;
	struct timeval start, end;
       
	/* https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_74/apis/gettod.htm */

	int i;
	int r= atoi(argv[1]);
        gettimeofday(&start, NULL);
	
		for (i=0; i<r; i++){
			Hello();
		
		}
	gettimeofday(&end, NULL);
	elapsed = ((double)end.tv_sec + 0.000001*(double)end.tv_usec) - ((double)start.tv_sec+0.000001*(double)start.tv_usec);

printf("time elapsed = %lf \n", elapsed);
	return 0;
}
