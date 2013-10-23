#include<stdio.h>
#include<math.h>

double f (double x)
{return pow(M_E, -x*x);}


int main(int argc, char **argv){
	int i;
double cal = 0 ;
double a=-2;
double b=2;
double n = atoi(argv[1]);
double h = (b-a)/n;
//sscanf(argv[1], "%d", &n); 
 

for(i=1;i<(n-1);i++){
	cal += (f(a+i*h) + f(a+(i+1.0)*h))/2.0;
}
	cal = cal*h;
	printf("wynik: %f \n", cal);
}
