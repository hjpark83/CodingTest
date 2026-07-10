/*문제 : https://www.acmicpc.net/problem/1918
  알고리즘 : 자료구조, 스택
  티어 : Gold2
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int Capacity;
    int top;
    char* data;
}Stack;

Stack* CreateStack(int X){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->Capacity = X;
    S->top = -1;
    S->data = (char*)malloc(sizeof(char)*X);
    return S;
}

int isEmpty(Stack* S){
    return S->top == -1;
}

int isFull(Stack* S){
    return S->top == S->Capacity-1;
}

void Push(Stack* S, char X){
    S->data[++S->top] = X;
}

char Pop(Stack* S){
    return S->data[S->top--];
}

char Top(Stack* S){
    return S->data[S->top];
}

int prec(char op){
    if(op == '(')
        return -1;
    else if(op == '+' || op == '-')
        return 0;
    else
        return 1;
}

int main(){
    char str[101];
    Stack* S = CreateStack(100);
    scanf("%s", str);
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            // 피연산자는 바로 출력
            printf("%c", str[i]);
        }
        else if(str[i] == '('){
            // '('는 무조건 스택에 넣는다.
            Push(S, str[i]);
        }
        else if(str[i] == ')'){
            while(!isEmpty(S) && Top(S) != '('){
                // '('가 나올 때까지 출력
                printf("%c", Pop(S));
            }
            Pop(S);
        }
        else{
            while(!isEmpty(S) && prec(Top(S)) >= prec(str[i])){ 
                // 스택의 연산자가 더 우선순위가 높으면
                printf("%c", Pop(S));
            }
            Push(S, str[i]);
        }
    }
    while(!isEmpty(S)){ 
        // 스택에 남아있는 연산자들 출력
        printf("%c", Pop(S));
    }
}