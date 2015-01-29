#include <cstdlib>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>

using namespace std;
int numero;
string numero2;
int i=0;
int revertir;
string guarda;

string cambio(int i){
	string atras;
		if(i<(revertir)){
			//atras+=numero2[revertir-1-i];
			guarda+=numero2[revertir-1-i];
			i++;
			cambio(i);
		}
		return guarda;
}

int main(){
	cout<<"Ingresa el numero a invertir"<<endl;
	cin>>numero;

	string resultado;
	int resultado2;

	ostringstream Convert;
	Convert<<numero;
	numero2=Convert.str();
	revertir=numero2.length();
	resultado=cambio(i);
	istringstream convert(guarda);

	if(!(convert>>resultado2)){
		resultado2=0;
	}
	cout<<"\n"<<resultado2<<endl;
}
