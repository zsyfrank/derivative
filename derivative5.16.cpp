#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double myderiv(double x, double step_size, double (*func)(double),double h,double prec,double max_tries)// stepsize is divided by h every time
{
	cout<<fixed<<setprecision(10)<<"func("<<x<<")="<<func(x)<<std::endl;
	int i;
	double deriv1,deriv2,error,prec_improve=0;
	for(i=0;i<100;i++)
	{
		deriv1=(func(x+step_size)-func(x-step_size))/(2*step_size);
	    deriv2=(func(x+2*step_size)+4*func(x+step_size)-func(x-2*step_size)-4*func(x-step_size))/(12*step_size);
	    cout<<"when the step size is"<<step_size<<"the error is"<<deriv1-deriv2<<std::endl;
		prec_improve=fabs((error - (deriv1-deriv2))/deriv2);//to calculate how much the precision has been improved
		cout<<"the error has been improved by"<<prec_improve<<std::endl;
		error=deriv1-deriv2;
	    if(fabs(deriv1-deriv2)<=prec)
	    {
		    break;
	    }
	    step_size=step_size/h;
	}
	if(i>=max_tries)
	{
		cout<<"fail to achieve precision"<<std::endl;
	}
	else
		return deriv1;
}
int main()
{   
    double x,step_size,h,prec,max_tries;
    double result1,result2,result3,result4;
	cout<<"please input the parameter:"<<std::endl;
    cin>>x;
    cout<<"please input the step size:"<<std::endl;
    cin>>step_size;
	cout<<"please input the multiple that stepsize is reduced every time:"<<std::endl;
	cin>>h;
	cout<<"please input the precision you need:"<<std::endl;
	cin>>prec;
	cout<<"please input the max tries:"<<std::endl;
	cin>>max_tries;
    result1=myderiv(x,step_size,&sin,h,prec,max_tries);
	cout<<"for sinx"<<endl;
	cout<<fixed<<setprecision(10)<<"result1="<<result1<<std::endl;
	result2=myderiv(x,step_size,&cos,h,prec,max_tries); 
	cout<<"for cosx"<<endl;
	cout<<fixed<<setprecision(10)<<"result2="<<result2<<std::endl;
	result3=myderiv(x,step_size,&exp,h,prec,max_tries);  
	cout<<"for e^x"<<endl;
	cout<<fixed<<setprecision(10)<<"result3="<<result3<<std::endl;
	result4=myderiv(x,step_size,&log,h,prec,max_tries);  
	cout<<"for lnx"<<endl;
	cout<<fixed<<setprecision(10)<<"result4="<<result4<<std::endl;
    return 0;
}
