#include<iostream>
using namespace std;

// 类模板
// 类外实现
template <class T>
class animal
{
protected:
    T mAge;
public:
    // 类内为函数声明，类外写函数
    animal(T Age);
    void show();
};

template<class T>
animal<T>::animal(T Age)
{
    this->mAge = Age;
}

template<class T>
void animal<T>::show()
{
    cout << "animal's age is " << this->mAge;
}
int main()
{
    //注意此处的类对象调用需要指明<>中的类型
    animal<int> a(10);
    a.show();
    return 0;
}