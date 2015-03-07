#include <cstdlib>
#include <iostream>
#include "LinkedList.h"

using namespace std;
using namespace vcn;

/*
    Haga un programa que genere y almacene en una lista enlazada n números primos que se
    encuentren en el rango [p..q] y después los muestre en forma inversa. Los valores de n, p y
    q deben ser definidos por el usuario.
 */

int main(int argc, char** argv) {
    LinkedList<int> * lista1 = new LinkedList<int>();
    LinkedList<int> * lista2 = new LinkedList<int>();
    int inicio = 0;
    int fin = 0;
    int n = 0;
    int resta;
    int con = 0;


    cout << "Dame un numero" << std::endl;
    cin >> inicio;
    cout << "Otro numero" << std::endl;
    cin >> fin;
    cout << "Cuantos numeros quieres imprimir" << std::endl;
    cin >> n;

    resta = fin - inicio;
    while (inicio < fin && con < n) {
        int cont = 0;
        if (inicio == 0) {
            cont = 1;
        } else if (inicio == 1) {
            cont = 1;
        } else {
            for (int j = 2; j < inicio; j++) {
                if (inicio % j == 0) {
                    cont++;
                    break;
                }
            }
        }
        if (cont == 0) {
            lista1->insertFront(inicio);
            con++;
        }
        inicio++;
    }


    cout << *lista1 << endl;
    cout << *lista2 << endl;
    return 0;
}

