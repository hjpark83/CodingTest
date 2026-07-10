/*문제 : https://www.acmicpc.net/problem/2220
  알고리즘 : 자료구조, 그리디 알고리즘
  티어 : Platinum 4
*/

#include <iostream>
using namespace std;

int A[100000];
void swap(int a, int b){
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    
    A[1]=1;
    for(int i=2;i<=N;i++){
        A[i]=i;
        swap(i-1,i);

        for(int j=i-1;j>1;j/=2){
            swap(j,j/2);
        }
    }

    for(int i=1;i<=N;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}
