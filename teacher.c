//
// Created by 28207 on 25-4-8.
//

#include "teacher.h"
#include "students.h"
#include "ad.h"
#include "all.h"
extern int  choice;
extern int  shenfen;
extern char  usrid[20];
extern Nodeid *head;
extern Nodes*head1;
extern TodoNode *todoHead;
void teaMenue()
{
    printf("\n\n\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t**************学生信息管理系统***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.增加学生信息~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.删除学生信息~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.修改学生信息~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~4.查看学生信息~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~5.查看班内成绩~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~6.导出学生成绩~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~7.查看班内成绩分析 ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~8.返回上一层 ~~~~~~~~~~~~~~~~\n");
    printf("\t\t                                             \n");
    scanf("%d",&choice);
    if(choice==5)
    {
        system("cls");
        sortStudentsByNumber();
        classScore();
    }else if(choice==8&&shenfen==2)
    {
        system("cls");
        Main();
    }else if(choice==8&&shenfen==3)
    {
        system("cls");
        adMenue();
    }else if(choice==1)
    {
        system("cls");
        adStudent();
        sortStudentsByNumber();
    }else if(choice==2)
    {
        system("cls");
        delStudent();
    }else if(choice==3)
    {
        system("cls");
        changeStudent();
    }else if(choice==4)
    {
        system("cls");
        lookStudent();
    }else if(choice==7)
    {
        system("cls");
        classScores();
    }else if(choice==6)
    {
        system("cls");
        daoChus();
        int chose = 0;
        printf("返回上一页请按1，结束输入请按任意键：");
        scanf("%d", &chose);
        if (chose == 1) {
            system("cls");
            adMenue();
        }
        exit(0);
    }
}
void sortStudentsByNumber() {
    daoRus();
    if (head1 == NULL || head1->next == NULL) {
        return;
    }
    int swapped;
    Nodes *ptr1;
    Nodes *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head1;
        while (ptr1->next != lptr) {
            if (ptr1->data.num > ptr1->next->data.num) {
                student temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    daoChus();
}
void adStudent()
{
    daoRus();
    Nodes *temp = (Nodes *)malloc(sizeof(Nodes));
    temp->next = NULL;
    printf("请输入学号：");
    scanf("%d", &temp->data.num);
    getchar();
    char name[20];
    printf("请输入姓名：");
    safeInput(name, 19, "姓名");
    strcpy(temp->data.name, name);
    char clas[20];
    printf("请输入班级：");
    safeInput(clas, 19, "班级");
    strcpy(temp->data.clas, clas);
    char sex[5];
    printf("请输入性别：");
    safeInput(sex, 4, "性别");
    strcpy(temp->data.sex, sex);
    printf("请输入英语成绩：");
    scanf("%f", &temp->data.engScore);
    printf("请输入c语言成绩：");
    scanf("%f", &temp->data.cScore);
    temp->data.total = temp->data.cScore + temp->data.engScore;
    engLevel(temp->data.clas, temp);
    cLevel(temp->data.clas, temp);
    Level(temp->data.clas, temp);
    int position;
    printf("请选择插入位置：\n");
    printf("1. 插入到链表头部\n");
    printf("2. 插入到链表尾部\n");
    printf("3. 插入到指定位置\n");
    scanf("%d", &position);
    if (position == 1) {
        temp->next = head1;
        head1 = temp;
    } else if (position == 2) {
        if (head1 == NULL) {
            head1 = temp;
        } else {
            Nodes *current = head1;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    } else if (position == 3){
        int index;
        printf("请输入要插入的位置（从1开始）：");
        scanf("%d", &index);
        if (index == 1) {
            temp->next = head1;
            head1 = temp;
        } else {
            Nodes *current = head1;
            for (int i = 1; i < index - 1 && current != NULL; i++) {
                current = current->next;
            }
            if (current == NULL) {
                printf("插入位置超出链表长度，将插入到链表尾部。\n");
                current = head1;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = temp;
            } else {
                temp->next = current->next;
                current->next = temp;
            }
        }
    } else {
        printf("无效的选择，将默认插入到链表尾部。\n");
        if (head1 == NULL) {
            head1 = temp;
        } else {
            Nodes *current = head1;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }
    daoChus();
    printf("学生信息添加成功！\n");
    int chose = 0;
    printf("返回上一页请按1，结束输入请按任意键：");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        teaMenue();
    } else {
        exit(0);
    }
}
void delStudent()
{
    daoRus();
    int num;
    printf("请输入你要删除的学生学号：");
    scanf("%d", &num);
    Nodes *p = head1;
    Nodes *q = NULL;
    while (p != NULL) {
        if (num == p->data.num) {
            if (q == NULL) {
                head1 = p->next;
            } else {
                q->next = p->next;
            }
            free(p);
            printf("删除学生信息成功！\n");
            daoChus();
            freeStudentList();
            int chose = 0;
            printf("返回上一页请按1，结束输入请按任意键：");
            scanf("%d", &chose);
            if (chose == 1) {
                system("cls");
                teaMenue();
            }else
            {
                exit(0);
            }
        }
        q = p;
        p = p->next;
    }
    printf("此学号不存在！\n");
    freeStudentList();
    int chose = 0;
    printf("返回上一页请按1，结束输入请按任意键：");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        teaMenue();
    }
    exit(0);
}
void changeStudent()
{
    daoRus();
    Nodes *p = head1;
    int num;
    printf("欢迎来到学生信息修改页面\n");
    printf("请输入要更改的学生学号：");
    scanf("%d",&num);
    while (p != NULL)
    {
        if (p->data.num == num)
        {
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("此学号不存在！\n");
        freeStudentList();
    }else
    {
        printf("请输入修改后学号：");
        scanf("%d",&p->data.num);
        getchar();
        char name[20];
        printf("请输入修改后姓名：");
        safeInput(name, 19, "姓名");
        strcpy(p->data.name, name);
        char clas[20];
        printf("请输入修改后班级：");
        safeInput(clas, 19, "班级");
        strcpy(p->data.clas, clas);
        char sex[5];
        printf("请输入修改后性别：");
        safeInput(sex, 4, "性别");
        strcpy(p->data.sex, sex);
        printf("请输入修改后英语成绩：");
        scanf("%f",&p->data.engScore);
        printf("请输入修改后c语言成绩：");
        scanf("%f",&p->data.cScore);
        p->data.total=p->data.cScore+p->data.engScore;
        engLevel(p->data.clas,p);
        cLevel(p->data.clas,p);
        Level(p->data.clas,p);
        daoChus();
        printf("修改账号成功!\n");
    }
    freeStudentList();
    int chose = 0;
    printf("返回上一页请按1，结束输入请按任意键：");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        teaMenue();
    }
    exit(0);
}
void lookStudent()
{
    daoRus();
    Nodes *p = head1;
    int num;
    printf("请输入要查看的学号：");
    scanf("%d",&num);
    while (p!=NULL)
    {
        if (p->data.num == num)
        {
            printf("学号：%d\n",p->data.num);
            printf("姓名：%s\n",p->data.name);
            printf("班级：%s\n",p->data.clas);
            printf("性别：%s\n",p->data.sex);
            printf("英语成绩：%.2f\n",p->data.engScore);
            printf("英语排名：%d\n",p->data.engLevel);
            printf("c语言成绩：%.2f\n",p->data.cScore);
            printf("c语言排名：%d\n",p->data.cLevel);
            printf("总成绩：%.2f\n",p->data.total);
            printf("总排名：%d\n",p->data.lev);
            freeStudentList();
            int chose = 0;
            printf("返回上一页请按1，结束输入请按任意键：");
            scanf("%d", &chose);
            if (chose == 1) {
                system("cls");
                teaMenue();
            }else
            {
                exit(0);
            }
        }
        p = p->next;
    }
    printf("此学号不存在！\n");
    freeStudentList();
    int chose = 0;
    printf("返回上一页请按1，结束输入请按任意键：");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        teaMenue();
    }
    exit(0);
}
void classScore()
{
    printf("欢迎查询班内成绩！\n请输入您要查询的班级：");
    char cl[20];
    scanf("%s",&cl);
    FILE*fp;
    fp=fopen("C:/Users/28207/Desktop/学生信息.txt","r");
    if(feof(fp))
    {
        printf("此班级不存在！");
        exit(0);
    }
    Node *head = NULL;
    Node *tail = NULL;
    while (1) {
        Node *temp = (Node *)malloc(sizeof(Node));
        if (fread(&temp->data, sizeof(student), 1, fp) != 1) {
            free(temp);
            break;
        }
        if (strcmp(temp->data.clas, cl) == 0) {
            temp->next = NULL;
            temp->prev = tail;

            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        } else {
            free(temp);
        }
    }
    fclose(fp);
    if (head == NULL) {
        printf("此班级不存在或没有学生信息！\n");
        Sleep(1000);
        system("cls");
        return;
    }
    Node *now=head;
    while(now!=NULL)
    {
        printf("学号：%d 姓名:%s 班级：%s 英语成绩：%.2lf c语言成绩：%.2f 总成绩：%.2f\n",now->data.num,now->data.name,now->data.clas,now->data.engScore,now->data.cScore,now->data.total);
        int choose;
        printf("输入1显示上一页，输入2显示下一页");
        scanf("%d",&choose);
        if(choose==1)
        {
            now=now->prev;
        }else if(choose==2)
        {
            now=now->next;
        }else
        {
            printf("无效指令");
        }
    }
    int choose;
    printf("输入1返回上一页，输入其它退出登录");
    scanf("%d",&choose);
    if(choose==1&&shenfen==1)
    {
        system("cls");
        stuMenue();
    }else if(choose==1&&shenfen==2)
    {
        system("cls");
        teaMenue();
    }else
    {
        exit(0);
    }
}