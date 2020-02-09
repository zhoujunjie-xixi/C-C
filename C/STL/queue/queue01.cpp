#include<iostream>
#include<queue>
using namespace std;

void test1()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    while(!q.empty())
    {
        cout<<q.front()<<endl;  // 返回队头元素
        q.pop();
    }
    cout<<q.back()<<endl; //返回队尾元素
}

int main()
{
    test1();
    return 0;
}
