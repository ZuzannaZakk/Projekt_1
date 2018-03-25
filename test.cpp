#include <iostream>
#include <string>
#include <vector>
#include "klasy.h"
#include "test.h"
#include "menu.h"
using namespace std;

void TestSet::addWordTest()
{
    Set a;
    a.addWord("TEST");
    if( a.getsizeofSet() == 0 ) cout << "Nie udalo sie dodac slowa" << endl;
}
void TestSet::createSetTest()
{

}
void TestSet::deleteWordTest()
{
    Set a;
    a.addWord("JEDEN");
    a.addWord("DWA");
    a.deleteWord("DWA");
    if( a.getsizeofSet() != 1 ) cout << "Nie udalo sie usunac slowa" << endl;
}
void TestSet::deleteRepeatedTest()
{
    Set a;
    for( int i = 0; i < 10; i++ )
    {
        a.addWord("TEST");
    }
    a.deleteRepeated();
    if( a.getsizeofSet() != 1 ) cout << "Nie udalo sie usunac wszystkich slow ktore sie powtarzaja" << endl;
}
void TestSet::shortestWordTest()
{
    Set a;
    a.addWord("PIERWSZY");
    a.addWord("DRUGI");
    a.addWord("TRZECI");
    a.addWord("CZWARTY");
    if( a.shortestWord() != "DRUGI" ) cout << "BLAD" << endl;
}
void TestSet::longestWordTest()
{
    Set a;
    a.addWord("PIERWSZY");
    a.addWord("DRUGI");
    a.addWord("TRZECI");
    a.addWord("CZWARTY");
    if( a.longestWord() != "PIERWSZY" ) cout << "BLAD" << endl;
}
void TestSet::sumTest()
{

}
void TestSet::intersectionTest()
{

}
void TestSet::differenceTest()
{

}

