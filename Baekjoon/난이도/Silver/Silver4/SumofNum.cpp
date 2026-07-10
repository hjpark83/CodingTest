#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    vector<int> A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int count=0;
    int result=0;

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            result+=A[j];
            if(result==M){
                count++;
                result=0;
                break;
            }
        }
        if(result!=0){
            result=0;
        }
    }
    cout<<count<<'\n';
    return 0;
}