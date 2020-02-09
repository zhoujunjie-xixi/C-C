#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

#define SALE_DEPARTMENT 1 //销售部门
#define DEVELOP_DEPARTMENT 2 //研发部门
#define FINASCIAL_DEPARTMENT 3 //财务部门
#define ALL_DEPARTMENT 4 //所有部门

// multimap 案例
// 公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在哪个部门工作
// 人员信息有：姓名 年龄 电话 工资等组成
// 通过 Multimap 进行信息的插入 保存 显示
// 分部门显示员工信息 显示全部员工信息

class worker
{
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};

// 创建员工
void CreateWorker(vector<worker>&vWorker)
{
    int i;
    string s1 = "ABCDE";
    srand(time(NULL));
    for (i = 0; i < 5;i++)
    {    
        worker w1;
        w1.mName = "worker";
        w1.mName += s1[i];
        w1.mAge = rand() % 30 +20;
        w1.mSalary = rand() % 100000 + 50000;
        w1.mTele = "010-8888888";

        vWorker.push_back(w1);
    }
}
// 员工分组
void WorkerByGroup(vector<worker>& vWorker,multimap<int,worker>& sWorker)
{
    srand(time(NULL));
    vector<worker>::iterator p1;
    for (p1 = vWorker.begin(); p1 != vWorker.end();p1++)
    {
        int depart;
        depart = rand() % 3 + 1;
        switch(depart)
        {
        case SALE_DEPARTMENT: 
            sWorker.insert(make_pair(depart,*p1));
            break;
        case DEVELOP_DEPARTMENT: 
            sWorker.insert(make_pair(depart,*p1));;
            break;
        case FINASCIAL_DEPARTMENT: 
            sWorker.insert(make_pair(depart,*p1));;
            break;
        default:
            break;
        }
    }
}

// 打印每一部门的员工信息
void show(multimap<int, worker>& sWorker,int department)
{
    int i,count;
    multimap<int, worker>::iterator it;
    count = sWorker.count(department);
    for (it = sWorker.find(department), i = 0; it != sWorker.end() && i < count;it++,i++)
    {
        cout << "mName:" << it->second.mName << " "
             << "mAge:" << it->second.mAge << " "
             << "Salary:" << it->second.mSalary << " "
             << "mTele:" << it->second.mTele << endl;
    }
}

// 打印全部员工信息
void PrintWorkerByGroup(multimap<int, worker>& sWorker)
{
    // 打印销售部员工信息
    cout << "sale department" << endl;
    show(sWorker, SALE_DEPARTMENT);
    // 打印研发部门
    cout << "develop department" << endl;
    show(sWorker, DEVELOP_DEPARTMENT);
    // 打印销售部门
    cout << "finacial department" << endl;
    show(sWorker, FINASCIAL_DEPARTMENT);

}

int main()
{
    // 存放新员工的信息
    vector<worker> vWorker;
    // multiset 保存分组信息
    multimap<int, worker> sWorker;
    // 创建员工
    CreateWorker(vWorker);
    // 员工分组
    WorkerByGroup(vWorker,sWorker);
    // 打印每一部门的员工信息
    PrintWorkerByGroup(sWorker);
    return 0;
}