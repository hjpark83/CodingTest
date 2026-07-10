#include <iostream>
#include <vector>
using namespace std;

void Swap(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}

void SelectionSort(vector<int>& A, int N, int K){
    int count=0;

    vector<int> Answer(N);
    for(int i=A.size()-1;i>=1;i--){
        int Max=A[0];
        int index=0;
        for(int j=1;j<=i;j++){
            if(A[j]>Max){
                Max=A[j];
                index=j;
            }
        }
        if(i!=index){
            Swap(A[i],A[index]);
            count++;

            if(count==K){
                for(int i=0;i<N;i++){
                    Answer[i]=A[i];
                }
                break;
            }
        }
    }
    if(count<K){
        cout<<"-1"<<'\n';
        return;
    }
    for(int i=0;i<N;i++){
        cout<<Answer[i]<<" ";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;
    
    vector<int> A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    SelectionSort(A,N,K);
    return 0;
}