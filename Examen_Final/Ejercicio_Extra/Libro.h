#pragma once
#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

class Libro
{
    string titulo;
    int nPag;
    double altura;

public:
    Libro() : Libro("", 0, 0.0){}
    Libro(string nTitulo,int nNPag, double nAltura) : titulo(nTitulo), nPag(nNPag), altura(nAltura) {}
    int getAltura();
    string getNombre();
    bool operator >(Libro & libro);
    bool operator <(Libro & libro);
    friend ostream & operator << (ostream & os, Libro & libro);
};