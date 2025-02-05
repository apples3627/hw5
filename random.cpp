#include<iostream>
#include <fstream>
#include <cmath> 
#include <cstdlib>
using namespace std;
float factorial(int n) { 
    if(n == 0 | n == 1) return 1; 
    else return n * factorial(n - 1); 
    }
int main() {
	float p,*biex, *bitheory;
	int n, k, N = 100000, count; //실험 횟수
	n = 20;  p = 0.5;//던지는 횟수
	biex = new float[n+1]; //실험
	bitheory = new float[n+1]; //이론
	for (k = 0; k <= n; k++) biex[k] = 0;
	for (int nn = 0; nn < N; nn++) {
		count = 0;
		for (int j = 0; j < n; j++) if ((rand() / (float)RAND_MAX) < p) count++;
		biex[count]++;
	} 
	for (int k = 0; k <= n; k++) biex[k] /= (float)N; 
	ofstream xxx("0.5N10000n20.txt");
	for (int k = 0; k <= n; k++) {
		bitheory[k] = factorial(n) / factorial(k) / factorial(n - k) * pow(p, k) * pow((1-p), n - k);
		xxx << k << "\t" << bitheory[k] << "\t" << biex[k] << endl;
	}
    if (!xxx) {
        cout << "can't open" << endl;
        return 1;
    }

	xxx.close();
    delete[] biex; 
    delete[] bitheory; 
	return rand(); //return random 확인
}