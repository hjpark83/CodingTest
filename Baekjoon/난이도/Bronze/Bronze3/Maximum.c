#include <stdio.h>

int main(){
    int arr[9][9];
    int max=arr[0][0];
    int maxX=0;
    int maxY=0;

    int isMaxInitialized=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&arr[i][j]);
            if(!isMaxInitialized||arr[i][j]>max){
                max=arr[i][j];
                maxX=i+1;
                maxY=j+1;
                isMaxInitialized=1;
            }
        }
    }
    printf("%d\n",max);
    printf("%d %d\n",maxX,maxY);
    return 0;
}