#include <stdio.h>
#include <stdlib.h>

int main(){
    int count,one,two;
    int* sum;
    scanf("%d",&count);
    sum=(int*)malloc(count*sizeof(int));

    for(int i=0;i<count;i++){
        scanf("%d %d",&one,&two);
        sum[i]=one+two;
    }
    for(int i=0;i<count;i++){
        printf("Case %d: %d\n",i+1,sum[i]);
    }
    free(sum);
    return 0;
}