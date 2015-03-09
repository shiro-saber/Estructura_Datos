#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <graphics.h>

using namespace std;

int main(int argc, char* argv[]) 
{
    int gd = DETECT,gm,x,y;
    initgraph(&gd,&gm,NULL);
    rectangle(50,70,100,100);
    getch();
    closegraph();

    return 0;
}

