//
// Created by 28207 on 25-4-8.
//

#include "zhanghao.h"
#include "all.h"
#define BACKSPACE 0x08
extern int  choice;
extern int  shenfen;
extern char  usrid[20];
extern Nodeid *head;
extern Nodes*head1;
extern TodoNode *todoHead;
void safe_input(char *buffer,int max_len,int is_password)
{
    int i=0;
    char ch;
    while (1)
    {
        ch=getch();
        if (ch=='\r'||ch=='\n')
        {
            printf("\n");
            break;
        }
        if (ch=='\b')
        {
            if (i>0)
            {
                i--;
                printf("\b \b");
            }
            continue;
        }
        if (i<max_len-1)
        {
            buffer[i++]=ch;
            printf(is_password ? "*" : "%c",ch);
        }
        if (i==max_len-1)
        {
            printf("\n");
            break;
        }
    }
    buffer[i]='\0';
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
void input_username(char* username)
{
    safe_input(username,20,0);
    if (strlen(username)==19)
    {
        printf("提示：用户名已自动截断至19字符\n");
    }
}
void input_question(char* question)
{
    safe_input(question,20,0);
    if (strlen(question)==19)
    {
        printf("提示：安全问题已自动截断至19字符\n");
    }
}
void input_answer(char* answer)
{
    safe_input(answer,20,0);
    if (strlen(answer)==19)
    {
        printf("提示：安全答案已自动截断至19字符\n");
    }
}
void input_password(char* password)
{
    safe_input(password,20,1);
}
void updataPage()
{
    user users;
    user duRu;
    fflush(stdin);
    printf("输入账号：\n");
    input_username(users.id);
    printf("输入密码：\n");
    fflush(stdin);
    input_password(users.password);
    FILE*fp=fopen("C:/Users/28207/Desktop/学生管理系统账号密码.txt","rb");
    while(1)
    {
        fread(&duRu,sizeof(users),1,fp);
        if(strcmp(users.id,duRu.id)==0)
        {
            break;
        }
        if(feof(fp))
        {
            printf("\n");
            printf("账号或密码错误");
            Sleep(1000);
            system("cls");
            fclose(fp);
            Main();
        }
    }
    if (duRu.shenfen!=shenfen)
    {
        printf("\n");
        printf("非法登录！\n");
        Sleep(1000);
        system("cls");
        fclose(fp);
        Main();
    }
    if(strcmp(duRu.password,users.password)==0)
    {
        printf("\n");
        printf("登录成功\n");
        strcpy(usrid,users.id);
        Sleep(1000);
        system("cls");
        fclose(fp);
    }else
    {
        printf("\n");
        printf("密码错误\n");
        fclose(fp);
        system("cls");
        Main();
    }
}
void aboutUpdataPage()
{
    printf("\n\n\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t**************学生信息管理系统***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.学生登录~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.教师登录~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.管理员登录~~~~~~~~~~~~~~~~\n");
    printf("\t\t                                             \n");
    scanf("%d",&shenfen);
    if(shenfen!=1&&shenfen!=2&&shenfen!=3)
    {
        printf("不存在该服务");
        system("cls");
        aboutUpdataPage();

    }
    system("cls");
    updataPage();

}
void mainPage()
{
        printf("\n\n\n");
        printf("\t\t              ----------------               \n");
        printf("\t\t**************学生信息管理系统***************\n");
        printf("\t\t              ----------------               \n");
        printf("\t\t                                             \n");
        printf("\t\t~~~~~~~~~~~~~~~1.账号相关~~~~~~~~~~~~~~~~\n");
        printf("\t\t~~~~~~~~~~~~~~~2.登陆界面~~~~~~~~~~~~~~~~\n");
        printf("\t\t                                             \n");
        fflush(stdin);
        scanf("%d",&choice);
        if(choice==1)
        {
          system("cls");
            aboutDataPage();

        }else if(choice==2){
            system("cls");
            aboutUpdataPage();
            }
    else
    {
        printf("不存在该服务\n");
        Sleep(1000);
        system("cls");
        mainPage();
    }
}
void xiugai()
{
    printf("欢迎来到密码修改界面\n");
    FILE*fp;
    fp=fopen("C:/Users/28207/Desktop/学生管理系统账号密码.txt","rb+");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    fseek(fp,0,SEEK_SET);
    user duRu;
    user users;
    printf("请输入账号：");
    input_username(users.id);
    while(1)
    {
        fread(&duRu,sizeof(duRu),1,fp);
        if(!strcmp(duRu.id,users.id))
        {
            break;
        }
    }
    printf("请输入原密码：");
    input_password(users.password);
    if(strcmp(users.password,duRu.password))
    {
        printf("密码错误！");
        system("cls");
        Main();
    }
    printf("请输入修改后的密码：");
    char c[20];
    scanf("%s",&c);
    strcpy(duRu.password,c);
    fseek(fp,-80,SEEK_CUR);
    fwrite(&duRu,sizeof(duRu),1,fp);
    printf("密码修改成功，请重新登录！\n");
    system("cls");
    fclose(fp);
    Main();
}
void zhaohui()
{
    printf("欢迎来到密码找回界面\n");
    FILE*fp;
    user duRu;
    user users;
    fp=fopen("C:/Users/28207/Desktop/学生管理系统账号密码.txt","ab+");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    printf("请输入账号：");
    input_username(users.id);
    while(1)
    {
        fread(&duRu,sizeof(user),1,fp);
        if(!strcmp(duRu.id,users.id))
        {
            break;
        }
        if(feof(fp))
        {
            printf("此账号不存在\n");
            Sleep(1000);
            fclose(fp);
            system("cls");
            Main();
        }
    }
    printf("请回答验证问题：%s\n",duRu.question);
    input_answer(users.answer);
    fclose(fp);
    if(strcmp(duRu.answer,users.answer))
    {
        printf("回答错误！");
        Sleep(1000);
        system("cls");
        Main();
    }else
    {
        printf("回答正确。您的密码是：%s",duRu.password);
        Sleep(1000);
        system("cls");
        Main();
    }

}
void zhuCe()
{
    printf("欢迎来到注册界面\n");
    FILE*fp;
    user duRu;
    user users;
    fp=fopen("C:/Users/28207/Desktop/学生管理系统账号密码.txt","ab+");
    printf("请设置账号：\n");
    input_username(users.id);
    if(!feof(fp))
    {
        fread(&duRu,sizeof(users),1,fp);
        while(1)
        {
            if(strcmp(duRu.id,users.id))
            {
                if(!feof(fp))
                {
                    fread(&duRu,sizeof(users),1,fp);
                }else
                {
                    break;
                }
            }else
            {
                printf("账号已存在");
                Sleep(1000);
                system("cls");
                Main();
                fclose(fp);
            }
        }
    }
    printf("请输入密码：\n");
    input_password(users.password);
    printf("请输入安全问题：\n");
    input_question(users.question);
    printf("请输入安全答案：\n");
    input_answer(users.answer);
    printf("请选择注册的身份：\n");
    printf("\t\t~~~~~~~~~~~~~~~1.学生~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.教师~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.管理员~~~~~~~~~~~~~~~~\n");
    int n;
    scanf("%d",&n);
    if (n==1||n==2||n==3)
    {
        users.shenfen=n;
    }else
    {
        printf("没有此身份！\n");
        system("cls");
        zhuCe();
    }
    printf("注册成功\n");
    fwrite(&users,sizeof(users),1,fp);
    fclose(fp);
    Sleep(1000);
    system("cls");
    aboutUpdataPage();
}
void aboutDataPage()
{
    printf("\n\n\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t**************学生信息管理系统***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.密码找回~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.密码修改~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.账户注册~~~~~~~~~~~~~~~~\n");
    printf("\t\t                                             \n");
    scanf("%d",&choice);
    if(choice==3)
    {
        system("cls");
        zhuCe();
    }else if(choice==1)
    {
        system("cls");
        zhaohui();
    }else if(choice==2)
    {
        system("cls");
        xiugai();
    }else
    {
        printf("不存在该服务\n");
        exit(0);
    }
}