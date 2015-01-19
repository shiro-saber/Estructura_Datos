#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string palin;
int i;
int j;

bool es(string palin, int i, int j){
	if(i!=palin.size()/2){/*tamaño de la palabra*/
		if(palin.at(i)==palin.at(j)){/*principio de palabra=fin de la palabra*/
			/*return es(la palabra en la siguente posicion de i(inicio) y la posicion anterior de j(final))*/
			return es(palin, ++i, --j);
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
	cout<<"Dame la palabra o texto (sin espacios):"<<endl;
	cin>>palin;

	if(es(palin, 0, palin.size()-1)){
		cout<<"Si es palindromo"<<endl;
	}
	else{
		cout<<"No es un palindromo"<<endl;
	}
	return 0;
}
