#include <iostream>
using namespace std;

int main() {
    int N = 2, M = 3, K = 2; //3x2행렬 x 2x3행렬
    //1 2 3       7 8
    //        x   9 0   =  28  14
    //4 5 6       1 2      79  44

    float A[] = {1, 2, 3, 4, 5, 6};
    float B[] = {7, 8, 9, 0, 1, 2};
    float *C = new float[N * K];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            C[i * K + j] = 0;
            for (int k = 0; k < M; k++) {
                C[i * K + j] += A[i * M + k] * B[k * K + j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << C[i * K + j] << " ";
        }
        cout << endl;
    }
    delete[] C;
    return 0;
}
