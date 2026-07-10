/*
# Question: BJ7869 (https://www.acmicpc.net/problem/7869)
# Rank: Gold2
# Algorithm: Math, Geometry, Many Conditions
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void Swap(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x1, y1, r1, x2, y2, r2;
    double dist, result, theta1, theta2, S1, S2;
    double PI = 3.14159265358979f;
    
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    cout<<fixed;
    cout.precision(3);

    dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    // 제2코사인 법칙
    // r2를 작은 원으로 만들어 주기
    if(r1<r2){
        Swap(r1,r2);
        Swap(x1,x2);
        Swap(y1,y2);
    }

    // 1. 두 원이 전혀 겹치지 않는 경우
    if(dist >= r1+r2){
        result = 0.000;
    }
    // 2. 한 원이 다른 원에 포함될 경우
    else if(dist+r2 <= r1){
        result = r2 * r2 * PI;
    }
    // 3. 겹치는 영역이 있는 경우
    else{
        theta1 = acos((r1*r1+dist*dist-r2*r2)/(2*r1*dist));
        theta2 = acos((r2*r2+dist*dist-r1*r1)/(2*r2*dist));
        S1 = (r1*r1*theta1)-r1*r1*sin(2*theta1)/2;
        S2 = (r2*r2*theta2)-r2*r2*sin(2*theta2)/2;
        result = S1 + S2;
    }

    cout<<result<<"\n";
    return 0;
}