#include <iostream>
#include <string>
#include <vector>
#include "klasy.h"
using namespace std;

int main ( )
{
    string w;
    Set a, b;
    cout << "Zbior a :" << endl;
    for( int i = 0; i < 5; i++ )
    {
        cin >> w;
        a.addWord( w );
    }
    cout << "Zbior b:" << endl;
    for( int i = 0; i < 5; i++ )
    {
        cin >> w;
        b.addWord( w );
    }

    cout << "Suma : ";
    (a+b).display();
    cout << "Iloczyn : ";
    (a*b).display();

    a.shortestWord();
    a.longestWord();
    a.deleteRepeated();
    a.display();

    return 0;
}
