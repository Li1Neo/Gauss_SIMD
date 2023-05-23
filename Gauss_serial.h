#include<iostream>
#include<iomanip>
#include <windows.h>
#include<stdio.h>
#include<cmath>
#include<malloc.h>
#include"helper_utils.h"
#define N 2000
using namespace std;

void Gauss_serial(int n, float m[N][N]) {
    for (int i=0; i<n; ++i) {
        float t1 = m[i][i];
        for (int j=i; j<n; ++j) { //��j���õ�һ������Ԫ�ر�Ϊ1
            m[i][j] = m[i][j] / t1;
        }
        for (int j=i+1; j<n; ++j) { //�Ե�j+1~n����Ԫ
            float t2 = m[j][i];
            for (int k=i+1; k<n; ++k) {
                m[j][k] = m[j][k] - t2 * m[i][k];
            }
            m[j][i] = 0.0;
        }
//        matrix_print(n, m);
    }
}
