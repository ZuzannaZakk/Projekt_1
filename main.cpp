#include <iostream>
#include <string>
#include <vector>
#include "klasy.h"
using namespace std;

int main ( )
{
    Set a, b;
    a.createSet();
    b.createSet();

    cout << "Suma : ";
    (a+b).display();
    cout << "Iloczyn : ";
    (a*b).display();
    //a.deleteRepeated();
    a.display();
    b.display();

    return 0;
}
