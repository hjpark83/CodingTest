#include <stdio.h>

int main(void){
    int score,average;
    int sum=0;
    for(int i=0;i<5;i++){
        scanf("%d",&score);
        if(score<40){
            score=40;    
        }
        sum+=score;
    }
    average=sum/5;
    printf("%d\n",average);
    return 0;
}