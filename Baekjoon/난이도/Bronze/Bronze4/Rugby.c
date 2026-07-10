#include <stdio.h>
#include <string.h>

int main(){
    while(1){
        char name[10];
        int age, weight;
        scanf("%s %d %d",name,&age,&weight);
        if(strcmp(name,"#")==0||age==0||weight==0){
            break;
        }
        if(age>17||weight>=80){
            printf("%s Senior\n",name);
            continue;
        }else{
            printf("%s Junior\n",name);
        }
    }
    return 0;
}