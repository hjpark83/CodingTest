#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    scanf("%s",str);
    int n=strlen(str);
    int isPalin=1;

    for(int i=0;i<n;i++){
        if(str[i]!=str[n-i-1]){
            isPalin=0;
            break;
        }
    }
    if(isPalin==0){
        printf("0\n");
    }else{
        printf("1\n");
    }
    return 0;
}