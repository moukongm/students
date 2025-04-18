//
// Created by 28207 on 25-4-8.
//

#ifndef ALL_H
#define ALL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
typedef struct Student
{
    int num;
    char name[20];
    char clas[20];
    char sex[5];
    float engScore;
    int engLevel;
    float cScore;
    int cLevel;
    float total;
    int lev;
}student;
typedef struct Userdata
{
    char id[20];
    char password[20];
    char question[20];
    char answer[20];
    int shenfen;
}user;
typedef struct node
{
    student data;
    struct node *next;
    struct node *prev;
}Node;
typedef struct nodeId
{
    user data;
    struct nodeId *next;
}Nodeid;
typedef struct nodes
{
    student data;
    struct nodes *next;
}Nodes;
typedef struct Todo {
    int id;
    char description[100];
    char status[20];
} Todo;

typedef struct TodoNode {
    Todo data;
    struct TodoNode *next;
} TodoNode;
int validateInputLength(char *input, int maxLength, const char *fieldName);
void safeInput(char *buffer, int maxLength, const char *fieldName);
void freeTodoList();
void freeStudentList();
void freeUserList();
void loadTodos() ;
void saveTodos();
void daoRus();
void daoChus();
void engLevel(char* class,Nodes *node);
void cLevel(char* class,Nodes *node);
void Level(char* class,Nodes *node);
void daoRuId();
void daoChuId();
int Main();

#endif //ALL_H
