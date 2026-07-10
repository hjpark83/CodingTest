/*문제 : https://www.acmicpc.net/problem/17386
  알고리즘 : 기하학, 선분 교차 판정
  티어 : Gold3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int CCW(long x1, long y1, long x2, long y2, long x3, long y3){
    long result=(x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3);
    if(result>0){
        return 1;
    }else if(result<0){
        return -1;
    }
    return 0;
}

bool isOverlap(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4){
    if(min(x1,x2)<=max(x3,x4) && min(x3,x4)<=max(x1,x2) && min(y1,y2)<=max(y3,y4) && min(y3,y4)<=max(y1,y2)){
        return true;
    }
    return false;
}

bool isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4){
    int abc=CCW(x1,y1,x2,y2,x3,y3);
    int abd=CCW(x1,y1,x2,y2,x4,y4);
    int cda=CCW(x3,y3,x4,y4,x1,y1);
    int cdb=CCW(x3,y3,x4,y4,x2,y2);

    if(abc*abd==0 && cda*cdb==0){
        return isOverlap(x1,y1,x2,y2,x3,y3,x4,y4);
    }else if(abc*abd<=0 && cda*cdb<=0){
        return true;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    bool cross=isCross(x1,y1,x2,y2,x3,y3,x4,y4);

    if(cross)
        cout<<1;
    else
        cout<<0;

    return 0;
}