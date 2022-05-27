#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double derivative(double x,double (*func)(double),double prec,bool &flag)//guess the the proper step_size for target precision
{
	flag = 1;
	double step_size = pow(prec,4);//estimate the step_size basing on precision
	double deriv1 = (func(x+2*step_size)+4*func(x+step_size)-func(x-2*step_size)-4*func(x-step_size))/(12*step_size);
	step_size = step_size/2;
	double deriv2 = (func(x+2*step_size)+4*func(x+step_size)-func(x-2*step_size)-4*func(x-step_size))/(12*step_size);
	double error = fabs(deriv1-deriv2);
	if(error <= prec)
	{
		cout<<deriv1<<","<<deriv2<<","<<step_size<<std::endl;
		flag = 0;
		cout<<"it's a good guess,and the derivative is"<<deriv2<<std::endl;
	}
	else
	{
		cout<<"it's a guess is not good enough ,and the present derivative on STEP1 is"<<deriv2<<std::endl;
		int i = 0;
		while(error > prec)
		{
			step_size = step_size/2;
			error = fabs(deriv2 - (func(x+2*step_size)+4*func(x+step_size)-func(x-2*step_size)-4*func(x-step_size))/(12*step_size));
			deriv2 = (func(x+2*step_size)+4*func(x+step_size)-func(x-2*step_size)-4*func(x-step_size))/(12*step_size);
			i++;
		}
		cout<<"it's on STEP"<<i<<" that the target precision is reached"<<",and the derivative is"<<deriv2<<std::endl;
	}
	return deriv2;
}

double myderiv(double x, double step_size, double (*func)(double),double h,double prec,double max_tries,bool &flag)// stepsize is divided by h every time
{
	cout<<fixed<<setprecision(10)<<"func("<<x<<")="<<func(x)<<std::endl;
	int i;
	double deriv1,deriv2,error,prec_improve=0;
	for(i=0;i<max_tries;i++)
	{
		deriv1=(func(x+step_size)-func(x-step_size))/(2*step_size);
	    deriv2=(func(x+2*step_size)+4*func(x+step_size)-func(x-2*step_size)-4*func(x-step_size))/(12*step_size);
	    cout<<"when the step size is"<<step_size<<"the error is"<<deriv1-deriv2<<std::endl;
		prec_improve=fabs((error - (deriv1-deriv2))/deriv2);//to calculate how much the precision has been improved
	 //   cout<<"the error has been improved by"<<prec_improve<<std::endl;
		error=deriv1-deriv2;
	    if(fabs(deriv1-deriv2)<=prec)
	    {
			flag = 0;
		    break;
	    }
	    step_size=step_size/h;
	}
	return deriv1;
}

int main()
{   
    double x,step_size,h,prec,max_tries;
	bool flag = 1;
    double result1,result2,result3,result4;
	cout<<"please input the parameter:"<<std::endl;
    cin>>x;
	cout<<"please input the precision you need:"<<std::endl;
	cin>>prec;
	cout<<"please input the step size:"<<std::endl;
	cin>>step_size;
	cout<<"please input the multiple that stepsize is reduced every time:"<<std::endl;
	cin>>h;
	cout<<"please input the max tries:"<<std::endl;
	cin>>max_tries;
//sinx
	cout<<"for sinx"<<endl;
    result1 = derivative(x,&sin,prec,flag);
	if(flag)// geting derivative through comparing the two methods in case the guess failed
	{	
		result1=myderiv(x,step_size,&sin,h,prec,max_tries,flag);
	}
	cout<<fixed<<setprecision(10)<<"sinx'="<<result1<<std::endl;
//cosx
	cout<<"for cosx"<<endl;
	result2 = derivative(x,&cos,prec,flag);
	if(flag)// geting derivative through comparing the two methods in case the guess failed
	{
		result2=myderiv(x,step_size,&cos,h,prec,max_tries,flag);
	}	
	cout<<fixed<<setprecision(10)<<"cosx'="<<result2<<std::endl;
//e^x
	cout<<"for e^x"<<endl;
	result3=derivative(x,&exp,prec,flag);
	if(flag)// geting derivative through comparing the two methods in case the guess failed
	{
		result3=myderiv(x,step_size,&exp,h,prec,max_tries,flag); 
	}	
	cout<<fixed<<setprecision(10)<<"e^x'="<<result3<<std::endl;
//lnx
	cout<<"for lnx"<<endl;
	result4=derivative(x,&log,prec,flag);
	if(flag)// geting derivative through comparing the two methods in case the guess failed
	{
		result4=myderiv(x,step_size,&log,h,prec,max_tries,flag);  
	}
	cout<<fixed<<setprecision(10)<<"lnx'="<<result4<<std::endl;
    return 0;
}
