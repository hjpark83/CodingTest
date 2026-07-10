#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string alpha[8]={"c=","c-","dz=","d-","lj","nj","s=","z="};
    string str;
    cin>>str;

    int count=0;
    for(int i=0;i<str.length();){
        bool found=false;
        for(string a:alpha){
            if(str.substr(i,a.length())==a){
                count++;
                i+=a.length();
                found=true;
                break;
            }
            found=false;
        }
        if(!found){
            count++;
            i++;
        }
    }
    cout<<count<<"\n";
    return 0;
}