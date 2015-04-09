#include <cstdlib>
#include "LinkedList.h"
#include "Pila.h"

using namespace std;
using namespace vcn;

LinkedList<int> * Union(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i)
        temp->insertBack(a->at(i)->getInfo());
    for (int j = 0; j < b->size(); ++j) {
        bool esta = false;
        for (int k = 0; k < a->size(); ++k) {
            if (a->at(k)->getInfo() == b->at(j)->getInfo())
                esta = true;
        }
        if (!esta)
            temp->insertBack((b->at(j)->getInfo()));
    }

    return temp;
}

LinkedList<int> * Intersection(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i)
        for (int j = 0; j < b->size(); ++j)
            if (a->at(i)->getInfo() == b->at(j)->getInfo())
                temp->insertBack(a->at(i)->getInfo());

    return temp;
}

int main(int argc, char** argv) 
{
    LinkedList<char> *operacion = new LinkedList<char>();
    return 0;
}

