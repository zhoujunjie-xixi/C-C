#include<iostream>
#include <queue>
using namespace std;

struct node {
    int priority;
    int value;
    node(int a,int b)
    {
        priority = a;
        value = b;
    }
    friend bool operator < (const node &a, const node &b) {  
        return a.priority < b.priority;  //大顶堆
    }
    /* 这样写也可以
    bool operator < (const node &a) const {
        return priority < a.priority;
    }
    */

};
/**
因为标准库默认使用元素类型的<操作符来确定它们之间的优先级关系。而且自定义类型的<操作符与>操作符并无直接联系，故会编译不过。
struct node {
    int priority;
    int value;
    friend bool operator > (const node &a, const node &b) {   //错误示范
        return a.priority > b.priority;  
    }
};
**/


int main()
{   
    priority_queue<node> q;
    node a(1, 3);
    node b(2, 2);
    node c(3, 1);

    q.push(a);
    q.push(b);
    q.push(c);

    while(!q.empty())
    {
        cout << q.top().priority;
        q.pop();
    }
    return 0;
}