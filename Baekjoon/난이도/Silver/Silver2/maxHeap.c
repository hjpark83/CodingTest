#include <stdio.h>
#include <stdlib.h>

typedef struct Priority_Queue *PQ;
struct Priority_Queue {
    int capacity;
    int size;
    int *Element;
};

PQ CreatePQ(int MaxSize) {
    PQ pq = (PQ)malloc(sizeof(struct Priority_Queue));
    if (pq == NULL) {
        return NULL;
    }
    pq->size = 0;
    pq->capacity = MaxSize;
    pq->Element = (int*)malloc(sizeof(int) * (MaxSize + 1));
    if (pq->Element == NULL) {
        free(pq);
        return NULL;
    }
    return pq;
}

int isEmpty(PQ pq) {
    return pq->size == 0;
}

int isFull(PQ pq) {
    return pq->size == pq->capacity;
}

void Push(PQ pq, int value) {
    if (isFull(pq)) {
        return;
    }
    pq->Element[++pq->size] = value;

    int child = pq->size;
    int parent = child / 2;
    while (parent > 0 && pq->Element[parent] < pq->Element[child]) {
        int temp = pq->Element[parent];
        pq->Element[parent] = pq->Element[child];
        pq->Element[child] = temp;

        child = parent;
        parent = child / 2;
    }
}

int Pop(PQ pq) {
    if (isEmpty(pq)) {
        return 0;
    }
    int top = pq->Element[1];
    pq->Element[1] = pq->Element[pq->size--];

    int parent = 1;
    while (1) {
        int leftchild = 2 * parent;
        int rightchild = 2 * parent + 1;
        int largest = parent;

        if (leftchild <= pq->size && pq->Element[leftchild] > pq->Element[largest]) {
            largest = leftchild;
        }
        if (rightchild <= pq->size && pq->Element[rightchild] > pq->Element[largest]) {
            largest = rightchild;
        }
        if (largest != parent) {
            int temp = pq->Element[parent];
            pq->Element[parent] = pq->Element[largest];
            pq->Element[largest] = temp;

            parent = largest;
        } else {
            break;
        }
    }
    return top;
}

void freePQ(PQ pq) {
    free(pq->Element);
    free(pq);
}

int main(void) {
    int N;
    scanf("%d", &N);
    PQ pq = CreatePQ(N);

    int num;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (num == 0) {
            if (!isEmpty(pq)) {
                printf("%d\n", Pop(pq));
            } else {
                printf("0\n");
            }
        } else {
            Push(pq, num);
        }
    }
    freePQ(pq);
    return 0;
}
