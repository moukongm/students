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
    printf("\t\t**************ѧ����Ϣ����ϵͳ***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.�鿴����   ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.�����˺�����~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.ɾ���˺�����~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~4.�޸��˺�����~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~5.�鿴�˺�����~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~6.¼���˺�����~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~7.�����˺�����~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~8.��¼��ʦ��  ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~9.������һ��  ~~~~~~~~~~~~~~~~\n");
    printf("\t\t                                             \n");
    scanf("%d",&choice);
    if(choice==1)
    {
          system("cls");
            loadTodos();
            if (todoHead == NULL) {
                printf("��ǰû�д������\n");
                return;
            }

            printf("��ǰ���������б�\n");
            TodoNode *temp = todoHead;
            while (temp != NULL) {
                printf("ID: %d\n", temp->data.id);
                printf("����: %s\n", temp->data.description);
                printf("״̬: %s\n", temp->data.status);
                printf("----------------------------\n");
                temp = temp->next;
                system("cls");
            }
            int choice;
            printf("������һҳ�밴1���˳��밴�������");
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
        printf("������һҳ�밴1�����������밴�������");
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
        printf("������һҳ�밴1�����������밴�������");
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
    printf("�������˺ţ�");
    scanf("%s",temp->data.id);
    printf("���������룺");
    scanf("%s",temp->data.password);
   temp->data.answer[0]='0';
    temp->data.answer[1]='\0';
    temp->data.question[0]='0';
    temp->data.question[1]='\0';
    FILE *fp;
    fp = fopen("C:/Users/28207/Desktop/ѧ������ϵͳ�˺�����.txt", "ab");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        Sleep(1000);
        free(temp);
        system("cls");
        return;
    }
    fwrite(&temp->data, sizeof(student), 1, fp);
    fclose(fp);
    printf("��ӳɹ���\n");
    int chose = 0;
    printf("������һҳ�밴1�����������밴�����");
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
    printf("��������Ҫɾ�����˻���");
    scanf("%s", id);
    if (strcmp(id,usrid)==0)
    {
        printf("�޷�ɾ�������˺�\n");
        int chose = 0;
        printf("������һҳ�밴1�����������밴�������");
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
            printf("ɾ���˺ųɹ���\n");
            daoChuId();
            int chose = 0;
            printf("������һҳ�밴1�����������밴�������");
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
    printf("���˺Ų����ڣ�\n");
    int chose = 0;
    printf("������һҳ�밴1�����������밴�������");
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
    printf("��ӭ�����˻���Ϣ�޸�ҳ��\n");
    printf("������Ҫ���ĵ��˺ţ�");
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
        printf("���˺Ų����ڣ�\n");

    }else
    {
        printf("���������˺ţ�");
    scanf("%s",p->data.id);
    printf("�����������룺");
    scanf("%s",p->data.password);
    daoChuId();
        printf("�޸��˺ųɹ�!\n");
    }
    int chose = 0;
    printf("������һҳ�밴1�����������밴�������");
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
    printf("������Ҫ�鿴���˺ţ�");
    scanf("%s",id);
    while (p!=NULL)
    {
        if (strcmp(p->data.id, id) == 0)
        {
            printf("�˺ţ�%s\n",p->data.id);
            printf("���룺%s\n",p->data.password);
            int chose = 0;
            printf("������һҳ�밴1�����������밴�������");
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
    printf("���˺Ų����ڣ�\n");
    int chose = 0;
    printf("������һҳ�밴1�����������밴�������");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        adMenue();
    }
    exit(0);
}
