#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double myderiv(double x, double step_size, double (*func)(double))
{
	cout<<fixed<<setprecision(10)<<"func("<<x<<")="<<func(x)<<std::endl;
	int i;
	double deriv1,deriv2;
	for(i=0;i<10;i++)
	{
		deriv1=(func(x+step_size)-func(x-step_size))/(2*step_size);
	    deriv2=(func(x+2*step_size)+4*func(x+step_size)-func(x-2*step_size)-4*func(x-step_size))/(12*step_size);
	    cout<<"when the step size is"<<step_size<<"the error is"<<deriv1-deriv2<<std::endl;
	    if(fabs(deriv1-deriv2)<1e-10)
	    {
		    break;
	    }
	    step_size=step_size/10;
	}
	return deriv1;
}
int main()
{   
    double x,step_size;
    double result1,result2,result3,result4;
	cout<<"please input the parameter:"<<std::endl;
    cin>>x;
    cout<<"please input the step size:"<<std::endl;
    cin>>step_size;
    result1=myderiv(x,step_size,&sin);
	cout<<fixed<<setprecision(10)<<"result1="<<result1<<std::endl;
	result2=myderiv(x,step_size,&cos); 
	cout<<fixed<<setprecision(10)<<"result2="<<result2<<std::endl;
	result3=myderiv(x,step_size,&exp);  
	cout<<fixed<<setprecision(10)<<"result3="<<result3<<std::endl;
	result4=myderiv(x,step_size,&log);  
	cout<<fixed<<setprecision(10)<<"result4="<<result4<<std::endl;
    return 0;
}
