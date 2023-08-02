#include "F:\vscode_project\test_code\include\test.h"

#define BUFFSIZE 20
int main()
{
    //初始化
    struct msg employ_msg[SIZE];
    memset(employ_msg,0,SIZE);
    for(int i=0;i<SIZE;i++)
    {
        employ_msg[i].up=0;
        employ_msg[i].id=-1;
    }
    //建立数据库

    FILE* p=fopen("date.xml",'r');
    char* buff[BUFFSIZE];
    memset(buff,0,BUFFSIZE);
    while(fgets(buff,BUFFSIZE,p)){
        int num=0;
        int index=0;
        for(;index<BUFFSIZE;index++)
        {
            if(buff[index]>='0'&&buff[index]<='9')
            {
                num=num*10+(buff[index]-'0');
            }else break;
        }
        employ_msg[num].id=num;
        for(;index<BUFFSIZE;index++)
        {
            if(buff[index]>='a'&&buff[index]<='z')
            {
                employ_msg[num].name[index]=buff[index];
            }else break;
        }
        employ_msg[num].name[index]='/n';
        memset(buff,0,BUFFSIZE);
    }

    //循环主体
    while (1)
    {
        int cmdid=-1;
        int comployeeid=-1;
        char CheckTime[10];
        int c;
        //while ((c = getchar()) != '\n' && c != EOF) {} //清空缓冲区
        scanf("%d",&cmdid);
        if(cmdid==0)
        {
            for(int i=0;i<SIZE;i++)
                {
                    if(employ_msg[i].up!=0)
                    {
                        employ_msg[i].up=0;
                        employ_msg[i].id=-1;
                    }
                }
        }else if(cmdid==1&&scanf("%d %s",&comployeeid,CheckTime))
        {
            //更新数据库
            printf("update datebase\n");
            UpgradeMsg(employ_msg,comployeeid,CheckTime);

        }else if(cmdid==2)
        {
            //输出选中员工信息
            if(scanf("%d",&comployeeid)==1){
                printf("choosing employee msg\n");
                PrintEmploy(employ_msg,comployeeid);
            }
            else{
                //
                printf("ALL of emplpy msg\n");
                PrintEmployAll(employ_msg,SIZE);
            }
        }
        else{
            printf("ERR:COMMAND INVALID 重新输入\n");
            while ((c = getchar()) != '\n' && c != EOF) {} //清空缓冲区
        } 
    }
    return 0;
    
}
