#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    set<string> A;
    set<string> B;

    for(int i=0;i<N;i++){
        string name;
        cin>>name;
        A.insert(name);
    }
    for(int i=0;i<M;i++){
        string name;
        cin>>name;
        B.insert(name);
    }

    vector<string> Member;

    for(const string& person:A){
        if(B.find(person)!=B.end()){
            Member.push_back(person);
        }
    }
    cout<<Member.size()<<'\n';
    for(int i=0;i<Member.size();i++){
        cout<<Member[i]<<'\n';
    }
    return 0;
}