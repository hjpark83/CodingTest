#include <stdio.h>
#include <string.h>

int main(void){
    int num;
    scanf("%d",&num);

    int repeat;
    char word[20];
    for(int i=0;i<num;i++){
        scanf("%d %s",&repeat,word);
        for(int j=0;j<strlen(word);j++){
            for(int k=0;k<repeat;k++){
                printf("%c",word[j]);
            }
        }
        printf("\n");
    }
    return 0;
}