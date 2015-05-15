#include <cstdlib>
#include <iostream>
#include "Libro.h"
#include "LinkedList.h"
#include <math.h>
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
    int K = 20; //#libros por estante
    int N = 2; //estantes
    int M = 10; //libros
    int numproj;
    
    
    LinkedList<Libro> *librero = new LinkedList<Libro>();
    Node<Libro> *uno = new Node<Libro>("Harry Potter", 560, 33.5);
    Node<Libro> *dos = new Node<Libro>("El señor de los anillos", 350, 22.5);
    Node<Libro> *tres = new Node<Libro>("El señor de los anillos", 350, 8.5);
    Node<Libro> *cuatro = new Node<Libro>("El señor de los anillos", 350, 13.5);
    Node<Libro> *cinco = new Node<Libro>("El señor de los anillos", 350, 2.5);
    Node<Libro> *seis = new Node<Libro>("El señor de los anillos", 350, 66.5);
    Node<Libro> *siete = new Node<Libro>("El señor de los anillos", 350, 1.5);
    Node<Libro> *ocho = new Node<Libro>("El señor de los anillos", 350, 16.5);
    Node<Libro> *nueve = new Node<Libro>("El señor de los anillos", 350, 29.5);
    Node<Libro> *diez = new Node<Libro>("El señor de los anillos", 350, 38.5);
    
    librero->insertBack(uno);
    librero->insertBack(dos);
    librero->insertBack(tres);
    librero->insertBack(cuatro);
    librero->insertBack(cinco);
    librero->insertBack(seis);
    librero->insertBack(siete);
    librero->insertBack(ocho);
    librero->insertBack(nueve);
    librero->insertBack(diez);
    
    int altotal;
    Node<Libro> *temp;
    
    for (int i = 0; i < librero->size(); i++)
    {
        temp = librero[i];
        if(librero[i] != nullptr)
        {
            if(temp->getInfo()->getAltura() < temp->getInfo()->getAltura())
            {
                altotal += temp->getInfo()->getAltura() - temp->getNext()->getInfo()->getAltura(); //vamos sumando las diferencias de las alturas de los libros
            }
        }
    }

    cout << altotal << endl;
    
    return 0;
}

