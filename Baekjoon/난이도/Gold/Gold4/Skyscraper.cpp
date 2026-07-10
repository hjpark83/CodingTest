/*
# Question: BJ 1027 (https://www.acmicpc.net/problem/1027)
# Rank: Gold4
# Algorithm: Math, Brute force, Geometry
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 50
using namespace std;

int N, result=0;
vector<int> Building(MAX);
vector<int> Visible(MAX, 0);

void Input(){
    cin>>N;
    Building.resize(N);
    Visible.resize(N);
    for(int i=0; i<N; i++){
        cin>>Building[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    
    for(int i=0; i<N; i++){
        double max_slope = -1e9;
        for(int j=i+1; j<N; j++){
            double slope = (double)(Building[j]-Building[i])/(j-i);
            if(slope>max_slope){
                Visible[i]++;
                Visible[j]++;
                max_slope = slope;
            }
        }
    }
    for(auto a : Visible){
        result = max(result, a);
    }
    cout<<result<<'\n';
    return 0;
}