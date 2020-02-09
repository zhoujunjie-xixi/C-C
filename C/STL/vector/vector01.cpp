#include<iostream>
#include<vector>   //vector
#include<algorithm>  //算法
using namespace std;

class Person
{
public:
    int age;

    Person(int num)
    {
        age = num;
    }
};

// 存放 类指针
void test3()
{
    Person p5(30), p6(40);
    Person *p3, *p4;
    p3 = &p5;
    p4 = &p6;
    vector<Person*> v1;
    v1.push_back(p3);
    v1.push_back(p4);

    vector<Person*>::iterator p = v1.begin();
    for (; p != v1.end();p++)
    {
        cout << (**p).age << " ";
    }
}


//  容器可存放自定义类型
void test2()
{
    Person p1(10), p2(20);
    vector<Person> v1;
    v1.push_back(p1);
    v1.push_back(p2);

    vector<Person>::iterator p = v1.begin();
    for (; p != v1.end();p++)
    {
        cout << (*p).age << " ";
    }
}

void Printvector(int v)
{
    cout<<v<<" ";
}

void test1()
{
    int i;
    // 定义对象时指明类型
    vector<int> v;
    for(i=0;i<5;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();
    // for_each 是内置的遍历算法
    for_each(pBegin, pEnd, Printvector);

}

int main()
{
    //test1();
    //test2();
    test3();
    return 0;
}
