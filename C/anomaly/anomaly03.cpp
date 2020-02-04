#include<iostream>
using namespace std;

//01.异常借口声明
//void func1() throw(int) 代表函数体内只能throw int 类型
//主要是声明什么类型的参数 vscode上无法编译,基于此，本程序不做运行

//02.异常类型
//异常可以是int,float,char,char*,乃至 类 等

class Person
{
public:
    void print()
    {
        cout << "lalala" << endl;
    }
};


void func1()
{
    throw 000;
}

void func2()
{
    char c = 'a';
    throw c;
}

// throw 一个Person类
void func3()
{
    Person p;
    throw p;
}

void test1()
{
    try
    {
        func1();
    }
    catch(int x)
    {
        cout << "catch is "<<x<<"!"<<endl;
    }

    try
    {
        func2();
    }
    catch(char str)
    {
        cout << "catch is "<<str<<"!"<<endl;
    }

    try
    {
        func3();
    }
    catch(Person p)
    {
        p.print();  //此处可以调用类中的方法
    }
}

int main()
{
    test1();
    return 0;
}