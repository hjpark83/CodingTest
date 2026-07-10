#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        for(int j=0;j<i;j++){
            printf(" ");
        }
        for(int k=i;k<2*num-i;k++){
            printf("*");
        }
        for(int r=i;r<2*i;r++){
            printf(" ");
        }
        printf("\n");
    }
    for(int i=num-1;i>0;i--){
        for(int j=i;j>0;j--){
            printf(" ");
        }
        for(int k=2*num-i;k>i;k--){
            printf("*");
        }
        for(int r=i;r>0;r--){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}