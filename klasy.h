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
    void addWord( string s );
    void deleteWord( string s );
    void display();
    void deleteRepeated();
    void shortestWord();
    void longestWord();
    Set operator+( const Set &a );
    Set operator*( const Set &a );
    Set operator-( const Set &a );
};

#endif // klasy_h
