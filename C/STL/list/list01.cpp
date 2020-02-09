#include<iostream>
#include<list>
using namespace std;

// （双向）链表

void Printlist(list<int>&l)
{
    list<int>::iterator p;
    for(p=l.begin();p!=l.end();p++)
    {
        cout<<*p<<" ";
    }
    cout<<endl;
}

void test1()
{
    list<int> l1;
    l1.push_back(2);
    l1.push_back(1);
    l1.push_back(3);

    list<int> l2(l1);

    Printlist(l1);
    Printlist(l2);

    list<int> l3,l4;
    //l3.assign(l1.begin(), l1.end());

    l3.push_back(7);
    l3.push_back(2);
    l3.push_back(7);
    l3.push_front(4);
    l3.push_front(3);
    l3.push_front(9);
    l3.pop_front();

    l4 = l3;
    cout<<"l4:";
    Printlist(l4);

    // 删除  返回下一个数据的迭代器
    list<int>::iterator p1;
    p1 = l3.erase(l3.begin());
    cout<<(*p1)<<endl;

    l4.remove(7);
    cout<<"l4.remove(7):";
    Printlist(l4);
}

struct person
{
    int id;
    int age;
    person(int a=0,int b=0)
    {
        id = a;
        age = b;
    }
    // 重载 < 
    bool operator < (const person& a)
    {
        return age > a.age;
    }
};

// 排序，逆置操作
void test2()
{
    list<int> l1;
    l1.push_back(3);
    l1.push_back(1);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(8);

    // 排序，默认从小到大排
    l1.sort();
    Printlist(l1);
    // 逆置
    l1.reverse();
    Printlist(l1);
}

// 自定义排序
void test3()
{
    list<person> l1;
    person p1(1,7);
    person p2(2,2);
    person p3(3,5);
    person p4(4,3);
    
    l1.push_back(p1);
    l1.push_back(p2);
    l1.push_back(p3);
    l1.push_back(p4);
    l1.sort();

    list<person>::iterator p;
    for(p=l1.begin();p!=l1.end();p++)
    {
        cout<<(*p).id<<" "<<(*p).age<<endl;
    }
}

int main()
{
    //test1();
    //test2();
    test3();
    return 0;
}