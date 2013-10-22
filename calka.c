#include<stdio.h>
#include<math.h>

double f (double x)
{return pow(M_E, -x*x);}


int main(){
	int i;
double cal = 0 ;
double a=-2;
double b=2;
double n =100000000;
double h = (b-a)/n;

for(i=1;i<(n-1);i++){
	cal += (f(a+i*h) + f(a+(i+1.0)*h))/2.0;
}
	cal = cal*h;
	printf("wynik: %f \n", cal);
}
