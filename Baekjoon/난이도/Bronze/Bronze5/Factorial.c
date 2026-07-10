#include <stdio.h>

long long int Factorial(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        return n*Factorial(n-1);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    long long result=Factorial(N);
    printf("%lld\n",result);
    return 0;
}