#include<iostream>
#include<string>

using namespace std;

void test1()
{
    pair<int,int> pair1(10,4);
    cout<<pair1.first<<" "<<pair1.second<<endl;

    pair<int,string> pair2 = make_pair(1, "jkl");
    cout<<pair2.first<<" "<<pair2.second<<endl;
}

int main()
{
    test1();
    return 0;
}