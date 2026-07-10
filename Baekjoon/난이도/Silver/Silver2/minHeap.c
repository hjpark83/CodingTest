#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int*)a)-(*(int*)b);
}

typedef struct PriorityQueue *PQ;

struct PriorityQueue{
    int capacity;
    int size;
    int* Element;
};

PQ createQueue(int MaxSize){
    PQ pq=(PQ)malloc(sizeof(struct PriorityQueue));
    if(pq==NULL){
        return NULL;
    }

    pq->capacity=MaxSize;
    pq->size=0;
    pq->Element=(int*)malloc(sizeof(int)*(MaxSize+1));
    if(pq->Element==NULL){
        free(pq);
        return NULL;
    }

    return pq;
}
PQ destroyQueue(PQ pq){
    free(pq->Element);
    free(pq);
}
int isEmpty(PQ pq){
    return pq->size==0;
}
int isFull(PQ pq){
    return pq->size==pq->capacity;
}
void Push(PQ pq, int data){
    if(isFull(pq)){
        return;
    }
    pq->Element[++pq->size]=data;

    int child=pq->size;
    int parent=child/2;
    while(parent>0 && compare(&pq->Element[child],&pq->Element[parent])<0){
        int temp=pq->Element[parent];
        pq->Element[parent]=pq->Element[child];
        pq->Element[child]=temp;

        child=parent;
        parent=child/2;
    }
}
int Pop(PQ pq){
    if(isEmpty(pq)){
        return 0;
    }
    int Top=pq->Element[1];
    pq->Element[1]=pq->Element[pq->size--];

    int parent=1;
    while(1){
        int leftchild=2*parent;
        int rightchild=2*parent+1;
        int smallest=parent;

        if(leftchild<=pq->size && compare(&pq->Element[leftchild],&pq->Element[smallest])<0){
            smallest=leftchild;
        }
        if(rightchild<=pq->size && compare(&pq->Element[rightchild],&pq->Element[smallest])<0){
            smallest=rightchild;
        }
        if(smallest!=parent) {
            int temp=pq->Element[parent];
            pq->Element[parent]=pq->Element[smallest];
            pq->Element[smallest]=temp;

            parent=smallest;
        }else{
            break;
        }
    }
    return Top;
}

int main(void){
    int N;
    scanf("%d",&N);
    PQ pq=createQueue(N);

    for(int i=0;i<N;i++){
        int num;
        scanf("%d",&num);
       
       if(num==0){
            if(!isEmpty(pq)){
                printf("%d\n",Pop(pq));
            }else{
                printf("0\n");
            }
        }else{
            Push(pq,num);
        }
    }
    destroyQueue(pq);
    return 0;
}