#include <cstdlib>
#include <iostream>
#include <time.h>
#include "Busqueda.h"

#define N 100;

using namespace std;

int main(int argc, const char* argv[]){
	int arreglo[N];
	srand((int) time(NULL));
	int buscar;
	int repite;
	Busqueda<int> *search=new Busqueda<int>();
	repite=search->buscarOcurrencias(arreglo,buscar);

	for(int i=0; i<N; i++)
	{
		arreglo[i]=rand()%100+1;
	}

	cout<<"Entre el numero a buscar entre 1-100"<<endl;
	cin>>buscar;

	if(repite>0){
		cout<<"el numero "<<buscar<<" se encuentra en el arreglo tantas "<<repite<<" veces"<<endl;
	}
	else{
		cout<<"el numero "<<buscar<<" no se encuentra en el arreglo :("<<endl;
	}

	return 0;
}
