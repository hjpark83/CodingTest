#include <stdio.h>

int main(void){
    int count,len[3];
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf("%d %d %d",&len[0],&len[1],&len[2]);
        printf("Case #%d: ",i+1);
        if(len[0]+len[1]<=len[2]||len[0]+len[2]<=len[1]||len[1]+len[2]<=len[0]){
            printf("invalid!\n");
        }else if(len[0]==len[1]&&len[0]==len[2]){
            printf("equilateral\n");
        }else if(len[0]==len[1]||len[0]==len[2]||len[1] == len[2]){
            printf("isosceles\n");
        }else{
            printf("scalene\n");
        }
    }
    return 0;
}