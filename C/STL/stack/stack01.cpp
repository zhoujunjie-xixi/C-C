#include<iostream>
#include<stack>
using namespace std;

// 栈的主要操作就是 push，pop，top，empty
void test1()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();

    while(!s1.empty())
    {
        cout << s1.top()<<endl;
        s1.pop();
    }
}


int main()
{
    test1();
    return 0;
}