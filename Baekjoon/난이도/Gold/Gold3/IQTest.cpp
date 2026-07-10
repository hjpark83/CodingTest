/*
# Question: BJ (https://www.acmicpc.net/problem/1111)
# Rank: Gold3 
# Algorithm: Math, Implementation, Brute Force, Many Cases
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 101
using namespace std;
typedef long long ll;

int N;
vector<int> Numbers(MAX);

void Input() {
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>Numbers[i];
    }
}

int main() {
    fastio
    Input();
    
    if(N==1){
        cout<<"A"<<'\n';
    }else if(N==2){
        if(Numbers[0]!=Numbers[1]){
            cout<<'A'<<'\n';
        }else{
            cout<<Numbers[0]<<'\n';
        }
    }else{
        if(Numbers[0] == Numbers[1]){
            for(ll i=2; i<N; i++){
                if(Numbers[i] != Numbers[0]){
                    cout<<"B"<<'\n';
                    exit(0);
                }
            }
            cout<<Numbers[0]<<'\n';
        }else{
            if((Numbers[2]-Numbers[1])%(Numbers[1]-Numbers[0]) != 0){
                cout<<"B"<<'\n';
            }else{
                ll a = (Numbers[2]-Numbers[1])/(Numbers[1]-Numbers[0]);
                ll b = Numbers[1]-Numbers[0]*a;

                ll flag = 1;
                for(ll i=3; i<N && flag==1; i++){
                    if(Numbers[i-1]*a+b != Numbers[i]){
                        flag = 0;
                    }
                }

                if(flag == 0)
                    cout<<"B"<<'\n';
                else
                    cout<<Numbers[N-1]*a+b<<'\n';
            }
        }
    }
}