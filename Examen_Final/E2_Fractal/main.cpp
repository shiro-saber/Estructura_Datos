//fractal recursividad
#include <cstdlib>
#include <iostream>
#define N 4

using namespace std;

int a[N][N];

int fractal(int x[N][N])
{
    
}

void imprimeMatriz(int m[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv) 
{


    return 0;
}