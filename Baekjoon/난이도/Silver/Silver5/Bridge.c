#include <stdio.h>

#define MAX 30

long long int Combi(int n, int r){
    static long long int arr[MAX][MAX];
    for(int i=0;i<=n;i++){
        arr[i][0]=1;
        arr[i][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    return arr[n][r];
}
int main(){
    int count,num1,num2;
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf("%d %d",&num1,&num2);
        printf("%lld\n",Combi(num2,num1));
    }
    return 0;
}