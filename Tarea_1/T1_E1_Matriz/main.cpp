#include <iostream>
#include <cstdlib>

using namespace std;

void llena_mat(int a[][])
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (i == 1)
            a[1][j] = 1;
            else
            a[i][j] = i * 2;
        }
    }
}

int main()
{
    int n;

    cout << "Ingresa el tamaño de la matriz:" << endl;
    cin >> n;

    int a [n][n];

    return 0;
}

/*
#include<iostream>
#include<cstdlib>

using namespace std;

int  a[10][10],i,j,s=0;

	crea un cuadro latino
	00001
	00021
	00321
	04321
	54321

int lol;
int nose;
int numero;
int cont;

void cuadroLatino(){
	if(lol<numero){
		if(nose-1<numero-1){
			if(numero-nose-1<=lol){
				cont++;
                a[lol][nose]=cont;
			}
            cout<<a[lol][nose];
            nose++;
            cuadroLatino();
        }
        nose=0;
        lol++;
        cout<<endl;
        cont=0;
        cuadroLatino();
	}
}


int main(){
	cout<<"Dime que tan grande quieres el cuadro latino"<<endl;
    cin>>numero;

	for(i=1; i<numero; i++){
		for(j=1; j<numero; j++){
			a[i][j] =0;
			cuadroLatino();
		}
	}
    return 0;
}
*/
