#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<int> A;

    for(int i=1;i<=N;i++){
        vector<int> tmp;
        tmp.push_back(N);
        tmp.push_back(i);
        for(int j=1;;j++){
            if(tmp[j-1]<tmp[j]){
                break;
            }
            tmp.push_back(tmp[j-1]-tmp[j]);
        }
        if(tmp.size()>A.size()){
            A=tmp;
        }   
    }
    cout<<A.size()<<'\n';
    for(auto V: A){
        cout<<V<<" ";
    }
    cout<<'\n';
    return 0;
}