#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv) {
   char host[150];
   int rank;
   int namelen;
   int k,i,j,sum,pom;
   int size,n,nn;
   
   printf("Podaj wielkosc macierzy\n");
   scanf("%d",&n);
   

    

  
   //**********************    iNICJACJA ********************************************
    MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Get_processor_name(host,&namelen);
   MPI_Comm_size(MPI_COMM_WORLD, &size);

   //*************************   Wszytanie macierzy   *****************************
   int A[n][n];
   int B[n][n];
   int C[n][n];
   int P[n][n]; 
  
   
   if(rank=0){
   
   nn = size % n;
   n = n + nn;
   printf("nn: %d  n %d\n",nn,n);
   
   
   if(rank==0){
   for(i=0;i<n;i++){ 
		for(j=0;j<n;j++){  
		
	    A[i][j]=i;
		C[i][j]=0;
	   }
	}
	for(i=0;i<n;i++){ 
		for(j=0;j<n;j++){  
		
	   B[i][j]=i;
	   }
	}
	
	}
   
  }
int tag = 1;

	//MPI_Scatter(	&A, 1,   MPI_INT, &C,    1,   MPI_INT,0, MPI_COMM_WORLD);

	
	
	
for (j=0;j<n;j++) {
for (i=0;i<n;i++) {
for (k=0;k<n;k++) {
C[i][j] += A[i][k] * B[k][j] ;
}}}


//MPI_Gather(&C, 4, MPI_INT, &A, 4, MPI_INT, 0, MPI_COMM_WORLD);
if(rank=0){
	for(i=0;i<n;i++){ 
	printf("\n       ");
		for(j=0;j<n;j++){  
		printf(" %d ",B[i][j]);
	   }
	}
	
	for(i=0;i<n;i++){ 
	printf("\n");
		for(j=0;j<n;j++){  
		printf(" %d ",A[i][j]);
	   }
	}

	printf("\n Macierz wynik:\n");
	for(i=0;i<n;i++){ 
	printf("\n");
		for(j=0;j<n;j++){  
		printf(" %d ",C[i][j]);
	   }
	}
printf("\n");
}
return 0;
}
