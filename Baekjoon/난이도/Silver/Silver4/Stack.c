#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack *stack;

struct Stack{
    int capacity;
    int TopOfStack;
    int *Array;
};

stack CreateStack(int maxElement){
    stack S=(stack)malloc(sizeof(struct Stack));
    if(S==NULL)
        exit(1);
    S->Array=(int*)malloc(sizeof(int)*maxElement);
    if(S->Array==NULL)
        exit(1);
    S->capacity=maxElement;
    S->TopOfStack=-1;
    return S;
}
int isEmpty(stack S){
    if(S->TopOfStack==-1)
        return 1;
    return 0;
}
int isFull(stack S){
    return S->TopOfStack==S->capacity-1;
}
void Push(int x, stack S){
    if(isFull(S)){
        return;
    }
    S->Array[++S->TopOfStack]=x;
}
int Pop(stack S){
    if(isEmpty(S)){
        return -1;
    }
    return S->Array[S->TopOfStack--];
}
int Top(stack S){
    return S->Array[S->TopOfStack];
}
int main(){
    int N;
    scanf("%d",&N);

    stack S=CreateStack(10000);

    char command[10];
    int x;

    while (N--) {
        scanf("%s", command);
        if (strcmp(command, "push") == 0) {
            scanf("%d", &x);
            Push(x, S);
        } else if (strcmp(command, "pop") == 0) {
            int value=Pop(S);
            printf("%d\n",value);
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", S->TopOfStack + 1);
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", isEmpty(S));
        } else if (strcmp(command, "top") == 0) {
            if(isEmpty(S)){
                printf("-1\n");
            }else{
                printf("%d\n",Top(S));
            }
        }
    }

    free(S->Array);
    free(S);

    return 0;
}