#include<iostream>
using namespace std;

template <class T>
class animal
{
protected:
    T mAge;
public:
    animal(T Age)
    {
        this->mAge = Age;
    }
    void show()
    {
        cout << "animal's age is " << this->mAge;
    }
};

int main()
{
    animal<int> a(10);
    a.show();
    return 0;
}