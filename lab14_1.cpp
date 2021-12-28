#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]){
    double AV, SD = 0, GM = 1, HM = 0, sum = 0, max = A[0], min = A[0];

    for (int i=0; i<N; ++i){
        sum += A[i];
        SD += pow(A[i], 2);
        GM *= A[i];
        HM += 1/A[i];
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }

    AV = sum / N;
    SD = sqrt((SD/N) - pow(AV, 2));
    GM = pow(GM, 1.0/N);
    HM = N / HM;
    
    B[0] = AV;
    B[1] = SD;
    B[2] = GM;
    B[3] = HM;
    B[4] = max;
    B[5] = min;
}
