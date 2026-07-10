#include <stdio.h>

int main(void){
    int angle[3];
    int sum=0;
    for(int i=0;i<3;i++){
        scanf("%d",&angle[i]);
        sum+=angle[i];
    }
    if(angle[0]==60&&angle[1]==60&&angle[2]==60){
        printf("Equilateral\n");
    }else if(sum==180&&(angle[0]==angle[1]||angle[0]==angle[2]||angle[1]==angle[2])){
        printf("Isosceles\n");
    }else if(sum==180&&(angle[0]!=angle[1]!=angle[2])){
        printf("Scalene\n");
    }else{
        printf("Error\n");
    }
    return 0;
}