#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int cumulative=0, sum=0;
    string ans;
    for(int i=0;i<N;i++){
        cin>>ans;
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='O'){
                cumulative++;
                sum+=cumulative;
            }else{
                cumulative=0;
            }
        }
        cout<<sum<<endl;
        sum=0, cumulative=0;
    }
}