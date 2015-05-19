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
    char temp [N][N];
    if(n != 0)
    {
        for (int i = 0; i < 9; ++i)
        {
            if(i == 4) //cada cuadro se imprime el original que debe quedar en medio
                imprimeMatriz(temp);
            char b[N][N];
            for (int k = 0; k < N; k++)
            {
                for (int j = 0; j < N; j++)
                {
                    b[k][j] = c[n]; //se crea la nueva matriz representando los cuadros que se dividen
                }
            }
            imprimeMatriz(b);
            for (int l = 0; l < N; l++)
                for (int m = 0; m < N; m++)
                    temp[l][m] = b[l][m];
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
            a[i][j] = c[0]; //llenamos el cuadro mas grande
	}
    }
    
    fractal (a, n);
    return 0;
}