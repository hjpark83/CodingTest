#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N);
    stack<int> S;

    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    int sum=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            if(!S.empty())
                S.pop();
        }else{
            S.push(A[i]);
        }
    }
    while(!S.empty()){
        sum+=S.top();
        S.pop();
    }
    cout<<sum<<'\n';
    return 0;
}