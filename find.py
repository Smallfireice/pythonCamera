import os
import time
keyList=[]
time=[]
keyWithTime={}

#关键字获取函数，关键字保存到列表keyList中
def key_read(filePath):
    file=open(filePath, encoding='utf-8')
    i=1
    line= file.readline()
    while line:
        keyList.append(line.replace('\n', ''))
        line=file.readline()
        i=i+1
    file.close()
#文件内容对比工作
def work(filePath='log.txt'):
    file=open(filePath, encoding='utf-8')
    i=1
    line= file.readline()
    while line:
        for key in keyList:
            if line.find(key)!= -1:
                time=line.split()
                time1=time[1].split(':')
                keyWithTime[key]=format(float(time1[2]), ".3f")
        line=file.readline()
        i=i+1
    file.close()   
key_read('key.txt') 
work()
print(f'keyList: {keyList}')
print(f'keyWithTime: {keyWithTime}')
os.system('pause')