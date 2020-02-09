#include<iostream>
#include<map>

using namespace std;

// map主要是以键-值形式存放（以pair的形式存）的，按照红黑树的方式对键排序存放的存储结构

void test1()
{
    map<int, int> m1;
    // 插入数据 插入 pair.first pair.second
    // 第一种
    // 前三种类似，返回值pair，pair.first是迭代器，second是插入是否成功的结果
    pair<map<int, int>::iterator, bool> ret;   
    ret = m1.insert(pair<int, int>(10, 10));
    cout << ret.second << endl;
    ret = m1.insert(pair<int, int>(10, 11));
    cout << ret.second << endl;  // 返回为0，说明插入失败，因为原来已经有key=10,不能再插入了（区别第四种插入方式）
    // 第二种
    m1.insert(make_pair(20, 20));
    // 第三种
    m1.insert(map<int, int>::value_type(30, 30));
    // 第四种
    m1[40] = 40;
    //打印
    map<int, int>::iterator p1;
    for (p1 = m1.begin(); p1 != m1.end();p1++)
    {
        cout << "key :" << (*p1).first << " value；" << p1->second << endl;
    }

    m1[40] = 100;  //若键已经存在，可进行修改；若不存在，添加之
    for (p1 = m1.begin(); p1 != m1.end();p1++)
    {
        cout << "key :" << (*p1).first << " value；" << p1->second << endl;
    }

    cout << m1[60] << endl;  //会自动为其陪 60——0的键值对
    for (p1 = m1.begin(); p1 != m1.end();p1++)
    {
        cout << "key :" << (*p1).first << " value；" << p1->second << endl;
    }

}

int main()
{
    test1();
    return 0;
}