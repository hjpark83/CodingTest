#include <iostream>
#include <cmath>
#include <vector>

#define MAX_NUM 1000001
using namespace std;

long long N, num;
vector<long long> A(MAX_NUM+1,1);
vector<long long> B;

void Eratostenes(){
    for(int i=2;i<=sqrt(MAX_NUM);i++){
        for(int j=i*i;j<=MAX_NUM;j+=i){
            A[j]=0;
        }
    }
    for(int i=2;i<MAX_NUM;i++){
        if(A[i]==1){
            B.push_back(i);
        }
    }
}

long long gcd(long long a, long long b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    Eratostenes();

    long long answer=1;

    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        for(int j=0;j<B.size();j++){
            if(num==B[j])
                answer=lcm(answer,num);
        }
    }

    if(answer==1){
        cout<<"-1"<<'\n';
    }else{
        cout<<answer<<'\n';
    }
    return 0;
}