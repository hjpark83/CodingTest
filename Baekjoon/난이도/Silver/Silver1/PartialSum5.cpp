#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    cin>>row>>col;

    vector<vector<int>> A(row+1,vector<int>(row+1,0));
    vector<vector<int>> D(row+1,vector<int>(row+1,0));

    for(int i=1;i<=row;i++){
        for(int j=1;j<=row;j++){
            cin>>A[i][j];
            D[i][j]=D[i][j-1]+D[i-1][j]-D[i-1][j-1]+A[i][j];
        }
    }
    for(int i=0;i<col;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        int result=D[x2][y2]-D[x1-1][y2]-D[x2][y1-1]+D[x1-1][y1-1];
        cout<<result<<'\n';
    }
    
}