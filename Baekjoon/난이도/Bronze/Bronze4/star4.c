#include <stdio.h>

int main(void){
    int num;
    scanf("%d",&num);
    for(int i=num;i>0;i--){
        for(int j=0;j<num-i;j++){
            printf(" ");
        }
        for(int k=0;k<i;k++){
            printf("*");
        }
        printf(" ");
        printf("\n");
    }
    return 0;
}