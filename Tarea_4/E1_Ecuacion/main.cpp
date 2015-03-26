#include <iostream>
#include <string>
#include "Pila.h"

/*
Programe una aplicaci�n que, dada una expresi�n matem�tica entrada por un usuario, verifique 
si est� balanceada o no. Una expresi�n est� balanceada cuando tiene el mismo n�meros de 
par�ntesis que abren y que cierran correctamente ubicados.
*/

using namespace std;

int main()
{
    string n;
 
    cout << "Ingrese su operacion: " << endl;
    cin >> n; 
    cout << endl;
    
    int m = 0;
    
    Pila<char> * pila1 = new Pila <char>();
    
    for(int i=0; i<n.size(); i++)
	{    
        Nodo<char> * n2 = new Nodo<char>(n.at(i));
        
        pila1->push(n2);     
    }
    
    while(!pila1->empty())
	{
        
        string parent;
        parent = pila1->pop()->getInfo();
        
        if(parent == ")")
        {
            ++m;
        }
        else if(parent == "(")
        {
            --m;
        }
        
    }
    
    if(m == 0)
        cout << "Esta balanceada" << endl;
    else
        cout << "No esta balanceada" << endl;
    
	system("PAUSE");
    return 0;
}
