#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#define debug 0

using namespace std;
vector<string> keys;
vector<pair<string, string>> keyTime;

int key_read(string file = "key.txt")
{
    ifstream inputfile(file);
    if(inputfile.is_open())
    {
        string line;
        while (getline(inputfile, line))
        {
            line.erase(line.find_last_not_of("\r\n")+1);
            keys.push_back(line);
        }
        
    }else
    {
        return -1;
    }
    inputfile.close();
    for(auto c : keys)
    {
#if debug
        cout << c << endl;
#endif
    }
    return 0;
}
bool sortfunc(const pair<string, string> &a, const pair<string, string> &b)
{
    return stod(a.second) < stod(b.second);
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
        if(buf == "ALGO")
        {
            splitNumeber++;
        }
    }
    return buf;
}

string substr(string &buf, char a, int number)
{
    string result = buf;
    size_t pos = result.find(a);
    
    if (pos != std::string::npos) {
        result = result.substr(0, pos + number+1);
    }
    return result;
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

    if (file.is_open()) 
    { 
        for (auto c : keyTime)
        {
            file << c.first <<endl;
            file << c.second << endl; 
        }

        file.close(); 
    } else 
    {
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
                    pair<string, string> temp;
                    temp.first = c;

                    // ostringstream oss;
                    // oss << fixed << setprecision(3) << number;
                    // number = stof(oss.str());

                    temp.second = substr(buf,'.',3);
                    keyTime.push_back(temp);
#if debug
                    cout << "find" << endl;
#endif
                }else
                {
#if debug
                    cout << "no find" << endl;
#endif
                }
            }
        }
        
    }else
    {
        return -1;
    }
    sort(keyTime.begin(), keyTime.end(), sortfunc);
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