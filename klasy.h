#include <iostream>
#include <string>
#include <vector>
using namespace std;
#ifndef klasy_h
#define klasy_h

class Set
{
    class Word
    {
        string s;
        public:
            Word( string s );
            string getWord();
    };
vector<Word*> words;
public:
    Set(){};
    ~Set();
    void createSet();
    void addWord( string s );
    void deleteWord();
    void display();
    void deleteRepeated();
    void shortestWord();
    void longestWord();
    Set operator+( const Set &a ); //suma
    Set operator*( const Set &a ); //iloczyn
    Set operator-( const Set &a ); //roznica
};

#endif // klasy_h
