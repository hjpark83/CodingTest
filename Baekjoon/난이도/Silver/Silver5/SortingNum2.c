#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b){
    int num1=*(int*)a;
    int num2=*(int*)b;

    return num1-num2;
}
int main(){
    int count;
    scanf("%d",&count);
    int* num=(int*)malloc(sizeof(int)*count);
    for(int i=0;i<count;i++){
        scanf("%d",&num[i]);
    }
    qsort(num,count,sizeof(int),compare);  
    for(int i=0;i<count;i++){
        printf("%d\n",num[i]);
    }
    free(num);
    return 0;
}