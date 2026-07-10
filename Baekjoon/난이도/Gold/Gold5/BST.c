/*문제 : https://www.acmicpc.net/problem/5639
  알고리즘 : 그래프, 트리, 재귀
  티어 : Gold5
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    struct Tree* Left;
    struct Tree* Right;

    int data;
}BST;

BST* CreateTree(int newData){
    BST* bst=(BST*)malloc(sizeof(BST));
    bst->Left=NULL;
    bst->Right=NULL;
    bst->data=newData;

    return bst;
}
BST* DestroyTree(BST* bst){
    free(bst);
}
void BST_PrintPostOrder(BST* bst){
    if(bst==NULL)
        return;
    BST_PrintPostOrder(bst->Left);
    BST_PrintPostOrder(bst->Right);
    printf("%d\n",bst->data);
}
BST* BST_Insert(BST* bst, int data){
    if(bst==NULL){
        bst=CreateTree(data);
        return bst;
    }else if(data<bst->data){
        bst->Left=BST_Insert(bst->Left,data);
    }else if(data>bst->data){
        bst->Right=BST_Insert(bst->Right,data);
    }
    return bst;
}
int main(void){
    int N;
    BST* bst=NULL;
    while(scanf("%d",&N)!=EOF){
        bst=BST_Insert(bst,N);
    }
    BST_PrintPostOrder(bst);
    DestroyTree(bst);
    return 0;
}