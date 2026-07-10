#include <stdio.h>

int main(void){
    char string;
    while(scanf("%c",&string)!=EOF){
        printf("%c",string);
    }
    return 0;
}