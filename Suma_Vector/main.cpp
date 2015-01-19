#include <cstdlib>
#include <iostream>

using namespace std;

int suma_vector(int j[], int i, int n)
{
    if(i == n)
    {
        return 0;
    }
    else
    {
        return j[i] + suma(j, i + 1, n);
    }
}

int main()
{

    return 0;
}
