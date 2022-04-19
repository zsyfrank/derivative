#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void tododerivative(double fx1,double fx2)
{
	double derivative;
	derivative = (fx2-fx1)/1e-6;
	printf("%lf",derivative);
}
int main()
{
	double x,fx1,fx2;//fx1,fx1 is used to do the derivative
	double exponent;
	printf("the value of x is\n");
	scanf("%lf",&x);
	char function[] ="";//function[] is where we store the function we input
	printf("please input the function\n");
	scanf("%s",function);
	if(strcmp(function,"sinx")==0)
	{
		fx1=sin(x);
		fx2=sin(x+1e-6);
		tododerivative(fx1,fx2);
	}
	if(strcmp(function,"cosx")==0)
	{
		fx1=cos(x);
		fx2=cos(x+1e-6);
		tododerivative(fx1,fx2);
	}
	if(strcmp(function,"logx")==0)
	{
		fx1=log(x);
		fx2=log(x+1e-6);
		tododerivative(fx1,fx2);
	}
	char *s1="x^";//s1 is used to judge whether the function we input is a power function
	if(strncmp(function,s1,2)==0)
	{
		exponent=atof(function);
		printf("%lf",atof(function));
		fx1=pow(x,exponent);
		fx2=pow(x+1e-6,exponent);
	}
	return 0;
}