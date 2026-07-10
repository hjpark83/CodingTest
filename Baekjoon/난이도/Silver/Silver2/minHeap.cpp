#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N);
    priority_queue<int,vector<int>,greater<int>> PQ;

    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==0){
            if(!PQ.empty()){
                cout<<PQ.top()<<'\n';
                PQ.pop();
            }else{
                cout<<"0"<<'\n';
            }
        }else{
            PQ.push(A[i]);
        }
    }
    return 0;
}