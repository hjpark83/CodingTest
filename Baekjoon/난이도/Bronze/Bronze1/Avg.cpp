#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N);

    int max=0;
    double sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]>=max){
            max=A[i];
        }
    }
    for(int i=0;i<N;i++){
        A[i]=static_cast<int>((static_cast<double>(A[i])/max)*100);
        sum+=A[i];
    }
    double avg=sum/N;
    cout<<avg<<'\n';
    return 0;
}