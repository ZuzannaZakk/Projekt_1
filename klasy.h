using namespace std;
#ifndef klasy_h
#define klasy_h

class Set
{
    class Word
    {
        string s;
        int l;
        public:
            Word( string s );
            string getWord();
            int getLength();
    };
int sizeofSet;
vector<Word*> words;
public:
    Set(){this->sizeofSet=words.size();};
    ~Set();
    int getsizeofSet();
    void createSet();
    void addWord( string s );
    void deleteWord( string s );
    void display();
    void deleteRepeated();
    string shortestWord();
    string longestWord();
    Set operator+( const Set &a ); //suma
    Set operator*( const Set &a ); //iloczyn
    Set operator-( const Set &a ); //roznica
};

#endif // klasy_h
