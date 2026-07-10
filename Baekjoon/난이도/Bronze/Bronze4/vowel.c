#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char sentence[255];

    while(1){
        scanf("%[^\n]s", sentence);
        getchar();
        if(sentence[0]=='#' && sentence[1]=='\0'){
            break;
        }
        int i=0;
        int count=0;
        while(sentence[i]!='\0'){
            char alpha=tolower(sentence[i]);
            if(alpha=='a'||alpha=='e'||alpha=='i'||alpha=='o'||alpha=='u'){
                count++;
            }
            i++;
        }
        printf("%d\n",count);
    }
    return 0;
}