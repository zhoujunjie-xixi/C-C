#include<iostream>
using namespace std;
// 栈解旋
//异常被抛出后，从进入 try 块起，到异常被抛掷前
//这期间在栈上的构造的所有对象， 都会被自动析构
//析构的顺序与构造的顺序相反。
class Person
{
public:
    Person()
    {
        cout << "构造函数\n";
    }
    ~Person()
    {
        cout << "析构函数\n";
    }
};
void dividor(int x,int y)
{
    Person p1, p2;

    if(y==0)
        throw y;

    cout<<"the result is:"<< x / y;
}

void test1()
{
    try
    {
        dividor(10, 0);
    }
    catch(int)
    {
        cout << "divisor is 0!";
    }
}
int main()
{
    test1();
    return 0;
}