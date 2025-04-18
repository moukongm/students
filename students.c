//
// Created by 28207 on 25-4-8.
//

#include "students.h"
#include "teacher.h"
#include "all.h"
extern int choice;
extern int  shenfen;
extern char  usrid[20];
extern Nodeid *head;
extern Nodes*head1;
extern TodoNode *todoHead;
void stuMenue()
{
    printf("\n\n\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t**************学生信息管理系统***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.成绩查询   ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.查询本班成绩~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.成绩分析~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~4.成绩申诉~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~5.返回上一层  ~~~~~~~~~~~~~~~~\n");
    printf("\t\t                                             \n");
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        mineScore();
    }else if(choice==2)
    {
        system("cls");
        classScores();
    }else if(choice==5)
    {
        system("cls");
        Main();
    }else if(choice==3)
    {
        system("cls");
        levelLook();
    }else if(choice==4)
    {
        int studentId;
        printf("请输入您的学号：");
        scanf("%d", &studentId);
        system("cls");
        submitAppeal(studentId);
    }
}
void mineScore()
{
    printf("欢迎来到成绩查询界面！\n请输入您的学号：");
    int number;
    scanf("%d",&number);
    FILE *fp;
    student duRu;
    fp=fopen("C:/Users/28207/Desktop/学生信息.txt","r");
    if(fp==NULL)
    {
        printf("此学号不存在！");
        fclose(fp);
        return;
    }
    while(!feof(fp))
    {
        fread(&duRu,sizeof(student),1,fp);
        if(number==duRu.num)
        {
            break;
        }else if(feof(fp))
        {
            printf("此学号不存在！");
            fclose(fp);
            Sleep(1000);
            system("cls");
            mineScore();
        }
    }
    printf("您的英语成绩为：%.2lf\n",duRu.engScore);
    printf("您的c语言成绩为:%.2lf\n",duRu.cScore);
    printf("您的总成绩为:%.2lf\n",duRu.total);
    fclose(fp);
    printf("返回上一层请按1，退出登录请按2\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        stuMenue();
    }else if(choice==2)
    {
        printf("欢迎下次使用");
        exit(0);
    }else
    {
        printf("不存在该服务\n");
        exit(0);
    }
}
void levelLook()
{
    printf("欢迎来到成绩分析界面！\n请输入您的学号：");
    int number;
    scanf("%d",&number);
    FILE *fp;
    student duRu;
    fp=fopen("C:/Users/28207/Desktop/学生信息.txt","r");
    if(fp==NULL)
    {
        printf("此学号不存在！");
        fclose(fp);
        exit(0);
    }
    while(!feof(fp))
    {
        fread(&duRu,sizeof(student),1,fp);
        if(number==duRu.num)
        {
            break;
        }else if (feof(fp))
        {
            printf("此学号不存在！");
            Sleep(1000);
            system("cls");
            fclose(fp);
            mineScore();
        }
    }
    printf("您的英语排名为：%.d\n",duRu.engLevel);
    printf("您的c语言排名为:%.d\n",duRu.cLevel);
    printf("您的总排名为:%.d\n",duRu.lev);
    fclose(fp);
    printf("返回上一层请按1，退出登录请按2\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        stuMenue();
    }else if(choice==2)
    {
        printf("欢迎下次使用");
        exit(0);
    }else
    {
        printf("不存在该服务\n");
        exit(0);
    }
}
void classScores()
{
    printf("欢迎来到本班成绩统计页面，请输入您要查询的班级：");
    char className[20];
    scanf("%s",className);
    FILE *fp;
    fp=fopen("C:/Users/28207/Desktop/学生信息.txt","rb+");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    student s;
    Nodes *head2;
    head2=NULL;
    while (fread(&s, sizeof(student), 1, fp))
    {
        if(strcmp(s.clas,className)==0)
        {
            Nodes *temp=(Nodes*)malloc(sizeof(Nodes));
            temp->next=NULL;
            temp->data=s;
            if(head2==NULL)
            {
                head2=temp;
            }else
            {
                temp->next=head2;
                head2=temp;
            }
        }
    }
    fclose(fp);
    Nodes *temp=head2;
    int count = 0;
    float totalScore = 0.0;
    float maxScore = -1.0;
    float minScore = 101.0;
    float engTotalScore = 0.0;
    float engMaxScore = -1.0;
    float engMinScore = 101.0;
    float cTotalScore = 0.0;
    float cMaxScore = -1.0;
    float cMinScore = 101.0;
    while (temp!=NULL)
    {
        count++;
        totalScore+=temp->data.total;
        engTotalScore+=temp->data.engScore;
        cTotalScore+=temp->data.cScore;
        if (temp->data.total>maxScore)
        {
            maxScore=temp->data.total;
        }
        if (temp->data.total<minScore)
        {
            minScore=temp->data.total;
        }
        if (temp->data.cScore>cMaxScore)
        {
            cMaxScore=temp->data.cScore;
        }
        if (temp->data.cScore<cMinScore)
        {
            cMinScore=temp->data.cScore;
        }
        if (temp->data.engScore>engMaxScore)
        {
            engMaxScore=temp->data.engScore;
        }
        if (temp->data.engScore<engMinScore)
        {
            engMinScore=temp->data.engScore;
        }
        temp=temp->next;
    }
    if (count > 0) {
        printf("班级 %s 的成绩分析:\n", className);
        printf("学生总数: %d\n", count);
        printf("平均英语成绩: %.2f\n", engTotalScore / count);
        printf("最高英语成绩: %.2f\n", engMaxScore);
        printf("最低英语成绩: %.2f\n", engMinScore);
        printf("平均c语言成绩: %.2f\n", cTotalScore / count);
        printf("最高c语言成绩: %.2f\n", cMaxScore);
        printf("最低c语言成绩: %.2f\n", cMinScore);
        printf("平均成绩: %.2f\n", totalScore / count);
        printf("最高成绩: %.2f\n", maxScore);
        printf("最低成绩: %.2f\n", minScore);
        int chose = 0;
        printf("返回上一页请按1，结束输入请按任意键");
        scanf("%d",&chose);
        if(chose==1&&shenfen==1)
        {
            system("cls");
            stuMenue();
        }else if(chose==1&&shenfen==2)
        {
            system("cls");
            teaMenue();
        }
        exit(0);
    } else {
        printf("未找到班级 %s 的学生\n", className);
        int chose = 0;
        printf("返回上一页请按1，结束输入请按任意键");
        scanf("%d",&chose);
        if(chose==1&&shenfen==1)
        {
            system("cls");
            stuMenue();
        }else if(chose==1&&shenfen==2)
        {
            system("cls");
            teaMenue();
        }
        exit(0);
    }
}
void submitAppeal(int studentId) {
    loadTodos();
    Todo todo;
    todo.id=studentId;
    printf("请输入您的申诉描述（200字以内）：\n");
    getchar();
    fgets(todo.description, sizeof(todo.description), stdin);
    strcpy(todo.status, "待处理");
    TodoNode *temp = (TodoNode *)malloc(sizeof(TodoNode));
    temp->data = todo;
    temp->next = todoHead;
    todoHead = temp;
    saveTodos();
    printf("申诉提交成功！\n");
    int choice;
    printf("返回上一页请按1，退出请按任意键：");
    scanf("%d", &choice);
    if (choice == 1) {
        system("cls");
        stuMenue();
    } else {
        exit(0);
    }
}