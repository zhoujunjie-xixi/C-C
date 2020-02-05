#include<iostream>
using namespace std;

// 模板技术，类型参数化 编写代码可以忽略类型
template <class T,class T1>
void func_template01(T &a,T1 &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 1;
    float b = 3;
    cout << "a = " << a << endl << "b = " << b << endl;
    //1.自动类型推导
    func_template01(a, b);
    cout << "a = " << a << endl << "b = " << b << endl;
    cout << typeid(a).name()<<endl;  // a仍为 int
    cout << typeid(b).name()<<endl;  // b仍为 float

    //2.显式指定类型
    int c = 2;
    cout << "a = " << a << endl << "c = " << c << endl;
    func_template01<int>(a,c);
    cout << "a = " << a << endl << "c = " << c << endl;
}


int main()
{
    test01();
    return 0;
}