#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

double myderiv(double x,double step_size,double(*func)(double x))
{
	double deriv =(func(x+step_size)-func(x-step_size))/(2*step_size);
	return deriv;
}

int main()
{
	double x,step_size,myderivative;
	char function[] ="";//function[] is where we store the function we input
	printf("please input the function\n");
	scanf("%s",function);
	printf("the value of x is\n");
	scanf("%lf",&x);
	printf("please input the stepsize\n");
	scanf("%lf",&step_size);
	if(strcmp(function,"sinx")==0)
	{
		myderivative = myderiv(x,step_size,sin);
		printf("the error is %lf\n",myderivative - cos(x));
	}
	if(strcmp(function,"cosx")==0)
	{
		myderivative = myderiv(x,step_size,cos);
		printf("the error is %lf\n",myderivative + sin(x));
	}
	if(strcmp(function,"logx")==0)
	{
		myderivative = myderiv(x,step_size,log);
		printf("the error is %lf\n",myderivative - (1/x));
	}
	printf("the derivative is %lf\n",myderivative);
	return 0;
}
