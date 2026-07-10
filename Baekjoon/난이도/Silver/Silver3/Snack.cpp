#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int N;
const int MAX=1001;
vector<int> A(MAX);
stack<int> S,T;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    A.resize(N);

    int cnt=0;
    int num=1;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    // 간식 받는 줄과 대기 줄 구분
    for(int i=0;i<N;i++){
        if(S.empty() && cnt<N){
            S.push(A[cnt++]);
        }

        while(S.top()!=num && cnt<N){
            S.push(A[cnt++]);
        }

        if(!S.empty() && S.top()==num){
            S.pop();
            num++;
        }else{
            cout<<"Sad"<<'\n';
            return 0;
        }
    }
    cout<<"Nice"<<'\n';
    return 0;
}