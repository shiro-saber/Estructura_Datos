#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
Realice un programa que resuelva el problema de un laberinto: Se trata de encontrar un camino
que nos permita salir de un laberinto definido en una matriz N x N. Para movernos por el
laberinto, sólo podemos pasar de una casilla a otra que sea adyacente a la primera y no esté
marcada como una casilla prohibida (esto es, las casillas prohibidas determinan las paredes que
forman el laberinto y pueden marcarse con un número, por ejemplo -1).
Algoritmo:
Se comienza en la casilla (0,0) y se termina en la casilla (n-1,n-1)
Nos movemos a una celda adyacente si esto es posible.
Cuando llegamos a una situación en la que no podemos realizar ningún movimiento que nos
lleve a una celda que no hayamos visitado ya, retrocedemos sobre nuestros pasos y buscamos un
camino alternativo.
*/

//usando el metodo de backtraking
const int columnas = 9;
const int filas = 9;

//Este es el laberinto predefinido
char laberinto[columnas][filas + 1] =
{
	"# #######",
	"#   #   #",
	"# ### # #",
	"# #   # #",
	"# # # ###",
	"#   # # #",
	"# ### # #",
	"#   #   #",
	"####### #",
};

const char pared = '#';
const char reiniciala = ' ';
const char pasamos = '*';

//Para guardar las coordenadas, actualizarlas y saber donde estoy
class coordenadas
{
public:
	int X;
	int Y;
	coordenadas(int x = 0, int y = 0) //establecer las coordenadas donde se pasara, inicia en 0
	{
        X = x,
        Y = y;
    }

	coordenadas(const coordenadas &coord) //Acutalizamos las coordenadas por las actuales
	{
        X = coord.X;
        Y = coord.Y;
	}
};

coordenadas inicio(1, 0); //establecemos el inicio, a lado de la primer pared
coordenadas salida(7, 8); //establecemos donde va a acabar el laberinto

void ve_laberinto()
{
	for (int Y = 0; Y < columnas; Y++)
	{
		printf("%s\n", laberinto[Y]); //imprimimos el laberinto por partes
	}
	printf("\n");
}

bool encuentra(int X, int Y)
{
	// Movemos, si no se puede regresamos a una casilla anterior
	laberinto[Y][X] = pasamos;

	// veamos si ya llegamos al final.
	if (X == salida.X && Y == salida.Y)
	{
		return true;
	}

	//Aqui esta la recursividad, ya que estamos buscando donde esta la meta
	if (X > 0 && laberinto[Y][X - 1] == reiniciala && encuentra(X - 1, Y))
	{
		return true;
	}
	if (X < filas && laberinto[Y][X + 1] == reiniciala && encuentra(X + 1, Y))
	{
		return true;
	}
	if (Y > 0 && laberinto[Y - 1][X] == reiniciala && encuentra(X, Y - 1))
	{
		return true;
	}
	if (Y < columnas && laberinto[Y + 1][X] == reiniciala && encuentra(X, Y + 1))
	{
		return true;
	}

	// Si no hemos llegado, o tomamos otro camino que no era, tenemos que regresar la casilla y hacerla pasable de nuevo
	laberinto[Y][X] = reiniciala;

	return false;
}

int main()
{
	if (encuentra(inicio.X, inicio.Y)) //si lo resolvimos imprimimos el resultado final
	{
		ve_laberinto();
	}
	else //si no el oops es que no lo encontramos o solo no hay solucion
	{
		printf("Ooops!\n");
	}

	return 0;
}
