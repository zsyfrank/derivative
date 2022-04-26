#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
double myderivative(double x,char *function)
{
	double fx1,fx2;//fx1,fx1 is used to do the derivative
	double exponent;
	double derivative;
	if(strcmp(function,"sinx")==0)
	{
		fx1=sin(x);
		fx2=sin(x+1e-6);
	}
	if(strcmp(function,"cosx")==0)
	{
		fx1=cos(x);
		fx2=cos(x+1e-6);
	}
	if(strcmp(function,"logx")==0)
	{
		fx1=log(x);
		fx2=log(x+1e-6);
	}
	char *s1="x^";//s1 is used to judge whether the function we input is a power function
	if(strncmp(function,s1,2)==0)
	{
		exponent=atof(function);
		printf("%lf",atof(function));
		fx1=pow(x,exponent);
		fx2=pow(x+1e-6,exponent);
	}
	derivative = (fx2-fx1)/1e-6;
	return derivative;
}
int main()
{
	double x,derivative;
	printf("the value of x is\n");
	scanf("%lf",&x);
	char function[] ="";//function[] is where we store the function we input
	printf("please input the function\n");
	scanf("%s",function);
	derivative=myderivative(x,function);
	printf("%lf",derivative);
	return 0;
}
