#include <iostream>
#include <string>
#include <vector>
#include "klasy.h"
#include "test.h"
#include "menu.h"
using namespace std;

void Menu::showMenu()
{
    cout << "-------------" << endl;
    cout << "MENU" << endl;
    cout << "-------------" << endl;
    cout << "1 - Stworz zbiory" << endl;
    cout << "2 - Dodaj slowo do zbioru" << endl;
    cout << "3 - Usun slowo ze zbioru" << endl;
    cout << "4 - Usun powtarzajace sie slowa ze zbioru" << endl;
    cout << "5 - Pokaz najkrotsze slowo w zbiorze" << endl;
    cout << "6 - Pokaz najdluzsze slowo w zbiorze" << endl;
    cout << "7 - Suma zbiorow" << endl;
    cout << "8 - Iloczyn zbiorow" << endl;
    cout << "9 - Pokaz elementy zbioru" << endl;
    cout << "10 - Uruchom testy" << endl;
    cout << "11 - Zamknij" << endl;
}
void Menu::run()
{
    int temp = 0, n;
    showMenu();
    cin >> choice;
    while( choice != 11 )
    {
        switch( choice )
        {
            case 1:
                {
                    if( temp )
                    {
                        cout << "Podczas jednej sesji mozna tworzyc zbiory tylko raz !!!" << endl;
                        break;
                    }
                    temp = 1;
                    cout << "Ile zbiorow stworzyc ?" << endl;
                    cin >> n;

                    for( int j = 0; j < n; j++ )
                    {
                        sets.push_back( new Set() );
                        cout << "Zbior nr " << j << endl;
                        sets[j]->createSet();
                    }
                    break;
                }
            case 2:
                {
                    if( !temp )
                    {
                        cout << "Nie zostal utworzony zaden zbior !!!" << endl;
                        break;
                    }
                    int i;
                    string s;
                    cout << "Do ktorego zbioru chcesz dodac slowo ? (podaj nr od 0 do " << n-1 << ")" << endl;
                    cin >> i;
                    if( i >= n )
                    {
                        cout << "Zbior nr " << i << " nie istnieje" << endl;
                        break;
                    }
                    cout << "Jakie to slowo ?" << endl;
                    cin >> s;
                    sets[i]->addWord(s);
                    break;
                }
            case 3:
                {
                    if( !temp )
                    {
                        cout << "Nie zostal utworzony zaden zbior !!!" << endl;
                        break;
                    }
                    int i;
                    string s;
                    cout << "Z ktorego zbioru chcesz usunac slowo ? (podaj nr od 0 do " << n-1 << ")" << endl;
                    cin >> i;
                    if( i >= n )
                    {
                        cout << "Zbior nr " << i << " nie istnieje" << endl;
                        break;
                    }
                    cout << "Jakie to slowo ?" << endl;
                    cin >> s;
                    sets[i]->deleteWord(s);
                    break;
                }
            case 4:
                {
                    if( !temp )
                    {
                        cout << "Nie zostal utworzony zaden zbior !!!" << endl;
                        break;
                    }
                    int i;
                    cout << "Z ktorego zbioru chcesz usunac powtarzajace sie slowa ? (podaj nr od 0 do " << n-1 << ")" << endl;
                    cin >> i;
                    if( i >= n )
                    {
                        cout << "Zbior nr " << i << " nie istnieje" << endl;
                        break;
                    }
                    sets[i]->deleteRepeated();
                    break;
                }
            case 5:
                {
                    if( !temp )
                    {
                        cout << "Nie zostal utworzony zaden zbior !!!" << endl;
                        break;
                    }
                    int i;
                    cout << "Podaj nr zbioru od 0 do " << n-1 << endl;
                    cin >> i;
                    if( i >= n )
                    {
                        cout << "Zbior nr " << i << " nie istnieje" << endl;
                        break;
                    }
                    cout << "Najkrotsze slowo w zbiorze : " << sets[i]->shortestWord() << endl;
                    break;
                }
            case 6:
                {
                    if( !temp )
                    {
                        cout << "Nie zostal utworzony zaden zbior !!!" << endl;
                        break;
                    }
                    int i;
                    cout << "Podaj nr zbioru od 0 do " << n-1 << endl;
                    cin >> i;
                    if( i >= n )
                    {
                        cout << "Zbior nr " << i << " nie istnieje" << endl;
                        break;
                    }
                    cout << "Najdluzsze slowo w zbiorze : " << sets[i]->longestWord() << endl;
                    break;
                }
            case 7:
                {
                    if( !temp )
                    {
                        cout << "Nie zostal utworzony zaden zbior !!!" << endl;
                        break;
                    }
                    if( n < 2 ) { cout << "Nie utworzono wystarczajacej ilosci zbiorow" << endl; }
                    int i, j;
                    cout << "Podaj 2 numery zbiorow z przedzialu [0 ; " << n-1 << "]" << endl;
                    cin >> i >> j;
                    if( i >= n || j >= n ){ cout << "Takie zbiory nie istnieja" << endl; break;}
                    Set a, b;
                    for( int x = 0; x < sets[i]->sizeofSet; x++ )
                    {
                        a.addWord( sets[i]->getWord(x) );
                    }
                    for( int x = 0; x < sets[j]->sizeofSet; x++ )
                    {
                        b.addWord( sets[j]->getWord(x) );
                    }
                   (a+b).display();
                    break;
                }
            case 8:
                {
                    if( !temp )
                    {
                        cout << "Nie zostal utworzony zaden zbior !!!" << endl;
                        break;
                    }
                    if( n < 2 ) { cout << "Nie utworzono wystarczajacej ilosci zbiorow" << endl; }
                    int i, j;
                    cout << "Podaj 2 numery zbiorow z przedzialu [0 ; " << n-1 << "]" << endl;
                    cin >> i >> j;
                    if( i >= n || j >= n ){ cout << "Takie zbiory nie istnieja" << endl; break;}
                    Set a, b;
                    for( int x = 0; x < sets[i]->sizeofSet; x++ )
                    {
                        a.addWord( sets[i]->getWord(x) );
                    }
                    for( int x = 0; x < sets[j]->sizeofSet; x++ )
                    {
                        b.addWord( sets[j]->getWord(x) );
                    }
                   (a*b).display();
                    break;
                }
            case 9:
                {
                    if( !temp )
                    {
                        cout << "Nie zostal utworzony zaden zbior !!!" << endl;
                        break;
                    }
                    int i;
                    cout << "Ktory zbior chcesz zobaczyc ? (podaj nr do 0 do " << n-1 << ")" << endl;
                    cin >> i;
                    if( i >= n )
                    {
                        cout << "Zbior nr " << i << " nie istnieje" << endl;
                        break;
                    }
                    sets[i]->display();
                    break;
                }
            case 10:
                {
                    TestSet test;
                    test.testAll();
                    break;
                }
            default:
                cout << "Blad !!!" << endl;
                break;
         }
        showMenu();
        cin >> choice;
        system( "cls" );
    }
}
