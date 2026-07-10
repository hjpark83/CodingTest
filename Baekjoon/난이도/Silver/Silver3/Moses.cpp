#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    queue<pair<string,int>> Q;
    string word;
    int x;
    for(int i=0;i<N;i++){
        cin>>word>>x;
        Q.push({word,x});
    }

    while(Q.size()>1){
        pair<string, int> A=Q.front();
        Q.pop();

        int cnt=(A.second-1)%Q.size();

        while(cnt--!=0){
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
    }
    cout<<Q.front().first;
    return 0;
}