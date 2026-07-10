#include <iostream>
#include <vector>
using namespace std;

void Calculation(vector<vector<long long>>& MatrixA, vector<vector<long long>>& MatrixB, int N){
    vector<vector<long long>> Matrix(N,vector<long long>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                Matrix[i][j]+=(MatrixA[i][k]%1000)*(MatrixB[k][j]%1000);  
            }
            Matrix[i][j]%=1000;
        }
    }
    MatrixA=Matrix;
}

vector<vector<long long>> pow(vector<vector<long long>>& Matrix, int B) {
    if(B==1){
        return Matrix;
    }
    vector<vector<long long>> temp = pow(Matrix, B/2);
    if(B%2==0){
        vector<vector<long long>> temp2(temp);
        Calculation(temp2, temp2, Matrix.size());
        return temp2;
    }else{
        vector<vector<long long>> temp2(temp);
        Calculation(temp2, temp2, Matrix.size());
        Calculation(temp2, Matrix, Matrix.size());
        return temp2;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,B;
    cin>>N>>B;

    vector<vector<long long>> Matrix(N,vector<long long>(N,1));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Matrix[i][j];
            Matrix[i][j]%=1000;
        }
    }
    
    vector<vector<long long>> result=pow(Matrix,B);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<result[i][j]%1000<<" ";
        }
        cout<<'\n';
    }
    return 0;
}