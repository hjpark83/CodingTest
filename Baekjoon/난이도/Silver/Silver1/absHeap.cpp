#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a)==abs(b)){
            if(a>b)
                return a>b;
            else{
                return b<a;
            }   
        }else{
            return abs(a)>abs(b);
        }
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N);
    priority_queue<int,vector<int>,cmp> pq;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==0){
            if(pq.empty()){
                cout<<"0"<<'\n';
            }else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }else{
            pq.push(A[i]);
        }
    }
    return 0;
}