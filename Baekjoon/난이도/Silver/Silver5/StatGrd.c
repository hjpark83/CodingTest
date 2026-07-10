#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 50

int compare(const void* a,const void* b){
    int num1=*(int*)a;
    int num2=*(int*)b;

    return num1-num2;
}
int main(void){
    int count,num;
    int score[MAX_STUDENT];
    scanf("%d",&count);

    for(int i=0;i<count;i++){
        scanf("%d",&num);

        int maxScore=score[0];
        int minScore=score[0];
        int gap=0;

        for(int j=0;j<num;j++){
            scanf("%d",&score[j]);
            if(maxScore<score[j])
                maxScore=score[j];
            if(minScore>score[j])
                minScore=score[j];
        }
        qsort(score,num,sizeof(int),compare);
        for (int k=1;k<num;k++) {
            if(gap<score[k]-score[k-1])
                gap=score[k]-score[k-1];
        }  
        printf("Class %d\n",i+1);
        printf("Max %d, Min %d, Largest gap %d\n",maxScore,minScore,gap);
    }
    return 0;
}