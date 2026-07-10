#include <stdio.h>
#include <math.h>

int main(void){
    int N;
    scanf("%d",&N);
    double quotient=pow(0.5,N);
    printf("%.*f\n",N,quotient);
    return 0;
}   