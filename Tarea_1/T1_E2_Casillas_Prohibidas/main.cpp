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

const int MazeHeight = 9;
const int MazeWidth = 9;

char Maze[MazeHeight][MazeWidth + 1] =
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

const char Wall = '#';
const char Free = ' ';
const char SomeDude = '*';

class COORD
{
public:
	int X;
	int Y;
	COORD(int x = 0, int y = 0) { X = x, Y = y; }
	COORD(const COORD &coord) { X = coord.X; Y = coord.Y; }
};

COORD StartingPoint(1, 0);
COORD EndingPoint(7, 8);

void PrintDaMaze()
{
	for (int Y = 0; Y < MazeHeight; Y++)
	{
		printf("%s\n", Maze[Y]);
	}
	printf("\n");
}

bool Solve(int X, int Y)
{
	// Make the move (if it's wrong, we will backtrack later.
	Maze[Y][X] = SomeDude;

	// If you want progressive update, uncomment these lines...
	//PrintDaMaze();
	//Sleep(50);

	// Check if we have reached our goal.
	if (X == EndingPoint.X && Y == EndingPoint.Y)
	{
		return true;
	}

	// Recursively search for our goal.
	if (X > 0 && Maze[Y][X - 1] == Free && Solve(X - 1, Y))
	{
		return true;
	}
	if (X < MazeWidth && Maze[Y][X + 1] == Free && Solve(X + 1, Y))
	{
		return true;
	}
	if (Y > 0 && Maze[Y - 1][X] == Free && Solve(X, Y - 1))
	{
		return true;
	}
	if (Y < MazeHeight && Maze[Y + 1][X] == Free && Solve(X, Y + 1))
	{
		return true;
	}

	// Otherwise we need to backtrack and find another solution.
	Maze[Y][X] = Free;

	// If you want progressive update, uncomment these lines...
	//PrintDaMaze();
	//Sleep(50);
	return false;
}

int main()
{
	if (Solve(StartingPoint.X, StartingPoint.Y))
	{
		PrintDaMaze();
	}
	else
	{
		printf("Damn\n");
	}

	//system("PAUSE");

	return 0;
}
