#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

/*Construya una función recursiva que convierta un número decimal en un número hexadecimal.*/

using namespace std;

string hexadecimal(int n)
{
    int m;

    if(n==0)
        return "|";

    else
    {

        if(n%16<10)
        {
            m = n/16;
            hexadecimal(m);
            cout << (n % 16);
        }

        else
        {
            switch(n%16)
            {

                case 10:
                    n=n/16;
                    hexadecimal(n);
                    cout<<"A";
                    break;

                case 11:
                    n=n/16;
                    hexadecimal(n);
                    cout<<"B";
                    break;

                case 12:
                    n=n/16;
                    hexadecimal(n);
                    cout<<"C";
                    break;

                case 13:
                    n=n/16;
                    hexadecimal(n);
                    cout<<"D";
                    break;

                case 14:
                    n=n/16;
                    hexadecimal(n);
                    cout<<"E";
                    break;

                case 15:
                    n=n/16;
                    hexadecimal(n);
                    cout<<"F";
                    break;
            }
        }
     return "";
    }
}


int main()
{
    int valor;

    cout << "entre un valor en base 10: ";
    cin >> valor;

    cout << "el valor en hexadecimal es: 0x";
    cout << hexadecimal(valor);

    return 0;
}


