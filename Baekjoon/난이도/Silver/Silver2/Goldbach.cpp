#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    vector<int> A(MAX+1,1); // 에라토스테네스의 체로 거른 소수 배열
    vector<int> B;
    A[0]=A[1]=0;
    
    for(int i=2;i<=sqrt(MAX);i++){
        if(A[i]==0)
            continue;
        for(int j=i*i;j<=MAX;j+=i){
            A[j]=0;
        }
    }

    while(T--){
        int cnt=0;
        int N;
        cin>>N;
    
        for(int i=2;i<=N;i++){
            if(A[i]==1)
                B.push_back(i);
        }

        int left=0;
        int right=B.size()-1;

        while(left<=right){
            int sum=B[left]+B[right];
            if(sum==N){
                cnt++;
                left++;
                right--;
            }else if(sum<N){
                left++;
            }else{
                right--;
            }
        }
        cout<<cnt<<'\n';
        B.clear();
    }
    return 0;
}