#include <iostream>

using namespace std;

int main() {
    //1 2 3       7 8
    //        x   9 0   =  28  14
    //4 5 6       1 2      79  44

    float A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    float B[3][2] = {
        {7, 8},
        {9, 0},
        {1, 2}};

    float **C = new float*[2];
    for (int i = 0; i < 2; ++i) {
        C[i] = new float[2];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    delete[] C;
    return 0;
}
