#include <stdio.h>

double raizq(double);

int main(void)
{  
    double n;
    
    scanf("%lf",&n);
    
    printf("%.2f \n",raizq(n));

    return(0);
}


double raizq (double n)
{
    int x;
    double q = n;
    
    for (x = 0; x < 200; ++x)
          q = q/2 + n/(2*q);
            
    return(q);    
}
