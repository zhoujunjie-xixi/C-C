#include<iostream>
#include<vector>

using namespace std;

void Printvector(vector<int>&v)
{
    vector<int>::iterator p = v.begin();
    for(;p!=v.end();p++)
    {
        cout<<(*p)<<" ";
    }
    cout<<endl;
}


// vector 初始化
void test1()
{
    // 初始化
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    
    // 通过v1容器的开始，结束迭代器给 v2 初始化
    vector<int> v2(v1.begin(),v1.end());
    // 通过拷贝构造的形式初始化
    vector<int> v3(v1);
    // 通过数组的形式初始化
    int array[4] = {0,1,2,3};
    vector<int> v4(array,array+(sizeof(array)/sizeof(int)));

    Printvector(v1);
    Printvector(v2);
    Printvector(v3);
    Printvector(v4);
    
    cout<<"v1和v4交换后：-------"<<endl;
    v1.swap(v4);
    Printvector(v1);
    Printvector(v4);
}

// 赋值操作
void test2()
{
    int array[4] = {0,1,2,3};
    vector<int> v4(array,array+(sizeof(array)/sizeof(int)));

    vector<int> v1,v2;
    v1.assign(v4.begin(),v4.end());

    v2 = v4;
    Printvector(v4);
    Printvector(v1);
    Printvector(v2);
}

// vector存储空间大小操作
// size cpacity resize
void test3()
{
    vector<int> v1;

    for(int i=0;i<1000;i++)
    {
        v1.push_back(i);
    }

    // capacity >= size
    cout<<v1.size()<<endl;
    cout<<v1.capacity()<<endl;

    // 若resize分配的空间比原来的空间小，则原来相对现在的空间被释放
    v1.resize(5);
    Printvector(v1);
}

// 存取数据
// v[] 和 at的访问方式
void test4()
{
    int array[4] = {0,1,2,3};
    vector<int> v(array,array+(sizeof(array)/sizeof(int)));

    for(int i=0;i<v.size();i++)  
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v.size();i++)  
    {
        cout<<v.at(i)<<" ";
    }

    // 两种访问方式的区别：
    // 当访问越界时，vector[]的方式仍会调用未知空间
    // 但是 at 的方式会抛出异常
}

// 巧用 swap 收缩vector
// 问题背景：当我们将容器中元素删除后，可能会出现实际size远远小于capacity的情况
//          因此需要收缩capacity的空间大小
void test5()
{
    vector<int> v1;

    for(int i=0;i<1000;i++)
    {
        v1.push_back(i);
    }

    // capacity >= size
    cout<<v1.size()<<endl;
    cout<<v1.capacity()<<endl;

    //以 v1的size 重置其 capacity
    // 定义匿名对象交换空间，又因为匿名对象周期仅此行，用完释放
    // 妙！！！
    vector<int>(v1).swap(v1);
    
    cout<<"收缩后："<<endl;
    cout<<v1.size()<<endl;
    cout<<v1.capacity()<<endl;
}

// reserve 预留空间
// 背景： 虽然vector是动态分配的，每次重新分配空间的过程可能会耗费不少时间
//      基于此，在预知大概需用的空间前提下，可以预留空间以备使用，达到有效减少重新分配空间次数
void test6()
{
    vector<int> v;
    v.reserve(10000);
    for(int i=0;i<1000;i++)
    {
        v.push_back(i);
    }
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}