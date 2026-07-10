#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define MAX 100001
using namespace std;

int N,M;
vector<int> A(MAX);
deque<int> Q;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(A[i]==0){
            Q.push_back(x);
        }
    }

    cin>>M;
    for(int i=0;i<M;i++){
        int y;
        cin>>y;
        Q.push_front(y);
        cout<<Q.back()<<" ";
        Q.pop_back();
    }
    return 0;
}