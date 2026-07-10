#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    queue<int> myQueue;
    for(int i=1;i<=N;i++){
        myQueue.push(i);
    }
    while(myQueue.size()>1){
        myQueue.pop();
        myQueue.push(myQueue.front());
        myQueue.pop();
    }
    cout<<myQueue.front()<<'\n';
    return 0;
}