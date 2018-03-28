#include <iostream>
#include <string>
#include <vector>
#include "klasy.h"
#include "test.h"
#include "menu.h"
using namespace std;

    int Set::getsizeofSet()
    {
        return this->sizeofSet;
    }

    void Set::createSet()
    {
        int n, temp = 1;
        string s;
        cout << "Liczba elementow zbioru : ";
        while( !(cin>>n) )
        {
            cin.clear();
            //cin.sync();
            cin.ignore( 1000 , '\n' );
            cout << "Podaj poprawna liczbe elementow zbioru : " << endl;
        }
        cout << "Elementy zbioru :" << endl;
        for( int i = 0; i < n; i++ )
        {
            temp = 1;
            cin >> s;
            for( size_t j = 0; j < s.length(); j++ )
            {
                if( isdigit( s[j] ) )
                {
                    cout << "To nie slowo !!! Wprowadz element ponownie" << endl;
                    temp = 0;
                    break;
                }
            }
            if( temp )
                addWord( s );
                else i--;
        }
        this->sizeofSet=words.size();
    }

    void Set::addWord( string s )
    {
        words.push_back( new Word(s) );
        this->sizeofSet=words.size();
    }

    void Set::deleteWord( string s )
    {
        if( words.size() == 0 )
        {
            cout << "Nie mozna nic usunac, brak elementow w zbiorze" << endl;
            return;
        }
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
        this->sizeofSet=words.size();
    }

    void Set::display()
    {
        for( size_t i = 0; i < words.size(); i++ )
            cout << words[i]->getWord() << " ";
        cout << endl;
    }

    string Set::getWord( int i )
    {
        return words[i]->getWord();
    }

    void Set::deleteRepeated()
    {
        if( words.size() == 0 )
        {
            return;
        }
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
        this->sizeofSet=words.size();
    }

    string Set::shortestWord()
    {
        if( words.size() == 0 )
        {
            return 0;
        }
        string temp = words[0]->getWord();
        for( size_t i = 1; i < words.size(); i++ )
        {
            if( (words[i]->getWord()).length() < temp.length() )
                temp = words[i]->getWord();
        }
        return temp;
    }

    string Set::longestWord()
    {
        if( words.size() == 0 )
        {
            return 0;
        }
        string temp = words[0]->getWord();
        for( size_t i = 1; i < words.size(); i++ )
        {
            if( (words[i]->getWord()).length() > temp.length() )
                temp = words[i]->getWord();
        }
        return temp;
    }

    Set::~Set()
    {
        for( size_t i = 0; i < words.size(); i++ )
            delete words[i];
        words.clear();
    }

    string Set::Word::getWord()
    {
        return this->s;
    }

    int Set::Word::getLength()
    {
        return this->l;
    }

    Set::Word::Word( string s )
    {
        this->s = s;
        this->l = s.length();
    }

    Set Set::operator+( const Set &a ) //suma zbiorow
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

    Set Set::operator*( const Set &a ) //iloczyn zbiorow
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

    /*Set Set::operator-( const Set &a ) //roznica zbirow
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
                    j--;
                }
            }
        }
        this->sizeofSet=words.size();
        return c;
    }*/


