#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "mpi.h"
#define SEED 35791246

int main(int argc, char **argv) {
   int rank;
   char host[150];
   int namelen;
   int il= 20;
   int i,j,sum=0;
   int size;
   int niter=0;
   double x,y;
   int count=0; /* # of points in the 1st quadrant of unit circle */
   double z;
   double pi;
   
   
   
  
/* Message tag */
   int tag = 1;
	double suma=0;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Get_processor_name(host,&namelen);
   MPI_Comm_size(MPI_COMM_WORLD, &size);

 
sscanf(argv[1], "%d", &niter); 

   fflush(stdout);
    if (rank == 0) {
   }
 else {
		size=size-1;
       int poczatek= (rank-1)*niter/size;
		int koniec= (rank)*niter/size;	
		for ( i=poczatek; i<koniec; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
	
   pi=(double)count/niter*4;
		MPI_Reduce(&pi,    &suma, 1,  MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
		}
		if (rank == 0) {
		MPI_Reduce(&pi,    &suma, 1,  MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
		printf("suma: %f\n",suma);    
   }

   MPI_Finalize();
   return 0;
}