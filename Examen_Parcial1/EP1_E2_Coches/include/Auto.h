#ifndef AUTO_H
#define AUTO_H

#include <iostream>
#include <string>

using namespace std;

class Auto
{
    virtual ostream& print(ostream& os) const = 0;
    public:
        virtual ~Auto(){}
        friend ostream& operator<<(ostream& os, const Auto& a);
};

#endif // AUTO_H
