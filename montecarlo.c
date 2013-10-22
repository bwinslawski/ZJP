#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

main(int argc, char* argv)
{
	long int niter=1000000000;
	//sscanf(argv[1], "%ld", &niter); 
  
   double x,y;
   int i,count=0; /* # of points in the 1st quadrant of unit circle */
   double z;
   double pi;

 //sscanf(argv[1], "%d", &niter); 


   /* initialize random numbers */
   srand(SEED);
   count=0;
   for ( i=0; i<niter; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
   pi=(double)count/niter*4;
   printf("# of trials= %ld , estimate of pi is %g \n",niter,pi);
}