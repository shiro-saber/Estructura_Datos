#include <cstdlib>
#include <iostream>

using namespace std;

int suma_vector(int j[], int i, int n)
{
    if ( i == n)
    {
        return 0;
    }
    else
    {
        return numeros[i] + suma(numeros, i+1, n);
    }
}

int main()
{
const int N = 10000;

    int numeros[N];

    srand((int) time(NULL));

    for (int i = 0; i < N; ++i)
    {
        numeros[i] = rand() % 5;
    }

    cout << "Suma = " << suma(numeros, 0, N) << endl;

    return 0;

}
