#pragma once
#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

class Libro
{
    string titulo;
    int nPag;
    int altura;

public:
    Libro() : Libro("", 0, 0){}
    Libro(string nTitulo,int nNPag, int nAltura) : titulo(nTitulo), nPag(nNPag), altura(nAltura) {}
    bool operator >(Libro & libro);
    bool operator <(Libro & libro);
    friend ostream & operator << (ostream & os, Libro & libro);
};