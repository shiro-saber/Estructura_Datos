#include <iostream>
#include <cstdlib>

using namespace std;

#define N 5

/*
Programe un algoritmo recursivo que permita resolver una matriz de N x N con la
siguiente forma (ejemplo para una matriz de 5 x 5 ). EL algoritmo debe funcionar para
cualquier valor de N.
1 1 1 1 1
1 2 2 2 2
1 2 4 4 4
1 2 4 8 8
1 2 4 8 16
*/

int a[N][N]; //la matriz
int cont;    //numero de la posicion
int fil;     //contador de filas
int col;     //contador de columnas

void llena_mat()
{

}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = 1;
            llena_mat();
        }
        //cout << endl;
    }
    system("PAUSE");
    return 0;
}
