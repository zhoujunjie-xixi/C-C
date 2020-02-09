#include<iostream>
#include<set>

using namespace std;

/*
    set/multiset 的特性是会根据元素的值自动进行排序(默认从小到大)
    set是以RB-tree（红黑树，平衡二叉树的一种） 为底层机制
    set 中每个元素只出现一次
    multiset 中可以有重复元素
*/

void Printset(set<int>&s)
{
    set<int>::iterator p;
    for(p=s.begin();p!=s.end();p++)
    {
        cout<<(*p)<<" ";
    }
    cout<<endl;
}

void test1()
{
    set<int> s1;
    s1.insert(100);
    s1.insert(2);
    s1.insert(43);
    s1.insert(10);

    set<int>::iterator p1;
    s1.erase(2);
    p1 = s1.erase(++s1.begin()); // 先++，删43，返回下一个指向100的迭代器
    cout<<(*p1)<<endl;
    Printset(s1);
}

void result(set<int>::iterator &p1,set<int> &s1)
{
    if(p1 == s1.end())
    {
        cout<<"don't find!"<<endl;
    }
    else
    {
        cout<<(*p1)<<endl;
    }
}

void test2()
{
    set<int> s1;
    s1.insert(100);
    s1.insert(2);
    s1.insert(43);
    s1.insert(10);

    Printset(s1);
    set<int>::iterator p1;
    p1 = s1.find(2);
    result(p1, s1);

    p1 = s1.find(1000);
    result(p1, s1);

    // 返回第一个 >=10 的迭代器
    p1 = s1.lower_bound(10);
    result(p1, s1);
    
    // 返回第一个 > 10 的迭代器
    p1 = s1.upper_bound(10);
    result(p1, s1);

    // equal_range 返回 lower_bound 和 upper_bound的值
    pair<set<int>::iterator,set<int>::iterator> ret = s1.equal_range(10);
    cout<<"equal_range(10): ----------"<<endl;
    result(ret.first, s1);
    result(ret.second , s1);
}

int main()
{
    //test1();
    test2();
    return 0;
}