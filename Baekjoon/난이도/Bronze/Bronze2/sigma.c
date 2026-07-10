#include <stdio.h>

int main(){
    long long a,b,result;
    scanf("%lld %lld",&a,&b);

    if(a>b){
        result=((a+b)*(a-b+1))/2;
    }else{
        result=((a+b)*(b-a+1))/2;
    }
    printf("%lld\n",result);
    return 0;
}