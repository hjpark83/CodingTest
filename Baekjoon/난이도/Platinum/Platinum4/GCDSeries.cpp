/*
# Question: BJ 14252 (https://www.acmicpc.net/problem/14252)
# Rank: Platinum4
# Algorithm: Math, Sorting, Eucilid Algorithm, Integer
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100001
using namespace std;

int N;
vector<int> arr;

void Input() {
    cin>>N;
    arr.resize(N);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }    
    sort(arr.begin(), arr.end());
}

int GCD(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    fastio
    Input();
    
    int ans = 0;
    for(int i=0; i<N-1; i++){
        if(GCD(arr[i], arr[i+1]) != 1){
            int flag = 0;
            for(int j=arr[i]+1; j<arr[i+1]; j++){
                if(GCD(j, arr[i]) == 1 && GCD(j, arr[i+1]) == 1){
                    flag = 1;
                    break;
                }
            }
            if(flag)
                ans++;
            else
                ans += 2;
        }
    }
    cout<<ans<<'\n';
    return 0;
}