#include <stdio.h>
#include <string.h>
int main(){
    char S[100];
    scanf("%s",&S);
    int len=strlen(S);

    int position[26];
    for(int i=0;i<26;i++){
        position[i]=-1;
    }
    for(int i=0;i<len;i++){
        int index=S[i]-'a';
        if(position[index]==-1){
            position[index]=i;
        }
    }
    for(int i=0;i<26;i++){
        printf("%d ",position[i]);
    }
    return 0;
}