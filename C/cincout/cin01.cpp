#include<iostream>
using namespace std;

// 了解 cin
void test1()
{
    int number1;       //注意一点，下面number实质上得到的是cin.get()的‘1’这个字符，再由int转为对应的49  即‘1’ --49
    int number2;
    number1 = cin.get();   //可以看见，虽然有cin.get和cin两个，但实际上我们从键盘仅仅输入了一次
    cin >> number2;       //number2 的赋值是由之前缓存区中尚存的数对其赋值的
    cout << "number1:" << number1 << endl;
    cout << "number2:" << number2 << endl;
}

int main()
{
    test1();
    return 0;
}