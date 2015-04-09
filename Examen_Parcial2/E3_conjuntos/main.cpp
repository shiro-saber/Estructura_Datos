#include <cstdlib>
#include "LinkedList.h"
#include "Pila.h"
#include "Cola.h"
#include <string>

using namespace std;
using namespace vcn;

bool simbolo(char c)
{
    return (c == '+' || c == '*');
}

void transformar(string aux, Cola<char> &expresion)
{
    Pila<char> operadores;
    LinkedList<int> lista1;
    LinkedList<int> lista2;
    int i = 0;
    char caracter = aux[i];
    
    while (caracter)
    {
        if (caracter >= '0' && caracter <= '9')
        {
            expresion.enqueue(caracter);
        }
        else if (simbolo(caracter))
        {
            while (!operadores.empty())
                expresion.enqueue(operadores.pop()->getInfo());
            operadores.push(caracter);
        }
        else if (caracter == '(')
        {
            operadores.push(caracter);
        }
        else if (caracter == ')')
        {
            while (!operadores.empty() && operadores.top()->getInfo() != '(')
            {
                expresion.enqueue(operadores.pop()->getInfo());
            }
            if (operadores.empty())
            {
                cout << "Entrada incorrecta";
            }
            operadores.pop();
        }
        else if (caracter == '*')
        {
            Node<int> * aux1 = operadores->top();;

            Node<int> * aux2 = expresion->getInicio();

            while(!operadores.empty())
            {
                lista1.insertBack(operadores.pop());
            }
            while(!expresion.empty())
            {
                lista2.insertBack(expresion.dequeue());
            }
            for (Node<int> *aux1 = lista1.first(); aux1; aux1 = aux1->getNext())
            {
                
                for (Node<int> *aux2 = lista2.first(); aux2; aux2 = aux2->getNext())
                {
                    
                    operadores.push(aux1->getInfo() * aux2->getInfo());
                    
                }
                lista1.clear();
                lista2.clear();
                
            }
            
            operadores.pop();
        }
        else if (caracter == '+')
        {
            while(!operadores.empty())
            {
            lista1.insertBack(operadores.pop());
            }
            while(!expresion.empty())
            {
                lista2->insertBack(expresion.dequeue());
            }
                                 
            operadores.pop();
            }
            Node<int> * auxN = operadores->top();;
            while (auxN!=NULL)
                {
                operadores->push(auxN->getInfo);
                auxN = auxN->getNext();
                }
                        
            Node<int> * auxM = expresion->getInicio();
            while(auxM!=NULL)
            {
                operadores->push(auxM->getInfo());
            }
                lista1.clear();
                lista2.clear();
        
        }

        caracter = aux[++i];
}



float verificar(Cola<char> &expresion)
{
    Pila<float> operandos;
    while (!expresion.empty())
    {
        if (expresion->getInicio()->getInfo() >= '0' && expresion->getInicio()->getInfo() <= '9')
        {
            operandos.push(expresion.dequeue()->getInfo() - 48.0);
        }
        if (!expresion.empty() && simbolo(expresion->getInicio()->getInfo()))
        {
            if (operandos.size() < 2)
            {
                cout << "Lo sentimos, no es valida la operacion";
            }
            float o1 = operandos.pop()->getInfo();
            float o2 = operandos.pop()->getInfo();
            
            switch (expresion.dequeue()->getInfo()) {
                case '+':
                    operandos.push(o2 + o1);
                    break;
                case '*':
                    operandos.push(o2 * o1);
                    break;
                default:
                    cout << "Lo sentimos, no es valida la operacion";
                    break;
            }
        }
    }
    if (operandos.size() == 1)
    {
        return operandos.pop()->getInfo();
    }
    else
    {
        cout << "Lo sentimos, no es valida la operacion";
    }
    return 0;
}

int main(int argc, const char * argv[]) 
{
    Cola<char> expresion;
    string operacion;
    
    cout << "ingresa una operacion " << endl;
    cin >> operacion;
    
    transformar(operacion, expresion);
    
    float resultado = verificar(expresion);
    cout << resultado << endl;
}
