#include <stdio.h>


int main(int argc, char **argv) {
   char host[150];
   int rank;
   int namelen;
   int k,i,j,sum,pom;
   int size,n,nn;
   
   sscanf(argv[1], "%d", &n); 
   
   int A[n][n];
   int B[n];
   int C[n][n];
   int P[n][n]; 
  
   for(i=0;i<n;i++){ 
		for(j=0;j<n;j++){  
		
	    A[i][j]=i;
		C[i][j]=0;
	   }
	}
	for(i=0;i<n;i++){  
	   B[i]=2;
	   }
	
	
 

for (i=0;i<n;i++) {
for (k=0;k<n;k++) {
C[i][k] += A[i][k] * B[k];
}}


	for(i=0;i<n;i++){ 
	printf(" %d ",B[i]);	
	}
	printf("\n   * \n");
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

return 0;
}
