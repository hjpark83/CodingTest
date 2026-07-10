#include <stdio.h>

int max=0;
int num[30000];

void calculate(int start, int n, int count){
    if(n<0){
        if (count>max) {
            max=count;
            for(int i=0;i<count;i++){
                num[i]=num[i+start-count-1];
            }
        }
        return;
    }
    num[start-count]=n;
    calculate(start,n-num[start-count],count+1);
}
int main(){ 
    int start;
    scanf("%d",&start);
    
    int maxNum=start-1;
    calculate(start,maxNum,2);

    printf("%d\n",max);
    for(int i=0;i<max;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}