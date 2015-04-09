#include <cstdlib>
#include <string>
#include "Pila.h"


using namespace std;

string binario(string decimal)
{
    string binario = "";
    int numero = atoi(decimal.c_str());
    Pila<int> *temp = new Pila<int>();
    while(numero != 0)
    {
        Pila->push(numero%2);
        numero = numero/2;
    }
    while(!temp->empty())
    {
        binario.append(std::to_string(temp->pop()->getInfo()));
    }
    
    delete temp;
    return binario;
}

int main(int argc, char** argv) 
{
    string numero;
    cout << "Escribe numero" << endl;
    cin >> numero;
    
    binario(numero);
    return 0;
}

