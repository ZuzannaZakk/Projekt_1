using namespace std;
#ifndef test_h
#define test_h

class TestSet
{
    Set a , b;
public:
    TestSet(){};
    int addWordTest();
    int deleteWordTest();
    int deleteRepeatedTest();
    int shortestWordTest();
    int longestWordTest();
    int sumTest();
    int intersectionTest();
    void testAll();
    ~TestSet(){};
};

#endif // test_h

