#include <iostream>
#include <vector>
using namespace std;

vector<int> Answer(2);

void Swap(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}

void SelectionSort(vector<int>& A, int K){
    int count=0;

    for(int last=A.size()-1;last>=1;last--){
        int Max=A[0];
        int index=0;
        for(int j=1;j<=last;j++){
            if(A[j]>Max){
                Max=A[j];
                index=j;
            }
        }
        if(last!=index){
            Swap(A[last],A[index]);
            count++;

            if(count==K){ 
                Answer[0]=A[last];
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

    int N,K;
    cin>>N>>K;
    
    vector<int> A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    SelectionSort(A,K);
    return 0;
}