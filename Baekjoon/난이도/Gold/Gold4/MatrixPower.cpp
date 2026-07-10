/*문제 : https://www.acmicpc.net/problem/5095
  알고리즘 : 수학, 선형대수
  티어 : Gold4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,P;
vector<vector<int>> Mat;

vector<vector<int>> MatMul(vector<vector<int>> A, vector<vector<int>> B, int ModNum){
    vector<vector<int>> Temp(N,vector<int>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                Temp[i][j] += A[i][k]*B[k][j];
                Temp[i][j] %= ModNum;
            }
        }
    }
    return Temp;
}

vector<vector<int>> MatPow(vector<vector<int>> A, int exp, int ModNum){
    int size = A.size();
    vector<vector<int>> result(size,vector<int>(size, 0));

    for(int i=0; i<size; i++){
        result[i][i] = 1; // 단위행렬로 초기화
    }

    while(exp>0){
        if(exp%2==1){
            result = MatMul(result, A, ModNum); // 홀수일때는 단위행렬에 A를 곱해준다.
        }
        A = MatMul(A, A, ModNum); // A를 제곱해준다.
        exp/=2;
    }
    return result;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    while(1){
        cin>>N>>M>>P;
        if (N==0 && M==0 && P==0){
            break;
        }

        Mat.resize(N,vector<int>(N));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>Mat[i][j];
            }
        }

        Mat = MatPow(Mat,P,M);

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<Mat[i][j]<<" ";
            }
            cout<<"\n";
        }
        Mat.clear(); // 다음 테스트케이스를 위해 초기화
        cout<<'\n';
    }
    return 0;
}