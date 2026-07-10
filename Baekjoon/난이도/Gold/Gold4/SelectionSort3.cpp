#include <iostream>
#include <vector>
using namespace std;

vector<int> Answer(2);

void SelectionSort(vector<long long>& A, long long K){
    int count=0;

    for(int i=A.size()-1;i>=1;i--){
        long long Max=A[0];
        long long index=0;
        for(int j=1;j<=i;j++){
            if(A[j]>Max){
                Max=A[j];
                index=j;
            }
        }
        if(i!=index){
            swap(A[i],A[index]);
            count++;

            if(count==K){ 
                Answer[0]=A[i];
                Answer[1]=A[index];
                break;
            }
        }
    }
    if(count<K){
        cout<<"-1"<<'\n';
        return;
    } 
    cout<<Answer[1]<<" "<<Answer[0]<<'\n';
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N,K;
    cin>>N>>K;
    
    vector<long long> A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    SelectionSort(A,K);
    return 0;
}