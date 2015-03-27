#ifndef EDITOR_H
#define	EDITOR_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "DoubleCircularLinkedList.h"
#include <string>

using namespace std;
using namespace vcn;

class Editor 
{
    fstream document;
    DoubleCircularLinkedList<vector<string>> *lineas = new DoubleCircularLinkedList<vector<string>>();
    string nombreDocumento = "No hay documento";
    
    void cargaDocumento();
    void muestraDocumento();//imprime
    
    void abreDocumento();
    void guarda();
    void ensenaDocumento();//lo muestra
    void modificaDocumento();
    
    void nuevaLinea();
    void quitaLinea();
    
    void agregaPalabra();
    void quitaPalabra();
public:
    Editor() {}
    void cargaApp();
};

#endif	/* EDITOR_H */

