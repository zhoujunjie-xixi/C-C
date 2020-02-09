#include<iostream>
#include<deque>
using namespace std;

// 双向容器 相比于vector容器可以进行对头部的操作
// 基本操作与vector相似
void Printdeque(deque<int>&d)
{
    deque<int>::iterator p;
    for(p=d.begin();p!=d.end();p++)
    {
        cout<<(*p)<<" ";
    }
    cout<<endl;
}

//初始化
void test1()
{
    deque<int>d1(5,3);
    deque<int>d2(d1.begin(),d1.end());
    deque<int>d3(d2);

    Printdeque(d1);
    Printdeque(d2);
    Printdeque(d3);
}

// 赋值 及 swap
    void test2() {
    deque<int> d1, d2, d3;
    deque<int>d4(3,2);

    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d2 = d1;
    d3.assign(d1.begin(), d1.end());

    Printdeque(d1);
    Printdeque(d2);
    Printdeque(d3);
    Printdeque(d4); 

    d1.swap(d4);
    cout<<"d1,d4交换后：-------"<<endl;
    Printdeque(d1);
    Printdeque(d4);
    }

// 大小操作
void test3()
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    cout<<d.size()<<endl;
    d.resize(2);
    cout<<"重置后："<<endl;
    Printdeque(d);
}

// 双端插入与删除操作
// 读取方式at或者[]
// 返回第一和最后一个值
void test4()
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(0);
    
    cout<<"第一个值："<<d.front()<<endl;
    cout<<"最后一个值："<<d.back()<<endl;
    Printdeque(d);

    d.pop_back();
    d.pop_front();
    cout<<"删除后："<<endl;
    Printdeque(d);
}
int main()
{
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}