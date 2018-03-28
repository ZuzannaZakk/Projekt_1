using namespace std;
#ifndef menu_h
#define menu_h

class Menu
{
   int choice;
   vector<Set*> sets;
public:
    Menu(){};
    void showMenu();
    void run();
    ~Menu(){};
};

#endif // menu_h
