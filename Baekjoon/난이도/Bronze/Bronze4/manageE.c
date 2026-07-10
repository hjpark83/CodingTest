#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int count;
    scanf("%d",&count);
    if(count>10){
        return 0;
    }
    char sentence[count][20];
    for(int i=0;i<count;i++){
        scanf("%s",sentence[i]);
        for(int j=0;j<strlen(sentence[i]);j++){
            sentence[i][j]=tolower(sentence[i][j]); 
        }
        
    }
    for (int i=0;i<count;i++){
        printf("%s\n",sentence[i]);
    }
    return 0;
}