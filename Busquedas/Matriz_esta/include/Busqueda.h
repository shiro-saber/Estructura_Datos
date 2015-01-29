#pragma once
#include <iostream>
#define N 100

template <class T>
class Busqueda {
public:
    Busqueda();
    int busquedaSecuencial(T[], T);
    int busquedaOcurrencias(T numeros[], T buscar);
	int busquedaBinaria(T[], T);
	int busquedaBinaria(T[], T, int, int);
};

template <class T>
Busqueda<T>::Busqueda()
{

}

template <class T>
int Busqueda<T>::busquedaSecuencial(T numeros[], T buscar)
{
    int encontrado=-1;
    int i=0;

    while(encontrado==-1 && i<N)
    {
		if(numeros[i]==buscar)
		{
			encontrado=i;
			++i;
		}
    }

    return encontrado;
}

template <class T>
int Busqueda<T>::busquedaOcurrencias(T numeros[], T buscar)
{
    int ocurrencias=0;
    int i=0;
    while (i<N){
        if (numeros[i++]==buscar){
            ocurrencias++;
        }
    }
    return ocurrencias;
}

template <class T>
int Busqueda<T>::busquedaBinaria(T[] numeros, T buscar)
{
	return busquedaBinaria(buscar, 0, N-1);
}

template <class T>
int Busqueda<T>::busquedaBinaria(T[] numeros, T buscar, int inicio, int fin)
{
	if(inicio>0)
	{
		return -1;
	}
	else
	{
		int mitad=(inicio+fin)/2;
		if(buscar==numeros[mitad])
		{
			return mitad;
		}
		else
		{
			if(buscar<numeros[mitad])
			{
				return busquedaBinaria(numeros,buscar,inicio,mitad-1);
			}
			else
			{
				return busquedaBinaria(numeros,buscar,mitad+1, fin);
			}
		}
	}
}
