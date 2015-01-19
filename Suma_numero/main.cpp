#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>

using namespace std;
int numero;
int resultado;
int i=0;

void sumar(string str){
	string guarda;
	int res;

	guarda=str[i];
	istringstream convert(guarda);
	if(!(convert>>res)){
		res=0;
	}
	resultado+=res;
	i++;
	if(i<str.length()){
		sumar(str);
	}
}

int main(){
	cout<<"Ingresa el numero a invertir"<<endl;
	cin>>numero;

	string numero2;
	int res;

	ostringstream Convert;
	Convert<<numero;
	numero2=Convert.str();
	sumar(numero2);

	cout<<"\nTu resultado es:\n"<<resultado<<endl;
}
