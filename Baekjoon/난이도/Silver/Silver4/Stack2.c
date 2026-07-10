#include <stdio.h>
#include <stdlib.h>

typedef struct StackRecord *Stack;
struct StackRecord{
    int Capacity;
    int Top;
    int* array;
};

Stack CreateStack(int maxElement){  
    Stack S=(Stack)malloc(sizeof(struct StackRecord));
    if(S==NULL){
        exit(1);
    }
    S->array=(int*)malloc(sizeof(int)*maxElement);
    if(S->array==NULL){
        exit(1);
    }
    S->Capacity=maxElement;
    S->Top=-1;
    return S;
}

int IsEmpty(Stack S){
    return S->Top==-1;
}
int IsFull(Stack S){
    return S->Top==S->Capacity-1;
}

void Push(int x, Stack S){
    if(IsFull(S)){
        return;
    }
    S->array[++S->Top]=x;
}
void Pop(Stack S){
    if(IsEmpty(S)){
        printf("-1\n");
    }else{
        printf("%d\n",S->array[S->Top]);
        S->Top--;
    }
}
int Top(Stack S){
    if(IsEmpty(S)){
        return -1;
    }
    return S->array[S->Top];
}

int main(){
    int x,order;
    scanf("%d",&x);
    Stack stack=CreateStack(x);

    for(int i=0;i<x;i++){
        scanf("%d",&order);
        
        switch(order){
            case 1:
                int element;
                scanf("%d",&element);
                Push(element,stack);
                break;
            case 2:
                Pop(stack);
                break;
            case 3:
                printf("%d\n",stack->Top+1);
                break;
            case 4:
                if(IsEmpty(stack)){
                    printf("1\n");
                }else{
                    printf("0\n");
                }
                break;
            case 5:
                if(!IsEmpty(stack)){
                    printf("%d\n",Top(stack));
                }else{
                    printf("-1\n");
                }
                break;
        }
    }
    free(stack->array);
    free(stack);
    return 0;
}