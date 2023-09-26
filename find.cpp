#include <iostream>
#include "find.h"

using namespace std;

int main()
{
    int flag = 0;
    string file;
    cout << "-----------log 拆解系统-----------"  << endl;
    cout << "选项0：使用默认log文件-------------"  << endl;
    cout << "选项1：使用手动导入log文件---------"  << endl;
    cin >> flag;


    if(-1 == key_read())
    {
        cout << "关键字导入失败" << endl;
    }

    if(flag == 0)
    {
        find_work();
    }else{
        find_work(file);
    }
}