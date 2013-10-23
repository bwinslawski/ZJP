#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "mpi.h"


double f (double x)
{return pow(M_E, -x*x);}


int main(int argc, char **argv) {
	   int rank;
	   char host[150];
	   int namelen;
	   int il= 20;
	   int i,j,sum=0;
	   int size;
	   int n=atoi(argv[1]);
	double cal = 0 ;
	double a=-2;
	double b=2;
	double h = (b-a)/n;
  
	double suma=0;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Get_processor_name(host,&namelen);
   MPI_Comm_size(MPI_COMM_WORLD, &size);


   fflush(stdout);
    if (rank == 0) {
   }
 else {
		size=size-1;
        int poczatek= (rank-1)*n/size;
		int koniec= (rank)*n/size;	
		for(i=poczatek;i<koniec;i++){
		cal += (f(a+i*h) + f(a+(i+1.0)*h))/2.0;
		}
		cal = cal*h;
		MPI_Reduce(&cal,    &suma, 1,  MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
		//printf("suma: %f\n",suma);
		}
		if (rank == 0) {
		MPI_Reduce(&cal,    &suma, 1,  MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
		
		  printf("sumaaaaa: %f\n",suma);
		}
  
   MPI_Finalize();
   return 0;
}