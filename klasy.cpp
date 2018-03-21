#include <iostream>
#include <string>
#include <vector>
#include "klasy.h"
using namespace std;

    Set::~Set()
    {
        for( size_t i = 0; i < words.size(); i++ )
            delete words[i];
        words.clear();
    }

    void Set::createSet()
    {
        int n;
        string s;
        cout << "Liczba elementow zbioru : ";
        cin >> n;
        cout << "Elementy zbioru :" << endl;
        for( int i = 0; i < n; i++ )
        {
            cin >> s;
            addWord( s );
        }
    }

    void Set::addWord( string s )
    {
        words.push_back( new Word(s) );
    }

    void Set::deleteWord(  )
    {
        string s;
        cout << "Usun : ";
        cin >> s;
        int temp = 1;
        for( size_t i = 0; i < words.size(); i++ )
        {
            if( words[i]->getWord() == s )
            {
                words.erase( words.begin()+i );
                i--;
                temp = 0;
            }
        }
        if( temp ) cout << "Nie ma takiego slowa w zbiorze !!!" << endl;
    }

    void Set::display()
    {
        for( size_t i = 0; i < words.size(); i++ )
            cout << words[i]->getWord() << " ";
        cout << endl;
    }

    void Set::deleteRepeated()
    {
        string temp = words[0]->getWord();
        for( size_t i = 0; i < words.size(); i++ )
        {
            temp = words[i]->getWord();
            for( size_t j = i+1; j < words.size(); j++ )
            {
                if( words[j]->getWord() == temp )
                {
                    words.erase( words.begin()+j );
                    j--;
                }
            }
        }
    }

    void Set::shortestWord()
    {
        string temp = words[0]->getWord();
        for( size_t i = 1; i < words.size(); i++ )
        {
            if( (words[i]->getWord()).length() < temp.length() )
                temp = words[i]->getWord();
        }
        cout << "Najkrotsze slowo w zbiorze : " << temp << endl;
    }

    void Set::longestWord()
    {
        string temp = words[0]->getWord();
        for( size_t i = 1; i < words.size(); i++ )
        {
            if( (words[i]->getWord()).length() > temp.length() )
                temp = words[i]->getWord();
        }
        cout << "Najdluzsze slowo w zbiorze : " << temp << endl;
    }

    string Set::Word::getWord()
    {
        return this->s;
    }

    Set::Word::Word( string s )
    {
        this->s = s;
    }

    Set Set::operator+( const Set &a )
    {
        Set c;
        for( size_t i = 0; i < words.size(); i++ )
        {
            c.addWord( words[i]->getWord() );
        }
        for( size_t i = 0; i < a.words.size(); i++ )
        {
            c.addWord( a.words[i]->getWord() );
        }
        c.deleteRepeated();
        return c;
    }

    Set Set::operator*( const Set &a )
    {
        Set c;
        int temp = 0;
        for( size_t i = 0; i < words.size(); i++ )
        {
            for( size_t j = 0; j < a.words.size(); j++ )
            {
                if( words[i]->getWord() == a.words[j]->getWord() )
                {
                    c.addWord( words[i]->getWord() );
                    temp = 1;
                }
            }
        }
        if( temp )
            c.deleteRepeated();
        return c;
    }

    Set Set::operator-( const Set &a )
    {
        Set c;
        for( size_t i = 0; i < words.size(); i++ )
        {
            c.addWord( words[i]->getWord() );
        }

        if(a.words.size()==0) return c;

        for( size_t i = 0; i < a.words.size(); i++ )
        {
            for( size_t j = 0; j < c.words.size(); j++ )
            {
                if( a.words[i]->getWord() == c.words[j]->getWord() )
                {
                    c.words.erase( c.words.begin()+j );
                    break;
                }
            }
        }
        return c;
    }

