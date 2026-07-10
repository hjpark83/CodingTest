#include <stdio.h>
#include <stdlib.h>

int main(){
    int count;
    int* num;
    int* person;
    int* div;
    int* mod;
    scanf("%d",&count);

    num=(int*)malloc(sizeof(int)*count);
    person=(int*)malloc(sizeof(int)*count);
    div=(int*)malloc(sizeof(int)*count);
    mod=(int*)malloc(sizeof(int)*count);

    for(int i=0;i<count;i++){
        scanf("%d %d",&num[i],&person[i]);
        div[i]=num[i]/person[i];
        mod[i]=num[i]%person[i];
    }
    for(int i=0;i<count;i++){
        printf("You get %d piece(s) and your dad gets %d piece(s).\n",div[i],mod[i]);
    }
    free(num);
    free(person);
    free(div);
    free(mod);
    return 0;
}