#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

// 评委打分案例（sort算法排序）
// 创建5个选手（姓名，得分），10个评委对5个选手进行打分
//得分规则：去除最高分，去除最得分，取出平均分
//按得分对5名选手进行排名

// 选手类
class player
{  
public:
    string mName;
    int mScore;
    player(string name="",int score=0)
    {
        mName = "player";
        mName += name;
        mScore = score;
    }   

    void setscore(int score)
    {
        mScore = score;
    }
    void show()
    {
        cout<<mName<<" "<<mScore<<endl;
    }
};

// 创建选手
void createplayer(vector<player>&v)
{
    string nameseed = "12345";
    for(int i=0;i<5;i++)
    {
        player p(nameseed.substr(i,1),0);
        v.push_back(p);
    }
}

// 打分
void point(vector<player>&v)
{
    int i,x;
    int average;
    vector<player>::iterator pv;
    for(pv=v.begin();pv!=v.end();pv++)
    {
        deque<int> d;
        for(i=0;i<10;i++)
        {
            x = rand()%41 + 60; // 60~100
            d.push_back(x);
        }

        // 排序，去掉最大值，最小值
        sort(d.begin(),d.end()); // 默认从小到大
        d.pop_back();
        d.pop_front();

        // 计算平均值
        average = 0;
        deque<int>::iterator pd;
        for(pd=d.begin();pd!=d.end();pd++)
        {
            average += (*pd);
        }
        average /= d.size();
        (*pv).setscore(average);
    }
}

bool compare(player p1,player p2)
{
    return p1.mScore>p2.mScore;
}

// 对选手进行排序
void sortplayer(vector<player>&v)
{
    // sort默认从小到大，所以未处理其他情况，可以自行定义排序的方案
    sort(v.begin(), v.end(),compare);

    // 打印结果
    vector<player>::iterator p;
    for (p = v.begin(); p != v.end(); p++) 
    {
        cout<<(*p).mName<<" "<<(*p).mScore<<endl;
    }   
}

int main()
{
    vector<player> v;
    createplayer(v);
    point(v);
    sortplayer(v);
    return 0;
}