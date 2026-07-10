#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    cin>>name;
    int N;
    cin>>N;

    vector<int> result;

    int count=0;
    for(int i=0;i<N;i++){
        char alphabet;
        int start, end;
        cin>>alphabet>>start>>end;
        for(int j=start;j<=end;j++){
            if(name[j]==alphabet){
                count++;
            }
        }
        result.push_back(count);
        count=0;
    }
    for(int count:result){
        cout<<count<<'\n';
    }
    return 0;
}