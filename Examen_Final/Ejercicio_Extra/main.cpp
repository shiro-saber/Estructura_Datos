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

int kuz(int N, int M, int K);
LinkedList<Libro> *libros = new LinkedList<Libro>();

int main(int argc, char** argv) 
{    
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
    
    libros->insertBack(uno);
    libros->insertBack(dos);
    libros->insertBack(tres);
    libros->insertBack(cuatro);
    libros->insertBack(cinco);
    libros->insertBack(seis);
    libros->insertBack(siete);
    libros->insertBack(ocho);
    libros->insertBack(nueve);
    libros->insertBack(diez);

    cout << kuz(3,10,4) << endl;
    
    return 0;
}

int kuz(int N, int M, int K){
  int prol = 0;
  string rep = "";
  int cont = 0;
  for(int i = 0; i < K; ++i){
    if(cont >= M){
      break;
    }
    cont ++;
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    if(i+1 >= K){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());
    //cout << prolijidad;

  }
  rep+= "\n";

  for(int i = K; i < K*2 ; ++i ){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*2 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }
  rep+= "\n";

  for(int i = K*2; i < K*3 ; ++i ){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*3 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }

  for(int i = K*3; i < K*4; ++i){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*4 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }
  rep+= "\n";

  for(int i = K*4; i < K*5 ; ++i ){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*5 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }
  rep+= "\n";

  for(int i = K*6; i < K*7 ; ++i ){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*6 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }


  for(int i = K; i < K*27; ++i ){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*7 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }
  rep+= "\n";

  for(int i = K*8; i < K*3 ; ++i ){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*8 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }

  for(int i = K*9; i < K*4; ++i){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*9 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }
  rep+= "\n";

  for(int i = K*10; i < K*5 ; ++i ){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*10 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }
  rep+= "\n";

  for(int i = K*11; i < K*7 ; ++i ){
    if(cont >= M){
      break;
    }
    rep += libros->at(i)->getInfo().getNombre() + "  ";
    cont ++;
    if(i+1 >= K*12 || i+1 >= M){
      break;
    }
    prol += (libros->at(i+1)->getInfo().getAltura() - libros->at(i)->getInfo().getAltura());

  }
  cout << rep << endl;;

  return prol;
}


