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
        printf("��ʾ���û������Զ��ض���19�ַ�\n");
    }
}
void input_question(char* question)
{
    safe_input(question,20,0);
    if (strlen(question)==19)
    {
        printf("��ʾ����ȫ�������Զ��ض���19�ַ�\n");
    }
}
void input_answer(char* answer)
{
    safe_input(answer,20,0);
    if (strlen(answer)==19)
    {
        printf("��ʾ����ȫ�����Զ��ض���19�ַ�\n");
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
    printf("�����˺ţ�\n");
    input_username(users.id);
    printf("�������룺\n");
    fflush(stdin);
    input_password(users.password);
    FILE*fp=fopen("C:/Users/28207/Desktop/ѧ������ϵͳ�˺�����.txt","rb");
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
            printf("�˺Ż��������");
            Sleep(1000);
            system("cls");
            fclose(fp);
            Main();
        }
    }
    if (duRu.shenfen!=shenfen)
    {
        printf("\n");
        printf("�Ƿ���¼��\n");
        Sleep(1000);
        system("cls");
        fclose(fp);
        Main();
    }
    if(strcmp(duRu.password,users.password)==0)
    {
        printf("\n");
        printf("��¼�ɹ�\n");
        strcpy(usrid,users.id);
        Sleep(1000);
        system("cls");
        fclose(fp);
    }else
    {
        printf("\n");
        printf("�������\n");
        fclose(fp);
        system("cls");
        Main();
    }
}
void aboutUpdataPage()
{
    printf("\n\n\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t**************ѧ����Ϣ����ϵͳ***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.ѧ����¼~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.��ʦ��¼~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.����Ա��¼~~~~~~~~~~~~~~~~\n");
    printf("\t\t                                             \n");
    scanf("%d",&shenfen);
    if(shenfen!=1&&shenfen!=2&&shenfen!=3)
    {
        printf("�����ڸ÷���");
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
        printf("\t\t**************ѧ����Ϣ����ϵͳ***************\n");
        printf("\t\t              ----------------               \n");
        printf("\t\t                                             \n");
        printf("\t\t~~~~~~~~~~~~~~~1.�˺����~~~~~~~~~~~~~~~~\n");
        printf("\t\t~~~~~~~~~~~~~~~2.��½����~~~~~~~~~~~~~~~~\n");
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
        printf("�����ڸ÷���\n");
        Sleep(1000);
        system("cls");
        mainPage();
    }
}
void xiugai()
{
    printf("��ӭ���������޸Ľ���\n");
    FILE*fp;
    fp=fopen("C:/Users/28207/Desktop/ѧ������ϵͳ�˺�����.txt","rb+");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    fseek(fp,0,SEEK_SET);
    user duRu;
    user users;
    printf("�������˺ţ�");
    input_username(users.id);
    while(1)
    {
        fread(&duRu,sizeof(duRu),1,fp);
        if(!strcmp(duRu.id,users.id))
        {
            break;
        }
    }
    printf("������ԭ���룺");
    input_password(users.password);
    if(strcmp(users.password,duRu.password))
    {
        printf("�������");
        system("cls");
        Main();
    }
    printf("�������޸ĺ�����룺");
    char c[20];
    scanf("%s",&c);
    strcpy(duRu.password,c);
    fseek(fp,-80,SEEK_CUR);
    fwrite(&duRu,sizeof(duRu),1,fp);
    printf("�����޸ĳɹ��������µ�¼��\n");
    system("cls");
    fclose(fp);
    Main();
}
void zhaohui()
{
    printf("��ӭ���������һؽ���\n");
    FILE*fp;
    user duRu;
    user users;
    fp=fopen("C:/Users/28207/Desktop/ѧ������ϵͳ�˺�����.txt","ab+");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    printf("�������˺ţ�");
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
            printf("���˺Ų�����\n");
            Sleep(1000);
            fclose(fp);
            system("cls");
            Main();
        }
    }
    printf("��ش���֤���⣺%s\n",duRu.question);
    input_answer(users.answer);
    fclose(fp);
    if(strcmp(duRu.answer,users.answer))
    {
        printf("�ش����");
        Sleep(1000);
        system("cls");
        Main();
    }else
    {
        printf("�ش���ȷ�����������ǣ�%s",duRu.password);
        Sleep(1000);
        system("cls");
        Main();
    }

}
void zhuCe()
{
    printf("��ӭ����ע�����\n");
    FILE*fp;
    user duRu;
    user users;
    fp=fopen("C:/Users/28207/Desktop/ѧ������ϵͳ�˺�����.txt","ab+");
    printf("�������˺ţ�\n");
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
                printf("�˺��Ѵ���");
                Sleep(1000);
                system("cls");
                Main();
                fclose(fp);
            }
        }
    }
    printf("���������룺\n");
    input_password(users.password);
    printf("�����밲ȫ���⣺\n");
    input_question(users.question);
    printf("�����밲ȫ�𰸣�\n");
    input_answer(users.answer);
    printf("��ѡ��ע�����ݣ�\n");
    printf("\t\t~~~~~~~~~~~~~~~1.ѧ��~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.��ʦ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.����Ա~~~~~~~~~~~~~~~~\n");
    int n;
    scanf("%d",&n);
    if (n==1||n==2||n==3)
    {
        users.shenfen=n;
    }else
    {
        printf("û�д���ݣ�\n");
        system("cls");
        zhuCe();
    }
    printf("ע��ɹ�\n");
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
    printf("\t\t**************ѧ����Ϣ����ϵͳ***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.�����һ�~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.�����޸�~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.�˻�ע��~~~~~~~~~~~~~~~~\n");
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
        printf("�����ڸ÷���\n");
        exit(0);
    }
}