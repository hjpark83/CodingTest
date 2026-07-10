#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    set<string> S;

    for(int i=0;i<N;i++){
        string name;
        string option;
        cin>>name>>option;
        
        if(option!="enter"&&option!="leave"){
            continue;
        }

        if(option=="enter"){
            S.insert(name);
        }else if(option=="leave" && S.count(name)){
            S.erase(name);
        }
    }
    vector<string> Member;
    
    for(const string& person:S){
        Member.push_back(person);
    }
    sort(Member.begin(),Member.end(),greater<string>());

    for(int i=0;i<Member.size();i++){
        cout<<Member[i]<<'\n';
    }
    return 0;
}