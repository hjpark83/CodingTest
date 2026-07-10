#include <iostream>
#include <vector>
using namespace std;

int LCS_LENGTH(const string& X,const string& Y, vector<vector<char>>& b){
    int m=X.length();
    int n=Y.length();

    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }else{
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
    return c[m][n];
}
string LCS(const string& X, const string& Y){
    int m=X.length();
    int n=Y.length();

    vector<vector<char>> b(m + 1, vector<char>(n + 1));
    LCS_LENGTH(X, Y, b);
    
    string result;
    int i=m, j=n;
    while (i > 0 && j > 0) {
        if (b[i][j] == 'd') {
            result = X[i-1] + result;
            i--;
            j--;
        } else if (b[i][j] == 'u') {
            i--;
        } else {
            j--;
        }
    }
    return result;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string X,Y;
    cin>>X>>Y;

    int m = X.length();
    int n = Y.length();

    vector<vector<char>> b(m + 1, vector<char>(n + 1)); // b 배열 생성
    int length=LCS_LENGTH(X,Y,b);
    if(length==0){
        cout<<length<<'\n';
    }else{
        cout<<length<<'\n';
        cout<<LCS(X,Y)<<'\n';
    }
    return 0;
}