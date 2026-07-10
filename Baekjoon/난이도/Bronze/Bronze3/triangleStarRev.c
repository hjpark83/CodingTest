#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    for(int i=num;i>0;i--){
        for(int j=num-i;j>0;j--){
            printf(" ");
        }
        for(int k=2*i-1;k>0;k--){
            printf("*");
        }
        printf("\n");
    }  
    return 0;
}