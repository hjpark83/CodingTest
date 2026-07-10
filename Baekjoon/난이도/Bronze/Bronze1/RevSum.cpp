#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string X,Y;
    cin>>X>>Y;

    reverse(X.begin(),X.end());
    reverse(Y.begin(),Y.end());

    int sum=stoi(X)+stoi(Y);
    string result=to_string(sum);

    reverse(result.begin(),result.end());
    cout<<stoi(result)<<endl;
    return 0;
}
