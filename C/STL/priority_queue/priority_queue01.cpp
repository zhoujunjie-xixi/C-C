#include<iostream>
#include <queue>
using namespace std;

// 普通数据类型例子
// 大家可以看到，默认模板有三个参数，第一个是优先队列处理的类，第二个参数比较有特点，是容纳优先队列的容器。
// 实际上，优先队列是由这个容器+C语言中关于heap的相关操作实现的。这个容器默认是vector，也可以是dequeue
// 因为后者功能更强大，而性能相对于vector较差，考虑到包装在优先队列后，后者功能并不能很好发挥，所以一般选择vector来做这个容器。
// 第三个参数比较重要，支持一个比较结构，默认是less，默认情况下，会选择第一个参数决定的类的<运算符来做这个比较函数。

// 接下来开始坑爹了，虽然用的是less结构，然而，队列的出队顺序却是greater的先出！


int main() 
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a; 
    //等同于 priority_queue<int, vector<int>, less<int> > a;
    
    //             这里一定要有空格，不然成了右移运算符↓
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b;

    for (int i = 0; i < 5; i++) 
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty()) 
    {
        cout << a.top() << ' ';
        a.pop();
    } 
    cout << endl;

    while (!c.empty()) 
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty()) 
    {
        cout << b.top() << ' ';
        b.pop();
    } 
    cout << endl;
    return 0;
}
