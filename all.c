//
// Created by 28207 on 25-4-8.
//

#include "all.h"
#include "ad.h"
#include "students.h"
#include "teacher.h"
#include "zhanghao.h"
int choice=0;
int shenfen=0;
char usrid[20];
Nodeid *head;
Nodes*head1;
TodoNode *todoHead = NULL;
int validateInputLength(char *input, int maxLength, const char *fieldName) {
    if (strlen(input) > maxLength) {
        printf("%s 的长度不能超过 %d 个字符，请重新输入：\n", fieldName, maxLength);
        return 0;
    }
    return 1;
}
void safeInput(char *buffer, int maxLength, const char *fieldName) {
    while (1) {
        fgets(buffer, maxLength + 1, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (validateInputLength(buffer, maxLength, fieldName)) {
            break;
        }
    }
}
void freeTodoList() {
    TodoNode *temp = todoHead;
    while (temp != NULL) {
        TodoNode *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    todoHead = NULL;
}

void freeStudentList() {
    Nodes *temp = head1;
    while (temp != NULL) {
        Nodes *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    head1 = NULL;
}

void freeUserList() {
    Nodeid *temp = head;
    while (temp != NULL) {
        Nodeid *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    head = NULL;
}
void loadTodos() {
    FILE *fp = fopen("C:/Users/28207/Desktop/待办事项.txt", "rb");
    if (fp == NULL) {
        printf("待办事项文件打开失败！\n");
        return;
    }
    Todo todo;
    while (fread(&todo, sizeof(Todo), 1, fp)) {
        TodoNode *temp = (TodoNode *)malloc(sizeof(TodoNode));
        temp->data = todo;
        temp->next = NULL;
        if (todoHead == NULL) {
            todoHead = temp;
        } else {
            temp->next = todoHead;
            todoHead = temp;
        }
    }
    fclose(fp);
}
void saveTodos() {
    FILE *fp = fopen("C:/Users/28207/Desktop/待办事项.txt", "wb");
    if (fp == NULL) {
        printf("待办事项文件保存失败！\n");
        return;
    }
    TodoNode *temp = todoHead;
    while (temp != NULL) {
        fwrite(&temp->data, sizeof(Todo), 1, fp);
        temp = temp->next;
    }
    temp=todoHead;
    while (temp != NULL) {
        TodoNode *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    todoHead = NULL;
    fclose(fp);
    printf("待办事项保存成功！\n");
}
void daoRus()
{
    FILE *fp;
    fp=fopen("C:/Users/28207/Desktop/学生信息.txt","rb+");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    Nodes node;
    while (fread(&node.data, sizeof(student), 1, fp))
    {
        Nodes *temp=(Nodes*)malloc(sizeof(Nodes));
        temp->next=NULL;
        memcpy(temp,&node,sizeof(Nodes));
        if(head1==NULL)
        {
            head1=temp;
        }else
        {
            temp->next=head1;
            head1=temp;
        }
    }
    fclose(fp);
}
void daoChus()
{
    FILE *fp;
    fp=fopen("C:/Users/28207/Desktop/学生信息.txt","wb+");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    Nodes*temp=head1;
    while(temp!=NULL)
    {
        fwrite(&temp->data,sizeof(student),1,fp);
        temp=temp->next;
    }
    fclose(fp);
    printf("文件保存成功!\n");
    freeStudentList();
}
void engLevel(char* class,Nodes *node)
{
    Nodes* temp=head1;
    int cont=1;
    while(temp!=NULL)
    {
        if(strcmp(temp->data.clas,class)==0)
        {
            if(temp->data.engScore>node->data.engScore)
            {
                cont++;
            }
        }
        temp=temp->next;
    }
    node->data.engLevel=cont;
}
void cLevel(char* class,Nodes *node)
{
    Nodes* temp=head1;
    int cont=1;
    while(temp!=NULL)
    {
        if(strcmp(temp->data.clas,class)==0)
        {
            if(temp->data.cScore>node->data.cScore)
            {
                cont++;
            }
        }
        temp=temp->next;
    }
    node->data.cLevel=cont;
}
void Level(char* class,Nodes *node)
{
    Nodes* temp=head1;
    int cont=1;
    while(temp!=NULL)
    {
        if(strcmp(temp->data.clas,class)==0)
        {
            if(temp->data.total>node->data.total)
            {
                cont++;
            }
        }
        temp=temp->next;
    }
    node->data.lev=cont;
}
void daoRuId()
{
    FILE *fp;
    fp=fopen("C:/Users/28207/Desktop/学生管理系统账号密码.txt","rb+");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    Nodeid node;
    while(fread(&node,sizeof(user),1,fp))
    {
        Nodeid *temp=malloc(sizeof(Nodeid));
        temp->next=NULL;
        memcpy(temp,&node,sizeof(Nodeid));
        if(head==NULL)
        {
            head=temp;
        }else
        {
            temp->next=head;
            head=temp;
        }
    }
    fclose(fp);
}
void daoChuId()
{
    FILE *fp;
    Nodeid *temp1=head;
    fp=fopen("C:/Users/28207/Desktop/学生管理系统账号密码.txt","wb+");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    while(temp1!=NULL)
    {
        fwrite(&temp1->data,sizeof(user),1,fp);
        temp1=temp1->next;
    }
    fflush(fp);
    fclose(fp);
    printf("文件保存成功!\n");
}
int Main()
{
    mainPage();
    if(shenfen==1)
    {
        stuMenue();
    }else if(shenfen==2)
    {
        teaMenue();
    }else if(shenfen==3)
    {
        adMenue();
    }
    mainPage();
    freeTodoList();
    freeStudentList();
    freeUserList();
    return 0;
}