#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char word[1000000];
    scanf("%s",word);
    
    int count[26]={0};
    
    for(int i=0;word[i]!='\0';i++){
        char c=tolower(word[i]);

        if(isalpha(c)){
            int index=c-'a';
            count[index]++;
        }
    }
    int maxCount=0;
    char frequent='?';

    for(int i=0;i<26;i++){
        if(count[i]>maxCount){
            maxCount=count[i];
            frequent='A'+i;
        }else if(count[i]==maxCount){
            frequent='?';
        }
    }
    printf("%c\n",frequent);
    return 0;
}