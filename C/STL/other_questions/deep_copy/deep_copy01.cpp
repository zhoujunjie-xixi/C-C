#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;

class person
{
public:
    int mAge;
    char* mName;

    person(int age=0, char* name="")
    {
        mAge = age;
        this->mName = new char[strlen(name)];
        strcpy(mName,name);
    }

    ~person()
    {
        if(this->mName)
        {
            delete [] this->mName;
        }
    }

};

// 此程序会直接崩掉，因为在vector存放p1时实际上是一个浅拷贝的过程，因此p1和拷贝的p1内两个指针指向同一个内存，释放两次，裂开
//　解决方案见deep_copy02 写一个深拷贝函数使得拷贝的p2中指针自己也开辟一个内存区域
void test1()
{
    vector<person> v1;
    person p1(10,"zjj");
    v1.push_back(p1);
}

int main()
{
    test1();
    
    return 0;
}