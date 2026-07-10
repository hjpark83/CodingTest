#include <stdio.h>

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(void){
    int arr[3];
    for(int i=0;i<3;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<3;i++){
        for(int j=2;j>i;j--){
            if(arr[j-1]>arr[j])
                swap(&arr[j-1],&arr[j]);
        }
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}