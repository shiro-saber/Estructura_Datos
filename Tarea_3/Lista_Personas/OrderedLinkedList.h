#ifndef ORDEREDLINKEDLIST_H
#define	ORDEREDLINKEDLIST_H

#include "LinkedList.h"

namespace vcn {
    template <class T>
    class OrderedLinkedList : public LinkedList<T> {
    private:
        using LinkedList<T>::insertBack;
        using LinkedList<T>::insertFront;
        // si orden es false es descendente
        // si orden es true es ascendente
        bool orden;

    public:

        OrderedLinkedList(bool _orden) : orden(_orden) {
        }
        void insert(T);

    };

    template<class T>
    void OrderedLinkedList<T>::insert(T element) {
        if (LinkedList<T>::empty()) {
            LinkedList<T>::insert(element, 0);
        } else {
            int i = 0;
            if (orden) {
                while (i < LinkedList<T>::size() && element < LinkedList<T>::at(i)->getInfo()) {
                    ++i;
                }
                LinkedList<T>::insert(element, i);
            } else {
                while (i < LinkedList<T>::size() && element > LinkedList<T>::at(i)->getInfo()) {
                    ++i;
                }
                LinkedList<T>::insert(element, i);
            }
        }
    }
}
#endif	/* ORDEREDLINKEDLIST_H */

