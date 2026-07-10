#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> FailFunc(string pattern){
    int len=pattern.length();
    int j=0;

    vector<int> fail(len,0);

    for(int i=1;i<len;i++){
        while(j>0 && pattern[i]!=pattern[j]){
            j=fail[j-1];
        }
        if(pattern[i]==pattern[j])
            fail[j]=++j;
    }
    return fail;
}
int KMP(string S,string P, vector<int> &fail){
    int j=0;
    for(int i=0;i<S.length();i++){
        while(S[i]!=P[j] && j>0){
            j=fail[--j];
        }
        if(S[i]==P[j]){
            if(++j=P.length()){
                return 1;
            }
        }
    }
    return 0;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    string cmp;
    cin>>str>>cmp;

    vector<int> table=FailFunc(cmp);
    cout<<KMP(str,cmp,table);
    return 0;
}