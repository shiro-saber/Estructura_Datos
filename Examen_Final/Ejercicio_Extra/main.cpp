#include <cstdlib>
#include <iostream>
#include "Libro.h"
#include "LinkedList.h"
#include <string>

/* un mueble de N (estantes) x M(libros), K (#libros por estante)
 -ordenalos de forma que M en N sea minima la suma de valores absolutos, de las alturas
 0 < K <=50
 0 < N <=10
 0 < M <= 500
 N < M
 K x N >= M
 0 < altura <= 1000*/

using namespace std;
using namespace vcn;

int main(int argc, char** argv) 
{
    int K = 20; 
    int N = 5; 
    int M = 100;
    int numproj;
    
    
    LinkedList<Libro> *librero = new LinkedList<Libro>();
    

    return 0;
}

