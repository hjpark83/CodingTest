/*문제 : https://www.acmicpc.net/problem/15922
  알고리즘 : 스위핑
  티어 : Gold5
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int,int>> Point;
    for(int i=0;i<N;i++){
        int x, y;
        cin>>x>>y;
        Point.push_back({x,y});
    }
    sort(Point.begin(),Point.end());

    int answer=0;
    int start=Point[0].first, end=Point[0].second;

    for(int i=1;i<N;i++){
        int x1=Point[i].first, y1=Point[i].second;
        if(end>x1){
            end=max(end,y1);
        }else{
            answer+=end-start;
            start=x1, end=y1;
        }
    }
    answer+=end-start;
    cout<<answer<<'\n';
    return 0;
}