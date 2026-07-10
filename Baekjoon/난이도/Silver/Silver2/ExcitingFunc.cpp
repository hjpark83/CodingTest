#include <iostream>
#include <vector>
using namespace std;

// int w(int a, int b, int c){
//     if(a<=0 || b<=0 || c<=0){
//         return 1;
//     }else if(a>20 || b>20 || c>20){
//         return w(20,20,20);
//     }else if(a<b && b<c){
//         return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
//     }else{
//         return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
//     }
// }
const int MAX_NUM=21;
vector<vector<vector<int>>> memo(MAX_NUM,vector<vector<int>>(MAX_NUM,vector<int>(MAX_NUM,-1)));

int w(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0){
        return 1;
    }else if (a>20 || b>20 || c>20){
        return w(20,20,20);
    }

    if(memo[a][b][c]!=-1){
        return memo[a][b][c];
    }

    if(a<b && b<c){
        memo[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }else{
        memo[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }

    return memo[a][b][c];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1){
            break;
        }
        int answer=w(a,b,c);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<answer<<'\n';
    }
    return 0;
}