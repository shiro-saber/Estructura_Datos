#include<iostream>
#include<cstdlib>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a[4][4],i,j,s=0;
int resul;
int prueba;
int J = 0;
int I = 0;

void laFuncion()
{
	if(I < 4)
	{
        if(J < 4)
        {
			prueba += a[I][J];
            J++;
            laFuncion();
        }
		J=0;
        I++;
        laFuncion();
	}
}


int main()
{
	srand(time(NULL));// con esto creo el rand

	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			a[i][j] = rand()%564;
			laFuncion();
			cout << "el resultado es: " << prueba;
			/*cout << endl << "LA MATRIZ 2" << endl;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			cout << a[i][j]<<"|";
		}
		cout <<endl;
	}*/
	return 0;
}
