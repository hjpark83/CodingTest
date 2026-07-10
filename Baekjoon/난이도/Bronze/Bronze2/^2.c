#include <stdio.h>
#include <math.h>

int main(){
    int N,M;
    int sum=0;
    scanf("%d",&N);
    scanf("%d",&M);

    int first=0;
    for(int i=N;i<=M;i++){
        if(sqrt(i)==(int)sqrt(i)){
            sum+=i;
            if(first==0)
                first=i;
        }
    }
    if(first!=0){
        printf("%d\n",sum);
        printf("%d\n",first);
    }else{
        printf("-1\n");
    }    
    return 0;
}