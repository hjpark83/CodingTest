#include <stdio.h>

int main(void){
    int num,total;
    int count=0;
    scanf("%d",&total);
    for(int i=0;i<total;i++){
        scanf("%d",&num);
        int isPrime=1;
        for(int j=2;j<num;j++){
            if(num%j==0){
                isPrime=0;
                break;
            }
        }
        if(isPrime&&num>1){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}