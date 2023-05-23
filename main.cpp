#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Gauss_AVX.h"
#include "Gauss_serial.h"
#include "helper_utils.h"
#define N 2000
using namespace std;

float m[N][N];
float temp_m[N][N];

int main() {
    // 简单示例
//    int n = 9;
//    random_matrix(n, m);
//    cp_matrix(m, temp_m);
//    cout<<"进行串行高斯消去..."<<endl;
////    Gauss_serial(n, temp_m);
////    Gauss_AVX_unaligned(n, temp_m);
////    Gauss_AVX_unaligned1(n, temp_m);
////    Gauss_AVX_unaligned2(n, temp_m);
    clock_t start, finish;
    long counter;
    float seconds;
    for(int n=100; n<=1500; n+=100) { // n:问题规模
        random_matrix(n, m);

        cp_matrix(m, temp_m);
        start = clock();
        counter = 0;
        while(clock() - start < 10000) {
            counter++;
            cp_matrix(m, temp_m);
//            Gauss_serial(n, temp_m);
            Gauss_AVX_unaligned(n, temp_m);
//            Gauss_AVX_unaligned1(n, temp_m);
//            Gauss_AVX_unaligned2(n, temp_m);
        }
        finish = clock();
        seconds = ( finish - start) / float(CLOCKS_PER_SEC);
        cout << n << ' ' << counter << ' ' << seconds  << ' ' << seconds / counter << endl;
    }

    return 0;
}
