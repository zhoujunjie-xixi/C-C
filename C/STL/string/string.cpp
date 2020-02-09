#include<iostream>
#include<string>
using namespace std;

// string 对 char*进行封装，是char*的一个容器


// 初始化
void test1()
{
    string s1;
    string s2("abcd");
    string s3(s2);
    string s4(10,'a');

    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
}

// 赋值操作
void test2()
{
    string s1;
    string s2("abcd");

    s1 = "aaa";
    cout << s1 << endl;

    s1 = s2;
    cout << s2 << endl;

    s1.assign("asd");
    cout << s1;
}

// 取值操作
void test3()
{
    string s1("abcd");
    for (int i = 0; i < s1.size();i++)
    {
        cout << s1[i];
    }
    cout << endl;
    for (int i = 0; i < s1.size();i++)
    {
        cout << s1.at(i);
    }

    //两种访问方式的区别
    //使用at 的方式时当访问越界，则会抛出异常
}

// 字符串的追加操作
// append 和 +=
void test4()
{
    string s1,s3;
    string s2("abcd");

    s3 = s1 = "aaa";

    s1.append(s2);
    cout << s1 << endl;

    s3 += s2;
    cout << s3 << endl;
}

// 字符串的查找
void test5()
{
    string s1 = "abcedabedfa";
    int pos;
    // 查找第一次出现的位置
    pos = s1.find("ed");
    cout << pos << endl;
    // 查找最后一次出现的位子
    pos = s1.rfind("ed");
    cout << pos << endl;
}

// string替换
void test6()
{
    string s1 = "abandon";
    //从第0个位置开始2个字符替换为“234”
    s1.replace(0, 2, "234");
    cout << s1 << endl;
}

// string比较
void test7()
{
    string s1 = "abc";
    string s2 = "abc";

    //相等为0，小于-1，大于1
    cout << s1.compare(s2);
}

// string 子串
void test8()
{
    string s1 = "adfadsfg";
    //从string[3]往后截取3个子串
    string mysubs = s1.substr(3,3);
    cout << mysubs;
}

//string 的插入删除操作
void test9()
{
    string s1 = "abcd";
    //从string[1]处插入"afs"
    s1.insert(1, "afs");
    cout << s1 << endl;
    //从string[1]处往后删除3个字符
    s1.erase(1,3);
    cout << s1 << endl;
}
int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //stest7();
    //test8();
    test9();

    return 0;
}