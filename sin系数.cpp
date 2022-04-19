#include<stdio.h>
#include<string.h>
#include<math.h>
#include<assert.h>
double deri_sin(double fx1,double fx2)//to calculate the derivative of the functiom;
{	
	double deriv;
    deriv=(fx2-fx1)/1e-6;
    return deriv;
}
double derivative (char f[])
{
       int i;
       double fx1,fx2,df_dx,x;
       for(i=0;strlen(f);i++)//to judge whether the function is consistent with '"number"*sin(x)";
       {
             if(f[i]='s')
                  if(f[i+1]='i')
                         if(f[i+2]='n')
							 x=f[i+3];
							 fx1=sin(x);
						     fx2=sin(x+1e-6);
                               df_dx= deri_sin(fx1,fx2);
       }
        return df_dx;
}
int Myatoi(const char f[]) //to get the coefficient before the function "sin";
{
   assert(f!= NULL);
   if(f==NULL)
       return 0;
   int tmp=0;
   while(*f>'0' &&*f<='9')//while(isdigit(*f)) is to judge whether the characters before the fuction "sin" are numbers;
   {
    tmp=tmp*10+(*f-'0');//get the numbers and convert characters into numbers;
    f++;
   }
   return tmp;
}
int main()
{
      char f[]="";//function[] is where we store the function we input
	  printf("please input the function\n");
      scanf("%s",f);//store the fuction as characters;
      double coef,y;
      coef=Myatoi(f);//coef is the coefficient before "sin";
      y=coef*derivative (f);//calculate the derivative;
      printf("The derivation of function is %d",y);
      return 0;
}
