/*문제 : https://www.acmicpc.net/problem/7561
  알고리즘 : 수학, 선형대수
  티어 : Gold4
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<vector<int>> A(3,vector<int>(4,0));
    vector<long long> B;

    double detA1,detA2,detA3,detA,detA1B,detA2B,detA3B;
    for(int t=0;t<N;t++){
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                cin>>A[i][j];
            }
        }
        detA1B=A[0][3]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])-A[0][1]*(A[1][3]*A[2][2]-A[1][2]*A[2][3])
            +A[0][2]*(A[1][3]*A[2][1]-A[1][1]*A[2][3]);
        detA2B=A[0][0]*(A[1][3]*A[2][2]-A[1][2]*A[2][3])-A[0][3]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])
            +A[0][2]*(A[1][0]*A[2][3]-A[1][3]*A[2][0]);
        detA3B=A[0][0]*(A[1][1]*A[2][3]-A[1][3]*A[2][1])-A[0][1]*(A[1][0]*A[2][3]-A[1][3]*A[2][0])
            +A[0][3]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);

        detA1=A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]);
        detA2=A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]);
        detA3=A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);

        detA=detA1-detA2+detA3;

        B.push_back(detA1B);
        B.push_back(detA2B);
        B.push_back(detA3B);
        B.push_back(detA);

        for(int i=0;i<B.size();i++){
            cout<<B[i]<<" ";
        }
        cout<<'\n';

        if(detA==0){
            cout<<"No unique solution\n";
        }else{
            cout<<fixed;
            cout.precision(3);
            cout<<"Unique solution: "<<(abs(detA1B/detA)<0.0005?0.000:detA1B/detA)<<" "
                <<(abs(detA2B/detA)<0.0005?0.000:detA2B/detA)<<" "
                <<(abs(detA3B/detA)<0.0005?0.000:detA3B/detA)<<'\n';}
        if(t!=N-1){
            cout<<'\n';
        }
        B.clear();
    }
}