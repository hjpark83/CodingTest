#include <iostream>
#include <vector>
#include <cmath>

const int MAX_NUM=4000001;
using namespace std;

bool hasDigit(int number, int digit) {
    while(number>0){
        if (number%10==digit){
            return true;
        }
        number/=10;
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A,B,D;
    cin>>A>>B>>D;

    vector<int> Prime(MAX_NUM+1,1);
    Prime[0]=Prime[1]=0;

    for(int i=2;i<=sqrt(MAX_NUM);i++){
        for(int j=i*i;j<=MAX_NUM;j+=i){
            Prime[j]=0;
        }
    }
    
    int count=0;
    for(int i=A;i<=B;i++){
        if(Prime[i]==1 && hasDigit(i,D)){
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}