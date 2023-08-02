#include<stdio.h>
#include<string.h>
#include "F:\vscode_project\test_code\include\test.h"
//输出所有员工的结构体信息
void PrintEmployAll(struct msg* employ,int size)
{
    for(int i=0;i<size;i++){
        if(employ[i].up!=0)
        {
            printf("ID=%d\n",employ[i].id);
            printf("NAME=%s\n",employ[i].name);
            printf("TYPE=%s\n",employ[i].type);
            printf("CHECK in=%s\n",employ[i].check_in);
            printf("CHECK in=%s\n",employ[i].check_out);
            printf("\n");
        }
    }
}



//更新结构体信息
void UpgradeMsg(struct msg* employee,int employeeID,char* checktime)
{
    if(employee[employeeID].up==0)
    {
        strcpy(employee[employeeID].check_in,checktime);
        employee[employeeID].up=1;
    }else{
        memset(employee[employeeID].check_out,0,10);
        strcpy(employee[employeeID].check_out,checktime);
    }
}


//输出选中员工的结构体信息
void PrintEmploy(struct msg* employee,int employeeID){
        printf("ID=%d\n",employee[employeeID].id);
        printf("NAME=%s\n",employee[employeeID].name);
        printf("TYPE=%s\n",employee[employeeID].type);
        printf("CHECK in=%s\n",employee[employeeID].check_in);
        printf("CHECK in=%s\n",employee[employeeID].check_out);
        printf("\n");
}
