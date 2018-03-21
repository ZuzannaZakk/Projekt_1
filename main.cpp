#include <iostream>
#include <string>
#include <vector>
#include "klasy.h"
using namespace std;

int main ( )
{
    Set a, b;
    cout << "Zbior a" << endl;
    a.createSet();
    a.shortestWord();
    a.longestWord();
    cout << "Zbior b" << endl;
    b.createSet();
    b.shortestWord();
    b.longestWord();
    cout << "Dzialania na zbiorach" << endl;
    cout << "Suma : ";
    (a+b).display();
    cout << "Iloczyn : ";
    (a*b).display();
    cout << "Roznica a\\b: ";
    (a-b).display();
    cout << "Roznica b\\a: ";
    (b-a).display();

    return 0;
}
