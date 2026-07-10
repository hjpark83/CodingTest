#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;

    while(1){
        cin>>num;
        if(num==0){
            break;
        }

        int count=0;
        vector<int> A(2*num+1,1);

        for(int i=2;i<=sqrt(2*num);i++){
            for(int j=i*i;j<2*num+1;j+=i){
                A[j]=0;
            }
        }
        for(int i=num+1;i<=2*num;i++){
            if(A[i]==1){
                count++;
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}