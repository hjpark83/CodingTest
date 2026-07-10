/*
# Question: BJ 6588 (https://www.acmicpc.net/problem/6588)
# Rank: Silver1
# Algorithm: Eratosthenes, Prime Number, Math
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000000
using namespace std;

int N;
bool isPrime[MAX+1];
vector<int> A(MAX+1, 0);

void Input() {
    
}

void Eratostenes(){
    for(int i=2; i<=MAX; i++)
        isPrime[i] = true;

    for(int i=2; i<=sqrt(MAX); i++){
        if(isPrime[i]){
            for(int j=i*i; j<=MAX; j+=i)
                isPrime[j] = false;
        }
    }
}

int main() {
    fastio
    Input();
    
    Eratostenes();
    while(1){
        cin>>N;
        if(N == 0)
            break;

        for(int i=3; i<=N/2; i++){
            if(isPrime[i] && isPrime[N-i]){
                cout<<N<<" = "<<i<<" + "<<N-i<<"\n";
                break;
            }else{
                if(i == N/2)
                    cout<<"Goldbach's conjecture is wrong.\n";
            }
        }
    }
    return 0;
}