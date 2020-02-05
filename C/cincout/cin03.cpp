#include<iostream>
using namespace std;

// cin.ignore()
// 忽视缓存区当前的字符，跳到下一个
void test01()
{
    int number1;
    cin.ignore(3);
    cin >> number1;
    cout << "number1:" << number1 << endl;
}

void test02()
{
    int number1;
    cin.ignore(2);
    cin >> number1;
    cout << "number1:" << number1 << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}