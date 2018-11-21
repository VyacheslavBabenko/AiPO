#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double function_sin(double x){
    return sin(x);
}

double function_cos(double x){
    return x*cos(x);
}

double function_tg(double x){
    return x*x+x-tan(x);
}

double function_e(double x){
    return exp(x)+3;
}

double ABS(double x){
    if(x<0) 
		return -x;
    return x;
}

double integrate(double (*f)(double),double a,double b,double c){
    double integral=0.0,i,E=0.000001;
    for(i=a;i<=b;i+=E)
        integral+=(f(i)-c);
    return integral*E;
}

int main(){
    double s,a,b,c,temp;
    struct answer{
        double value;
        int number;
    } answer;
    answer.value=0;
    double (*f[4])(double)={function_sin,function_cos,function_tg,function_e};
    scanf("%lf %lf %lf %lf",&s,&a,&b,&c);
    int i;
    for(i=0;i<4;i++){
        temp=integrate(f[i],a,b,c);
        if(temp>answer.value && temp<=s){
            answer.value=temp;
            answer.number=i;
        }
    }
    printf("%d %lf",answer.number,answer.value);
    return 0;
}
