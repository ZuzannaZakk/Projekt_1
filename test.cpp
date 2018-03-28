#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "klasy.h"
#include "test.h"
#include "menu.h"
using namespace std;

int TestSet::addWordTest()
{
    ifstream data1("zbior1.txt");
    ifstream data2("zbior2.txt");
    if( !data1 || !data2 )
    {
    cout<<"Blad wczytywania danych z pliku !!!";
    return 0;
    }
    string s;
    while( !data1.eof() )
    {
        data1 >> s;
        a.addWord(s);
    }
    while( !data2.eof() )
    {
        data2 >> s;
        b.addWord(s);
    }
    data1.close();
    data2.close();
    if( a.getsizeofSet() != 54 || b.getsizeofSet() != 19 )
    {
        cout << "Nie udalo sie dodac slow" << endl;
        return 0;
    }
    else return 1;
}

int TestSet::deleteWordTest()
{
    b.deleteWord("jeden");
    if( b.getsizeofSet() != 17 )
    {
        cout << "Nie udalo sie usunac slowa" << endl;
        return 0;
    }
    else return 1;
}
int TestSet::deleteRepeatedTest()
{
    a.deleteRepeated();
    if( a.getsizeofSet() != 1 )
    {
        cout << "Nie udalo sie usunac wszystkich slow ktore sie powtarzaja" << endl;
        return 0;
    }
    else return 1;
}
int TestSet::shortestWordTest()
{
    if( b.shortestWord() != "dwa" )
    {
        cout << "BLAD (znajdowanie najkrotszego slowa)" << endl;
        return 0;
    }
    else return 1;
}
int TestSet::longestWordTest()
{
    if( b.longestWord() != "czternascie" )
    {
        cout << "BLAD (znajdowanie najdluzszego slowa)" << endl;
        return 0;
    }
    else return 1;
}
int TestSet::sumTest()
{
    if( (a+b).getsizeofSet() != 15 )
    {
        cout << "BLAD (suma zbiorow)" << endl;
        return 0;
    }
    else return 1;
}
int TestSet::intersectionTest()
{
    if( (a*b).getsizeofSet() != 1 )
    {
        cout << "BLAD (iloraz zbiorow)" << endl;
        return 0;
    }
    else return 1;
}

void TestSet::testAll()
{
    if( ( addWordTest() && sumTest() ) && intersectionTest() && ( longestWordTest() && shortestWordTest() )
       && ( deleteRepeatedTest() && deleteWordTest() ) ) { cout << "Wszystkie testy zaliczone" << endl; }
}

