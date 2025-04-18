//
// Created by 28207 on 25-4-8.
//
#include "ad.h"
#include "all.h"
#include "teacher.h"
extern int  choice;
extern int  shenfen;
extern char  usrid[20];
extern Nodeid *head;
extern Nodes*head1;
extern TodoNode *todoHead ;
void adMenue()
{
    printf("\n\n\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t**************学生信息管理系统***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.查看代办   ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.增添账号密码~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.删除账号密码~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~4.修改账号密码~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~5.查看账号密码~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~6.录入账号密码~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~7.导出账号密码~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~8.登录教师端  ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~9.返回上一层  ~~~~~~~~~~~~~~~~\n");
    printf("\t\t                                             \n");
    scanf("%d",&choice);
    if(choice==1)
    {
          system("cls");
            loadTodos();
            if (todoHead == NULL) {
                printf("当前没有待办事项！\n");
                return;
            }

            printf("当前待办事项列表：\n");
            TodoNode *temp = todoHead;
            while (temp != NULL) {
                printf("ID: %d\n", temp->data.id);
                printf("描述: %s\n", temp->data.description);
                printf("状态: %s\n", temp->data.status);
                printf("----------------------------\n");
                temp = temp->next;
                system("cls");
            }
            int choice;
            printf("返回上一页请按1，退出请按任意键：");
            scanf("%d", &choice);
            if (choice == 1) {
                system("cls");
                adMenue();
            } else {
                exit(0);
            }
    }
    else if(choice==2)
    {
        system("cls");
       adId();
    }else if(choice==8)
    {
        system("cls");
        teaMenue();
    }else if(choice==9)
    {
        system("cls");
        Main();
    }else if(choice==3)
    {
        system("cls");
        delId();
    }else if(choice==4)
    {
        system("cls");
        chagId();
    }else if(choice==5)
    {
        system("cls");
        lookId();
    }else if(choice==6)
    {
        system("cls");
        daoRuId();
        int chose = 0;
        printf("返回上一页请按1，结束输入请按任意键：");
        scanf("%d", &chose);
        if (chose == 1) {
            system("cls");
            adMenue();
        }
    }else if(choice==7)
    {
        system("cls");
        daoChuId();
        int chose = 0;
        printf("返回上一页请按1，结束输入请按任意键：");
        scanf("%d", &chose);
        if (chose == 1) {
            system("cls");
            adMenue();
        }
    }
}
void adId()
{
    Nodeid *temp = (Nodeid *)malloc(sizeof(Nodeid));
    temp->next = NULL;
    printf("请输入账号：");
    scanf("%s",temp->data.id);
    printf("请输入密码：");
    scanf("%s",temp->data.password);
   temp->data.answer[0]='0';
    temp->data.answer[1]='\0';
    temp->data.question[0]='0';
    temp->data.question[1]='\0';
    FILE *fp;
    fp = fopen("C:/Users/28207/Desktop/学生管理系统账号密码.txt", "ab");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        Sleep(1000);
        free(temp);
        system("cls");
        return;
    }
    fwrite(&temp->data, sizeof(student), 1, fp);
    fclose(fp);
    printf("添加成功！\n");
    int chose = 0;
    printf("返回上一页请按1，结束输入请按任意键");
    scanf("%d",&chose);
    if(chose==1)
    {
        system("cls");
        adMenue();
    }
    exit(0);
}
void delId() {
    daoRuId();
    char id[20];
    printf("请输入你要删除的账户：");
    scanf("%s", id);
    if (strcmp(id,usrid)==0)
    {
        printf("无法删除自身账号\n");
        int chose = 0;
        printf("返回上一页请按1，结束输入请按任意键：");
        scanf("%d", &chose);
        if (chose == 1) {
            system("cls");
            adMenue();
        }
        exit(0);
    }
    Nodeid *p = head;
    Nodeid *q = NULL;
    while (p != NULL) {
        if (strcmp(p->data.id, id) == 0) {
            if (q == NULL) {
                head = p->next;
            } else {
                q->next = p->next;
            }
            free(p);
            printf("删除账号成功！\n");
            daoChuId();
            int chose = 0;
            printf("返回上一页请按1，结束输入请按任意键：");
            scanf("%d", &chose);
            if (chose == 1) {
                adMenue();
            }else
            {
                exit(0);
            }
        }
        q = p;
        p = p->next;
    }
    printf("此账号不存在！\n");
    int chose = 0;
    printf("返回上一页请按1，结束输入请按任意键：");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        adMenue();
    }
    exit(0);
}
void chagId()
{
    char id[20];
    daoRuId();
    Nodeid *p = head;
    printf("欢迎来到账户信息修改页面\n");
    printf("请输入要更改的账号：");
    scanf("%s",id);
    while (p != NULL)
    {
        if (strcmp(p->data.id, id) == 0)
        {
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("此账号不存在！\n");

    }else
    {
        printf("请输入新账号：");
    scanf("%s",p->data.id);
    printf("请输入新密码：");
    scanf("%s",p->data.password);
    daoChuId();
        printf("修改账号成功!\n");
    }
    int chose = 0;
    printf("返回上一页请按1，结束输入请按任意键：");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        adMenue();
    }
    exit(0);
}
void lookId()
{
    daoRuId();
    Nodeid *p = head;
    char id[20];
    printf("请输入要查看的账号：");
    scanf("%s",id);
    while (p!=NULL)
    {
        if (strcmp(p->data.id, id) == 0)
        {
            printf("账号：%s\n",p->data.id);
            printf("密码：%s\n",p->data.password);
            int chose = 0;
            printf("返回上一页请按1，结束输入请按任意键：");
            scanf("%d", &chose);
            if (chose == 1) {
                system("cls");
                adMenue();
            }else
            {
                exit(0);
            }
        }
        p = p->next;
    }
    printf("此账号不存在！\n");
    int chose = 0;
    printf("返回上一页请按1，结束输入请按任意键：");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        adMenue();
    }
    exit(0);
}
