#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    
    for(int i=1;i<=N;i++){
        string word, temp, answer; 
        stack<string> S;
        getline(cin,word);
        
        for(int j=0;j<word.length();j++){
            if(S.empty()){
                S.push(string(1,word[i]));
            }else{
                if(word[i]==' '){
                    S.push(temp);
                    S.push(" ");
                }else{
                    temp+=word[i];
                }
            }
            S.push(temp);

            while(!S.empty()){
                answer+=S.top();
                S.pop();
            }
        }
        cout<<"Case #"<<i<<": "<<answer<<"\n";
    }
    return 0;
}