#include<iostream>
using namespace std;

void dividor(int x,int y)
{
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