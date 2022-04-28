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
		for(int i=0;i<6;i++)//dynamic step_size
		{
			myderivative = myderiv(x,step_size,sin);
			printf("when the step_size is %lf the error is %lf\n",step_size,myderivative - cos(x));//print the error
			if(myderivative - cos(x)==0)
			{
				break;
			}
			step_size = step_size/10;//dynamic step_size
		}
	}
	if(strcmp(function,"cosx")==0)
	{
		for(int i=0;i<6;i++)
		{
			myderivative = myderiv(x,step_size,cos);
			printf("when the step_size is %lf the error is %lf\n",step_size,myderivative +sin(x));
			if(myderivative + sin(x)==0)
			{
				break;
			}
			step_size = step_size/10;
		}
	}
	if(strcmp(function,"logx")==0)
	{
	for(int i=0;i<6;i++)
		{
			myderivative = myderiv(x,step_size,log);
			printf("when the step_size is %lf the error is %lf\n",step_size,myderivative - 1/x);
			if(myderivative - (1/x)==0)
			{
				break;
			}
			step_size = step_size/10;
		}
	}
	printf("the derivative is %lf\n",myderivative);
	return 0;
}
