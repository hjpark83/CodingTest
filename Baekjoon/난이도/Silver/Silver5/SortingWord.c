#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char str[50];
    int len;
}Str;

int isDuplicate(const Str* word, int size, const char* str){
    for(int i=0;i<size;i++){
        if(strcmp(word[i].str,str)==0){
            return 1;
        }
    }
    return 0;
}
int compare(const void* a, const void* b){
    Str str1=*(Str*)a;
    Str str2=*(Str*)b;
    
    if(str1.len!=str2.len)
        return str1.len-str2.len;
    else
        return strcmp(str1.str,str2.str);
}

int main(){
    int num;
    scanf("%d",&num);
    Str word[num];

    int count=0;
    for(int i=0;i<num;i++){
        scanf("%s",word[i].str);
        word[i].len=strlen(word[i].str);
        if(!isDuplicate(word,i,word[i].str)){
            count++;
        }
    }

    Str only[count];
    int unique=0;
    for(int i=0;i<num;i++){
        if(!isDuplicate(only,unique,word[i].str)){
            strcpy(only[unique].str,word[i].str);
            only[unique].len=word[i].len;
            unique++;
        }
    }

    qsort(only,unique,sizeof(Str),compare);
    for(int i=0;i<count;i++){
        printf("%s\n",only[i].str);
    }
    return 0;
}