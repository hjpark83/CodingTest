#include <iostream>
using namespace std;

int count1=0,count2=0;
int fib(int n){
    
    if(n==1 or n==2){
        count1++;
        return 1;
    }else{
        return fib(n-1)+fib(n-2);
    }
}
int fibonacci(int n){
    int f[n];
    f[1]=f[2]=1;
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
        count2++;
    }
    return f[n];
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    fib(n);
    fibonacci(n);
    cout<<count1<<" "<<count2<<'\n';
    return 0;
}