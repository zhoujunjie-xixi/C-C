#include<iostream>
using namespace std;

void dividor(int x,int y)
{
    if(y==0)
        throw y;

    cout<<"the result is:"<< x / y;
}

void func()
{
    dividor(10, 0);
}

// 此处添加func意在说明异常的处理是可以逐级传递的
// 并非只能传一层
void test1()
{
    try
    {
        func();
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