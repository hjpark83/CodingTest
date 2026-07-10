/*문제 : https://www.acmicpc.net/problem/2887
  알고리즘 : 그래프, 최소 스패닝 트리, 정렬
  티어 : Platinum5
*/


#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int parent[100001];
vector<pair<int,int>> v[3];
vector<pair<int,pair<int,int>>> planet;

int find(int x){
    if(parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}

void union_(int x, int y){
    x=find(x);
    y=find(y);

    parent[y]=x;
}

bool sameparent(int x, int y){
    x=find(x);
    y=find(y);

    if(x==y)
        return true;
    else
        return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int x,y,z;
    for(int i=0;i<N;i++){
        cin>>x>>y>>z;
        v[0].push_back(make_pair(x,i));
        v[1].push_back(make_pair(y,i));
        v[2].push_back(make_pair(z,i));
        parent[i]=i;
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    sort(v[2].begin(),v[2].end());

    for (int i=0; i<N-1; i++){
		planet.push_back(make_pair(abs(v[0][i].first-v[0][i+1].first),make_pair(v[0][i].second, v[0][i+1].second)));
		planet.push_back(make_pair(abs(v[1][i].first-v[1][i+1].first),make_pair(v[1][i].second, v[1][i+1].second)));
		planet.push_back(make_pair(abs(v[2][i].first-v[2][i+1].first),make_pair(v[2][i].second, v[2][i+1].second)));
	}

    sort(planet.begin(),planet.end());

    int result=0;
    for(int i=0;i<planet.size();i++){
		if (!sameparent(planet[i].second.first, planet[i].second.second)){
			result+=planet[i].first;
			union_(planet[i].second.first, planet[i].second.second);
		}
	}
    cout<<result<<'\n';
    return 0;
}