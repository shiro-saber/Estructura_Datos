#ifndef LinkedList_LinkedList_h
#define LinkedList_LinkedList_h

#include "Node.h"

namespace vcn 
{
    template <class T>
    class LinkedList 
    {
        Node<T> * _first = nullptr;
        int _size = 0;
        
        class Iterator 
        {
            LinkedList<T> * _data;
            int _position;    
        public:
            Iterator(LinkedList<T> * _adata, int _aposition) : _data(_adata), _position(_aposition) {}
            
            Node<T> operator *() const { return *(_data->at(_position)); }
            const  Iterator & operator ++() { ++_position; return *this; }
            bool operator != (const Iterator & it) const { return _position != it._position; }
        };
    
    public:
        LinkedList() {}
        virtual ~LinkedList();
        
        Node<T> * first();
        int size();
        bool empty();
        
        void insert(T, int);
        void insert(Node<T> *, int);
        void insertFront(T); //inserta antes del primero
        void insertFront(Node<T> *);
        void insertBack(T); //inserta despues de el ultimo
        void insertBack(Node<T> *);
        
        Node<T> * remove(int);
        Node<T> *  removeFront(); //siempre quita el primero
        Node<T> *  removeBack(); //siempre quita el ultimo
        
        void clear(); //quita todo de la lista
        
        Node<T> *  at(int); //donde quieres meterlo
        int at(Node<T> *); //en que posicion esta?
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, LinkedList<Tn> &);
        
        Iterator begin() { return { this, 0}; } //si el return sabe que regresa un iterado, crea una nueva instancia pasando los valores
        Iterator end() {return {this, _size }; }
        
        Node<T> * operator [](const int); //con esto podemos tratar la lista como un arreglo.
        bool search(T); //Busqueda en la lista
        
    };
    
    template  <class T>
    LinkedList<T>::~LinkedList()
    {
        clear();
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::first()
    {
        return _first;
    }
    
    template  <class T>
    int LinkedList<T>::size()
    {
        return _size;
    }
    
    template  <class T>
    bool LinkedList<T>::empty()
    {
        return _size == 0;
    }
    
    /*si posicion < 0 se inserta al inicio
     * si posicion > _size se inserta al final
     * en cualquier otro caso, se inserta en la posicion dada
    */
    template  <class T>
    void LinkedList<T>::insert(T element, int position)
    {   
        Node<T> * newnode = new Node<T>(element);//crea el nuevo nodo
        insert(newnode, position);
    }
    
    template  <class T>
    void LinkedList<T>::insert(Node<T> * newnode, int position) //la unica diferencia es que ya tenemos el nodo
    {
        /*Cuando la lista esta vacia o position < 0*/
        if(empty() || position <= 0)
        {
            newnode->setNext(_first); 
            _first = newnode;
        }
        //cuando se inserta en cualquier posicion
        else
        {
            if(position > _size) { position = _size; }
            
            Node<T> * tmp = at(position-1);//siempre debes tener uno atras
            newnode->setNext(tmp->getNext()); //el nevo va a estar en el siguiente
            tmp->setNext(newnode); // el temporal pone el nuevo nodo en el siguiente
        }
        
        /*Incrementar el tamaño de la lista*/
        ++_size;
    }
    
    template  <class T>
    void LinkedList<T>::insertFront(T element)
    {
        insert(element, 0);
    }
    
    template  <class T>
    void LinkedList<T>::insertFront(Node<T> * node)
    {
        insert(node, 0);
    }
    
    template  <class T>
    void LinkedList<T>::insertBack(T element)
    {
        insert(element, _size);
    }
    
    template  <class T>
    void LinkedList<T>::insertBack(Node<T> * node)
    {
        insert(node, _size);
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::remove(int position)//vamos a obtener el de adelante, para poder enlazarlo en el siguiente
    {
        if(empty() || (position < 0 || position >= _size)){ return nullptr;/*si esta vacia regresa un nulo*/ }
        
        Node <T> * removenode;
        //caso primer elemento
        if(position == 0)
        {
            removenode = _first;
            _first = _first->getNext();
        }
        //cualquier otro nodo
        else
        {
            Node<T> * anterior = at(position-1);//no es el que quieres quitar
            removenode = anterior->getNext();
            anterior->setNext(removenode->getNext());//con esto ya puedes borrar
        }
        
        /*Para evitar que se quede apuntando a otra cosa*/
        removenode->setNext(nullptr);
        
        /*Decerementar tamaño*/
        --_size;
        
        return removenode;
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::removeFront()
    {
        return remove(0);
    }
    
    template  <class T>
    Node<T> *  LinkedList<T>::removeBack()
    {
        return remove(_size - 1);
    }
    
    template  <class T>
    void LinkedList<T>::clear()
    {
        Node<T> * tmp = _first;
        while (tmp != nullptr)
        {
            _first = _first->getNext();//pone el apuntador al siguiente, aqui ya puedes eliminarlo
            delete tmp;
            tmp = _first; //guardas el nuevo valor
        }
        
        _size = 0;//regresamos la lista a 0
        _first = nullptr;//regresas todos los valores a nulos
    }
  
    template  <class T>
    Node<T> *  LinkedList<T>::at(int position)
    {
        if(empty() || (position < 0 || position >= _size))
        {
            return nullptr;//si esta vacia regresa un nulo
        }
        
        int pos = 0;//necesitamos saber en que posicion esta.
        Node<T> *tmp = _first; //para tener el valor temporalmente
        
        while(tmp != nullptr && pos++ < position)//si tmp tiene valor y no es el que buscamos, buscamos al siguiente
        {
            tmp = tmp->getNext(); //si cumple las condiciones busca en el siguiente
        }
        
        return tmp; //si lo encontramos regresamos el valor
    }
    
    template  <class T>
    int LinkedList<T>::at(Node<T> * node)
    {
        if(empty() || node == nullptr)
        {
            return -1;//si no esta el nodo, regresamos -1 que es no esta en la lista
        }
        
        int pos = 0;//necesitamos saber en que posicion esta.
        Node<T> *tmp = _first; //para tener el valor del nodo temporalmente
        
        while(tmp != nullptr && tmp != node)//aqui comparamos por nodos, asi que comparamos el nodo en temp con el que te piden  
        {
            tmp = tmp->getNext(); //si cumple las condiciones busca en el siguiente
            ++pos;
        }
        
        if(pos == _size)
            return -1; // si no lo encontramos en toda la lista te dice no esta
        
        return pos; //si lo encontramos regresamos el valor
    }
    
    template <class T>
    std::ostream & operator <<(std::ostream & os, LinkedList<T> & list)
    {
        for (auto node : list )
        {
            os << node << std::endl;
        }
        
        return os;
    }
    
    template  <class T>
    Node<T> * LinkedList<T>::operator [](const int position)
    {
        return at(position);
    }
    
    template  <class T>
    bool LinkedList<T>::search(T element)
    {
        bool exist = false; //para comprobar si esta o no
        Node<T> * tmp = _first; //referencia al primer
        while (tmp != nullptr && !exist) //mientras el nodo no sea nulo t siga sin encontrarse
        {
            exist = tmp->getInfo() == element; //entonces comparamos la informacion del nodo con lo que buscamos, si se cumple exist cambia
            tmp = tmp->getNext(); //Cambiamos al siguiente para seguir las comparaciones
        }
        return exist; //regresa true si lo encuentra y false si no
    }
}

#endif