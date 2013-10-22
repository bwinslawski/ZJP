#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define S 35791246

main(int argc, char* argv)
{
	long int n=1000000000;
	//sscanf(argv[1], "%ld", &n); 
  
   double x,y;
   int i,count=0; 
   double z;
   double pi;

   srand(S);
   count=0;
   for ( i=0; i<n; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
   pi=(double)count/n*4;
   printf("pi is %g \n",pi);
}