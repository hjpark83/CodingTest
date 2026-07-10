#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a,const void *b){
    int num1=*(int*)a;
    int num2=*(int*)b;

    return num2-num1;
}
int main(){
    char s[10000];
    scanf("%s",s);
    int len=strlen(s);
    int *arr=(int*)malloc(len*sizeof(int));

    for (int i=0;i<len;i++) {
        arr[i]=s[i]-'0';
    }

    qsort(arr,len,sizeof(int),compare);

    for (int i=0;i<len;i++) {
        printf("%d",arr[i]);
    }
    free(arr);
    return 0;
}