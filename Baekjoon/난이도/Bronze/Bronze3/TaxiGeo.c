#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

int main(){
    int r;
    scanf("%d",&r);

    double result1=r*r*PI;
    double result2=r*r*2;

    printf("%.6lf\n",result1);
    printf("%.6lf\n",result2);  
    return 0;
}