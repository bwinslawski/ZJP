#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char **argv){
	
	int rank;
	int size;
	int i,j;
	int n,nn,k;
	
	int ziarno=2;
	int ile;
	int P=0;
	int pow=0;
	MPI_Init(&argc, &argv);	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); // identyfikator obecnego procesu
	MPI_Comm_size(MPI_COMM_WORLD, &size); // uruchomiona ilosc procesów

	
	sscanf(argv[1], "%d", &n); 
	
	
	ile = n; 
	nn = n%size;
		if(nn!=0){
		nn = size - nn;
		n = n + nn;}
		pow = n/size;
		ziarno = (n*n)/size;
	
	int tabD[n*n*2];
	int tabA[n*n*2];
	int tabB[n*n*2];
	int tabC[n*n*2];
	int skladowe[n*n*2];
	
	for(j=0;j<n;j++){  	
	   tabD[j]=j+1;
	   }
	//printf("Ziarno : %d n : %d\n",ziarno,ile);
	
	if (rank == 0){
	
		//printf("Podaj wielkosc macierzy\n");
		//scanf("%d",&n);
		
		int ilosc = ile;
	
		
	//	printf("nn: %d  n %d  ile: %d pow: %d\n",nn,n,ile,pow);
			for (i = 0; i<n*n; i++){ 
				 P++;   
				if(i>=((n*n)-(n*nn))){tabA[i]=0;}
				else if(P-1<ilosc)
				 {tabA[i]=i;  //printf("1: %d) %d<=%d\n",i,P,ilosc);
				 }
				else if (P<=n)
					{tabA[i]=0; //printf("2: %d) %d<%d\n",i,P,n);
					}
				else if(P>=n+1)
					{ //printf("3: %d) %d>%d\n",i,P,n);
					P=0; i--;
					}
			}
			/*for (i = 0; i<n*n; i++){ 
			//printf("tab[%d]  %d  ",i,tabA[i]);
			
			if(i!=0&&(((i+1)%n)==0)) {printf("\n");
			}
			}*/
			}
	

	//MPI_Barrier(MPI_COMM_WORLD);
	
	k=0;
	//printf("ZIARNO : %d \n" , ziarno);
	MPI_Scatter( &tabA , ziarno  , MPI_INT , &tabB, ziarno  , MPI_INT , 0 , MPI_COMM_WORLD);


	for (i=0; i<ziarno; i++){
		if(k>=n) {k=0;}
		skladowe[i]=tabB[i]*tabD[k];
		//printf("tabB[%d]: %d * tabD:%d = skladowa: %d proces %d\n",i, tabB[i],tabD[i],skladowe[i],rank);	
		k++;
		}


	MPI_Gather(&skladowe, ziarno , MPI_INT, &tabC, ziarno , MPI_INT, 0, MPI_COMM_WORLD);
		
	/*if (rank == 0){
		//printf(":::::::::::::::::::\nTu proces %d, drukuje wyniki\n:::::::::::::::::::\n", rank);
		for (i = 0; i<n*n; i++){ 
		
		//printf("  %d  ",tabC[i]);
			
			if(i!=0&&(((i+1)%n)==0)) {printf("\n");}
			}
	}*/

	MPI_Finalize();
	return 0;
}
