#include<iostream>
using namespace std;

// 类模板
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
    //注意此处的类对象调用需要指明<>中的类型
    animal<int> a(10);
    a.show();
    return 0;
}