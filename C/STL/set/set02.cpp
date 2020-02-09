#include<iostream>
#include<set>

using namespace std;

// vscode下无法运行
/*
    set默认从小到大排序，且对基本数据类型进行排序
    因此我们可以通过仿函数（此处简介，后面会有专门详解）来更改排序规则
*/

struct mycompare
{
    bool operator()(int a,int b)
    {
        return a > b;
    }
};

void test1()
{
    set<int, mycompare> s1;
    s1.insert(100);
    s1.insert(2);
    s1.insert(43);
    s1.insert(10);

    set<int>::iterator p;
    for(p=s1.begin();p!=s1.end();p++)
    {
        cout<<(*p)<<" ";
    }
    cout<<endl;
}

struct person
{
    int id;
    int age;
    person(int a,int b)
    {
        id = a;
        age = b;
    }
    bool operator < (const person& p1)
    {
        return age > p1.age;
    }

};

//class mycompare2
//{
//public:
//	bool operator()(person p1,person p2)
//	{
//		return p1.age < p2.age;
//	}
//};

void test2()
{
    set<person> s1;
    person p1(1, 4);
    person p2(1, 2);
    person p3(1, 8);
    person p4(1, 5);

    set<person>::iterator p;
    for(p=s1.begin();p!=s1.end();p++)
    {
        cout<<(*p).age<<" ";
    }
    cout<<endl;
}

int main()
{
    //test1();
    //test2();
    return 0;
}