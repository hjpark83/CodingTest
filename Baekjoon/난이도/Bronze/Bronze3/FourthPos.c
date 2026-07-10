#include <stdio.h>

typedef struct Point{
    int xpos;
    int ypos;
}Pos;

int main(){
    int numPoint=3;
    Pos points[numPoint];

    for(int i=0;i<numPoint;i++){
        scanf("%d %d",&points[i].xpos,&points[i].ypos);
    }
    Pos p4;
    p4.xpos = points[0].xpos ^ points[1].xpos ^ points[2].xpos;
    p4.ypos = points[0].ypos ^ points[1].ypos ^ points[2].ypos;
    printf("%d %d\n",p4.xpos,p4.ypos);
    return 0;
}