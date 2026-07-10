/*문제 : https://www.acmicpc.net/problem/1377
  알고리즘 : 정렬
  티어 : Gold2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<pair<int, int>> A(N);

    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second=i;
    }

    sort(A.begin(),A.end());

    int maxTime=0;
    for(int i=0;i<N;i++){
        maxTime=max(maxTime,A[i].second-i);
    }

    cout<<maxTime+1<<'\n';
    return 0;
}
