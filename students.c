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
    printf("\t\t**************ѧ����Ϣ����ϵͳ***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.�ɼ���ѯ   ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.��ѯ����ɼ�~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.�ɼ�����~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~4.�ɼ�����~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~5.������һ��  ~~~~~~~~~~~~~~~~\n");
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
        printf("����������ѧ�ţ�");
        scanf("%d", &studentId);
        system("cls");
        submitAppeal(studentId);
    }
}
void mineScore()
{
    printf("��ӭ�����ɼ���ѯ���棡\n����������ѧ�ţ�");
    int number;
    scanf("%d",&number);
    FILE *fp;
    student duRu;
    fp=fopen("C:/Users/28207/Desktop/ѧ����Ϣ.txt","r");
    if(fp==NULL)
    {
        printf("��ѧ�Ų����ڣ�");
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
            printf("��ѧ�Ų����ڣ�");
            fclose(fp);
            Sleep(1000);
            system("cls");
            mineScore();
        }
    }
    printf("����Ӣ��ɼ�Ϊ��%.2lf\n",duRu.engScore);
    printf("����c���Գɼ�Ϊ:%.2lf\n",duRu.cScore);
    printf("�����ܳɼ�Ϊ:%.2lf\n",duRu.total);
    fclose(fp);
    printf("������һ���밴1���˳���¼�밴2\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        stuMenue();
    }else if(choice==2)
    {
        printf("��ӭ�´�ʹ��");
        exit(0);
    }else
    {
        printf("�����ڸ÷���\n");
        exit(0);
    }
}
void levelLook()
{
    printf("��ӭ�����ɼ��������棡\n����������ѧ�ţ�");
    int number;
    scanf("%d",&number);
    FILE *fp;
    student duRu;
    fp=fopen("C:/Users/28207/Desktop/ѧ����Ϣ.txt","r");
    if(fp==NULL)
    {
        printf("��ѧ�Ų����ڣ�");
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
            printf("��ѧ�Ų����ڣ�");
            Sleep(1000);
            system("cls");
            fclose(fp);
            mineScore();
        }
    }
    printf("����Ӣ������Ϊ��%.d\n",duRu.engLevel);
    printf("����c��������Ϊ:%.d\n",duRu.cLevel);
    printf("����������Ϊ:%.d\n",duRu.lev);
    fclose(fp);
    printf("������һ���밴1���˳���¼�밴2\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        stuMenue();
    }else if(choice==2)
    {
        printf("��ӭ�´�ʹ��");
        exit(0);
    }else
    {
        printf("�����ڸ÷���\n");
        exit(0);
    }
}
void classScores()
{
    printf("��ӭ��������ɼ�ͳ��ҳ�棬��������Ҫ��ѯ�İ༶��");
    char className[20];
    scanf("%s",className);
    FILE *fp;
    fp=fopen("C:/Users/28207/Desktop/ѧ����Ϣ.txt","rb+");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
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
        printf("�༶ %s �ĳɼ�����:\n", className);
        printf("ѧ������: %d\n", count);
        printf("ƽ��Ӣ��ɼ�: %.2f\n", engTotalScore / count);
        printf("���Ӣ��ɼ�: %.2f\n", engMaxScore);
        printf("���Ӣ��ɼ�: %.2f\n", engMinScore);
        printf("ƽ��c���Գɼ�: %.2f\n", cTotalScore / count);
        printf("���c���Գɼ�: %.2f\n", cMaxScore);
        printf("���c���Գɼ�: %.2f\n", cMinScore);
        printf("ƽ���ɼ�: %.2f\n", totalScore / count);
        printf("��߳ɼ�: %.2f\n", maxScore);
        printf("��ͳɼ�: %.2f\n", minScore);
        int chose = 0;
        printf("������һҳ�밴1�����������밴�����");
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
        printf("δ�ҵ��༶ %s ��ѧ��\n", className);
        int chose = 0;
        printf("������һҳ�밴1�����������밴�����");
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
    printf("��������������������200�����ڣ���\n");
    getchar();
    fgets(todo.description, sizeof(todo.description), stdin);
    strcpy(todo.status, "������");
    TodoNode *temp = (TodoNode *)malloc(sizeof(TodoNode));
    temp->data = todo;
    temp->next = todoHead;
    todoHead = temp;
    saveTodos();
    printf("�����ύ�ɹ���\n");
    int choice;
    printf("������һҳ�밴1���˳��밴�������");
    scanf("%d", &choice);
    if (choice == 1) {
        system("cls");
        stuMenue();
    } else {
        exit(0);
    }
}