#include <cstdlib>
#include <iostream>

using namespace std;

int filas;
int columnas;
int cont;

int move(int filas, int columnas)
{
	int derecha=0;
	int abajo=0;

	if((filas==2 && columnas==1)||(columnas==3 && filas==1))
	{
		return 1;
	}
	else
	{
		if(filas>2)
		{
			abajo=move(filas-2,columnas);
		//	cont++;
		}
		if(columnas>3)
		{
				derecha=move(filas,columnas-3);
			//	cont++;
				return abajo+derecha;
		}
		//return cont;
	}
	//cout<<abajo+derecha<<endl;
}

int main()
{
	cout << "Numero de filas:" << endl;
	cin >> filas;
	cout << "Numero de columnas:" << endl;
	cin >> columnas;

	//cout<<cont<<endl;
	cout << "Los caminos son:" << endl << move(filas,columnas) << endl;
}
