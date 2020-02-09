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

    person(int age=0,const char* name="")
    {
        mAge = age;
        this->mName = new char[strlen(name)];
        strcpy(mName,name);
    }

    //　push_back本质上是一个拷贝的过程
    person(const person &p)
    {
        this->mAge = p.mAge;
        new char[strlen(this->mName) + 1];
        strcpy(this->mName, p.mName);
    }

    // 重载= 
    // 处理vector对象间赋值问题
    person& operator= (const person &p) 
    {
        if(this->mName)
        {
            delete [] mName;
        }
        this->mAge = p.mAge;
        new char[strlen(this->mName) + 1];
        strcpy(this->mName, p.mName);

        return *this;
    }
    ~person()
    {
        if(this->mName)
        {
            delete [] this->mName;
        }
    }

};

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