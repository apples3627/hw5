#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>

using namespace std;

float GeometricalDistribution(int k, float p) {
    return pow((1 - p), (k - 1)) * p;
}

int main() {
    int k_max = 20; 
    int N = 10000; 

    float *biex = new float[k_max]; 
    float *bitheory = new float[k_max]; 

    for (int i = 0; i < k_max; i++) {
        biex[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        int k = 1;
        while (true) {
            if ((rand() % 6) + 1 == 6) { 
                biex[k - 1]++;
                break; 
            }
            k++; 
            if (k > k_max) break; 
        }
    }

    float p = 1.0 / 6.0; //이론값계산
    for (int i = 0; i < k_max; i++) {
        bitheory[i] = GeometricalDistribution(i + 1, p);
    }

    ofstream file("GDk20N10000.txt");
    if (file.is_open()) {
        for (int i = 0; i < k_max; i++) {
            file << i + 1 << "\t" << bitheory[i] << "\t" << biex[i] / N << endl;
        }
        
    }
    if (!file) {
        cout << "can't open" << endl;
        return 1;
    }

    file.close();
    delete[] biex;
    delete[] bitheory;

    return 0;
}
