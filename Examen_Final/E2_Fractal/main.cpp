//Alfombra de Sierpinski
#include <cstdlib>
#include <iostream>
#define N 4

using namespace std;

char a[N][N];
char c[] = {'+', '*', '-', '.', '='};

void imprimeMatriz(char m[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

int fractal(char a[N][N], int n)
{
    if(n != 0)
    {
        for (int i = 0; i < 9; ++i)
        {
            if(i == 4)
                imprimeMatriz(a);
            char b[N][N];
            for (int k = 0; k < N; k++)
            {
                for (int j = 0; j < N; j++)
                {
                    b[k][j] = c[n];
                }
            }
            imprimeMatriz(b);
        }
        fractal(a, n-1);
    }
}

int main(int argc, char** argv) 
{
    int n = 4;
 
    for (int i = 0; i < N; i++)
    {
	for (int j = 0; j < N; j++)
	{
            a[i][j] = c[0];
	}
    }
    
    fractal (a, n);
    return 0;
}