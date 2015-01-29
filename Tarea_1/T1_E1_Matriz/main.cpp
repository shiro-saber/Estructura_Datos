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
int acum = 1;//el acumulador
int maxi = 2;//el maximo
int fil;     //contador de filas
int col;     //contador de columnas

void imprimeMatriz(int m[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void llena_mat()
{
	if (fil < N)//recorre filas
	{
		if (col < N)// recorre columnas
		{
			if (col != 0 && fil != 0)// dejar intacta la columna de los 1
			{
				cont = col;
				if (acum < maxi) //vemos que el acumulador sea menor que el acum
				{
					acum *= 2;
					a[fil][col] = acum;
				}
				else
				{
					a[fil][col] = acum;
					if (cont + 1 == N)
						maxi *= 2;
				}
			}
			//cout << a[fil][col];
			col++;
			llena_mat();
		}
		col = 0;
		acum = 1;
		fil++;
		//cout << endl;
		llena_mat();
	}
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = 1;
		}
	}
	llena_mat();
	imprimeMatriz(a);

	return 0;
}
