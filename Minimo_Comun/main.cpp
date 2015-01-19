#include <cstdlib>
#include <iostream>

using namespace std;

int mcd(int m, int n)
{
    int r = m % n;
    if(r == 0)
        return r;
    else
        return mcd(n,r);
}

int main()
{
    int v;
    int u;
    cout << "Introduce un número" << endl;
    cin >> v;
    cout << "Introduce un número mayor" << endl;
    cin >> u;

    cout << "MCD(" << v << "," << u << ")= " << mcd(v,u) << endl;

    return 0;
}
