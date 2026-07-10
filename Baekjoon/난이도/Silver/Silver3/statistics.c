#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b){
    int first=*(int*)a;
    int last=*(int*)b;

    return first-last;
}
int Avg(int arr[],int num){
    double sum=0;
    for(int i=0;i<num;i++){
        sum+=arr[i];
    }
    return round(sum/num);
}
int median(int arr[],int num){
    if(num==1)
        return arr[0];
    else    
        return arr[(num+1)/2-1];
}
int mode(int arr[],int num){ //arr -> 정수 배열
    int list[8001]={0}; // 요소의 빈도수 저장
    int maxFreq=0; // 최빈값의 빈도수
    int mode=0; // 최빈값
    int secondMode=0; //두번째로 빈도가 높은 빈도값
    int count=0; // 최빈값의 빈도수
    int index=0; // secondMode를 계산하기 위한 임시 변수

    for(int i=0;i<num;i++){
        int index=arr[i]+4000; // 범위가 -4000 ~ 4000 이기 때문
        list[index]++; // list를 돌면서 최빈값을 저장

        if(list[index]>maxFreq){
            maxFreq=list[index];
            mode=arr[i];
        } // 최빈값 변경
    }

    for(int i=0;i<8001;i++){
        if(list[i]==maxFreq){
            if(count==0){
                index=i; // count=0이면 index를 현재 index로 저장
                count++;
            }else if(count==1){
                index=i;
                break;
            }
        }
    }
    secondMode=index-4000;
    return secondMode; // 두번째로 높은 빈도 값 반환
}
int range(int arr[],int num){
    int max=arr[num-1];
    int min=arr[0];
    return max-min;
}
int main(){
    int num;
    int* list;

    scanf("%d",&num);
    list=(int*)calloc(num,sizeof(int));

    for(int i=0;i<num;i++){
        scanf("%d",&list[i]);
    }
    qsort(list,num,sizeof(list[0]),compare);

    printf("%d\n",Avg(list,num));
    printf("%d\n",median(list,num));
    printf("%d\n",mode(list,num));
    printf("%d\n",range(list,num));

    free(list);
    return 0;
}