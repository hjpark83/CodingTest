#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A;
    int num;

    while(1){
        cin>>num;
        if(num==-1){
            break;
        }
        for(int i=1;i<num;i++){
            if(num%i==0){
                A.push_back(i);
            }
        }
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
        }
        if(sum==num){
            cout<<num<<" = ";
            for(int j=0;j<A.size();j++){
                cout<<A[j];
                if(j<A.size()-1){
                    cout<<" + ";
                }
            }
            cout<<'\n';
        }else{
            cout<<num<<" is NOT perfect."<<'\n';
        }
        A.clear();
    }
}