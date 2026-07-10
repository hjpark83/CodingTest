#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;
    queue<int> myQueue;

    for(int i=1;i<=N;i++){
        myQueue.push(i);
    }
    cout<<"<";
    while(!myQueue.empty()){
        for(int i=0;i<K-1;i++){
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
        cout<<myQueue.front();
        myQueue.pop();
        if(!myQueue.empty()){
            cout<<", ";
        }
    }
    cout<<">"<<'\n';
    return 0;
}