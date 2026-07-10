/*문제 : https://www.acmicpc.net/problem/17298
  알고리즘 : 자료구조, 스택
  티어 : Gold4
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<int> A(N+1);
    vector<int> B(N+1);
    stack<int> myStack;

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=N-1;i>=0;i--){
        while(!myStack.empty() && myStack.top() <= A[i]){
            myStack.pop();
        }
        if(myStack.empty())
            B[i]=-1;
        else
            B[i]=myStack.top();

        myStack.push(A[i]);
    }
    for(int i=0;i<N;i++){
        cout<<B[i]<<" ";
    }
}