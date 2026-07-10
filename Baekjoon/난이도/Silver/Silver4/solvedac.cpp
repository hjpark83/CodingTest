#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int result = 0;
double sum=0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> A(N);
    if(N==0){
        cout<<result<<'\n';
        return 0;
    }

    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(), A.begin() + N);
    int diff = round(N * 0.15);

    for (int i=diff; i<N-diff; i++){
        sum+=A[i];
    }

    result=round(sum/(N-diff*2));
    cout<<result<<'\n';
    return 0;
}
