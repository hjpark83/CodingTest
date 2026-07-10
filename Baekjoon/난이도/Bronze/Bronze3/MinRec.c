#include <stdio.h>
#include <math.h>

int main(void){
    int x,y,w,h;
    scanf("%d %d %d %d",&x,&y,&w,&h);
    int diagonal_x=w;
    int diagonal_y=h;

    int min=abs(x-0);
    if(min>abs(diagonal_x-x)){
        min=abs(diagonal_x-x);
    }
    if(min>abs(diagonal_y-y)){
        min=abs(diagonal_y-y);
    }
    if(min>abs(y-0)){
        min=abs(y-0);
    }
    printf("%d\n",min);
    return 0;
}