#include <stdio.h>

int main(void){
    double count;
    double subject[1000]={0,};
    scanf("%lf",&count);
    
    for(int i=0;i<count;i++){
        scanf("%lf",&subject[i]);
    }
    double Max=subject[0];
    double Sum=0;

    for(int i=1;i<count;i++){
        if(subject[i]>Max){
            Max=subject[i];
        }
    }
    for(int i=0;i<count;i++){
        subject[i]=subject[i]/Max*100;
    }
    for(int i=0;i<count;i++){
        Sum+=subject[i];
    }
    printf("%lf",(double)Sum/count);

    return 0;
}