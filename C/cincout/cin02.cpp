#include<iostream>
using namespace std;

// cin.peek()
void test01()
{
    char number1;
    int number2;
    number1 = cin.peek();    //cin.peek与cin.put不同在于，peek仅仅查看当前缓存区的值，不取走；
    cin >> number2;         //而cin.put()取走了缓存区的值
    
    cout << "number1:" << number1 << endl;
    cout << "number2:" << number2 << endl;
}

int main()
{
    test01();
    return 0;
}