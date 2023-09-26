#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<string> keys;
vector<pair<string, float>> keyTime;

int key_read(string file = "key.txt")
{
    ifstream inputfile(file);

    if(inputfile.is_open())
    {
        string line;
        while (getline(inputfile, line))
        {
            keys.push_back(line);
        }
        
    }else
    {
        return -1;
    }
    inputfile.close();
    return 0;
}

string spilt_char(string line,char keysplit)
{
    int splitNumeber;
    istringstream iss(line);
    string buf;
    if(keysplit == ' ')
    {
        splitNumeber = 2;
    }else{
        splitNumeber = 3;
    }

    while(splitNumeber--)
    {
        getline(iss, buf, keysplit);
    }
    return buf;
}

void coutResult()
{
    int len = 5;
    cout << "时间点";
    for(int i = 0; i < len; i++)
    {
        cout << " ";
    }
    cout << "关键字" << endl;
    for(auto c: keyTime)
    {
        cout << c.second;
        for(int i = 0; i < len; i++)
        {
            cout << " ";
        }
        cout << c.first << endl;
    }
}

int savefile()
{
    std::ofstream file("result.txt"); 

    if (file.is_open()) { 
        for (auto c : keyTime) {
            file << c.first  << c.second << std::endl; 
        }

        file.close(); // 关闭文件
    } else {
        std::cout << "Failed to open the file." << std::endl;
        return -1;
    }

    return 0;
}

int find_work(string file = "log.txt")
{
    ifstream inputfile(file);
    string buf;

    if(inputfile.is_open())
    {
        string line;
        while (getline(inputfile, line))
        {
            for(auto c : keys)
            {
                if(string::npos != line.find(c))
                {
                    buf = spilt_char(line, ' ');
                    buf = spilt_char(buf, ':');
                    float number = stof(buf);
                    pair<string, float> temp;
                    temp.first = c;

                    ostringstream oss;
                    oss << fixed << setprecision(3) << number;
                    number = stof(oss.str());
                    temp.second = number;
                    keyTime.push_back(temp);
                }
            }
        }
        
    }else
    {
        return -1;
    }
    coutResult();
    if(-1 == savefile())
    {
        cout << "save file faile" << endl;
    }else{
        cout << "save file succuess" << endl;        
    } 
    inputfile.close();
    return 0;    
}