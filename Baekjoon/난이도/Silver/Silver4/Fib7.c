#include <stdio.h>

typedef unsigned long long ULLONG;

typedef struct tagMatrix2x2{
    ULLONG Data[2][2];
}Matrix2x2;

Matrix2x2 Matrix2x2_Multiply(Matrix2x2 A, Matrix2x2 B){
    Matrix2x2 C;

    C.Data[0][0] = A.Data[0][0] * B.Data[0][0] + A.Data[0][1] * B.Data[1][0];
    C.Data[0][1] = A.Data[0][0] * B.Data[0][1] + A.Data[0][1] * B.Data[1][1];
    C.Data[1][0] = A.Data[1][0] * B.Data[0][0] + A.Data[1][1] * B.Data[1][0];
    C.Data[1][1] = A.Data[1][0] * B.Data[0][1] + A.Data[1][1] * B.Data[1][1];

    return C;
}

Matrix2x2 Matrix2x2_Power(Matrix2x2 A, ULLONG n){
    if(n>1){
        A=Matrix2x2_Power(A,n/2);
        A=Matrix2x2_Multiply(A,A);

        A.Data[0][0] %= 1000000007;
        A.Data[0][1] %= 1000000007;
        A.Data[1][0] %= 1000000007;
        A.Data[1][1] %= 1000000007;

        if(n&1){
            Matrix2x2 B;
            B.Data[0][0]=1;B.Data[0][1]=1;
            B.Data[1][0]=1;B.Data[1][1]=0;
        
            Matrix2x2 temp = Matrix2x2_Multiply(A, B);
            A.Data[0][0] = temp.Data[0][0] % 1000000007;
            A.Data[0][1] = temp.Data[0][1] % 1000000007;
            A.Data[1][0] = temp.Data[1][0] % 1000000007;
            A.Data[1][1] = temp.Data[1][1] % 1000000007;
        }
    }
    return A;
}

ULLONG Fibonacci(ULLONG N){
    Matrix2x2 A;
    A.Data[0][0]=1;A.Data[0][1]=1;
    A.Data[1][0]=1;A.Data[1][1]=0;

    A=Matrix2x2_Power(A,N);

    return A.Data[0][1];
}

int main(void){
    ULLONG num;
    scanf("%llu",&num);

    ULLONG result=Fibonacci(num);

    if(num==0){
        printf("0\n");
    }else{
        printf("%llu\n",result%1000000007);
    }
    return 0;
}