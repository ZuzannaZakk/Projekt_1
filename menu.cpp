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
    cout << "9 - Roznica zbiorow" << endl;
    cout << "10 - Pokaz elementy zbioru" << endl;
    cout << "11 - Zamknij" << endl;
}
void Menu::run()
{
    //int choice;
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
                        cout << "Podczas jednej sesji mozna tworzyc zbiory tylko raz" << endl;
                        break;
                    }
                    temp = 1;
                    //int n;
                    cout << "Ile zbiorow stworzyc ?" << endl;
                    cin >> n;
                    //Set *sets = new Set[n];
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
                    cout << "Do ktorego zbioru chcesz dodac slowo ? (podaj nr)" << endl;
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
                    cout << "Z ktorego zbioru chcesz usunac slowo ? (podaj nr)" << endl;
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
                    cout << "Z ktorego zbioru chcesz usunac slowo ? (podaj nr)" << endl;
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
                    cout << "Podaj nr zbioru" << endl;
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
                    cout << "Podaj nr zbioru" << endl;
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
                    int i, j;
                    cout << "Podaj 2 numery zbiorow" << endl;
                    cin >> i >> j;
                    //(sets[i]+sets[j])->display();
                    break;
                }
            case 8:
                {
                    int i, j;
                    cout << "Podaj 2 numery zbiorow" << endl;
                    cin >> i >> j;

                    break;
                }
            case 10:
                {
                    int i;
                    cout << "Ktory zbior chcesz zobaczyc ? (podaj nr)" << endl;
                    cin >> i;
                    if( i >= n )
                    {
                        cout << "Zbior nr " << i << " nie istnieje" << endl;
                        break;
                    }
                    sets[i]->display();
                    break;
                }
            default:
                cout << "Blad !!!" << endl;
                break;
         }
        showMenu();
        cin >> choice;
    }
}
