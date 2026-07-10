#include <iostream>

using namespace std;

int abs(int n){
    return (n>=0? n:-n);
}

int main(){

    int min=1000-(1+1);
    int n,x,y,result,mina=1,minb=1; 
    cin>>n;
    while(n--){
        cin>>x>>y;
        for(int a=1;a<=100;a++){
            for(int b=1;b<=100;b++){
                result=abs(y-(a*x+b));
                if (result<=min){
                    min=result;
                    mina=a; minb=b;
                }
            }
        }
    }
    cout<<mina<<' '<<minb;

}