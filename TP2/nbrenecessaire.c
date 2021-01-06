#include<stdio.h>
#include<stdlib.h>
double f(double x)
{
	return x;
}

double simpson(double(*f)(double),double a,double b,int n)
{
        float h=(b-a)/n;
        double x=a+h;
        double z=a+h/2;
        double I1=0;
        double I2=f(z);
        for(int i=0; i<n-1; i++)
        {
                z=z+h;
                I1=I1+f(x);
                I2=I2+f(z);
                x=x+h;
        }
        return (h/6)*(f(a)+f(b)+2*I1+4*I2);
}

double trapezes(double(*f)(double),double a,double b,int n)
{
        float h=(b-a)/n;
        double s=0.5*(f(a)+f(b));
        for(int i=1; i<n; i++)
        {
                s=s+f(a+i*h);
        }
        return s*h;
}

double rectgauche(double (*f)(double), double a, double b, int n)
{
        double h=(b-a)/n;
        double s=0;
        for(int i=1; i <= n+1; i++)
        {
                s = s + f(a+i*h);
        }
        return h*s;
}

double rectdroite(double (*f)(double), double a, double b, int n)
{
        double h=(b-a)/n;
        double s=0;
        for(int i=0; i <= n; i++)
        {
                s = s + f(a+i*h);
        }
        return h*s;
}


double nbrnecessaire (double(*f)(double),double a,double b,double Err,double(*Methode)(double(*)(double),double,double,int),double I)
{
	int n=1;
	while((abs(Methode(f,a,b,n))-I)>Err)
	{
		n=n+1;
	}
	return n;
}

int main()
{
double s;
double a=0;
double b=1;
int n=100;
s=simpson(f,a,b,n);
printf("le resultat est %f",s);
printf("le nombre necessaire est %u",nbrnecessaire(f,a,b,0.0000001,simpson,0.5));
return 0;
}
