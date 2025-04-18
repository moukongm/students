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
    printf("\t\t**************ѧ����Ϣ����ϵͳ***************\n");
    printf("\t\t              ----------------               \n");
    printf("\t\t                                             \n");
    printf("\t\t~~~~~~~~~~~~~~~1.����ѧ����Ϣ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~2.ɾ��ѧ����Ϣ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~3.�޸�ѧ����Ϣ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~4.�鿴ѧ����Ϣ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~5.�鿴���ڳɼ�~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~6.����ѧ���ɼ�~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~7.�鿴���ڳɼ����� ~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~8.������һ�� ~~~~~~~~~~~~~~~~\n");
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
        printf("������һҳ�밴1�����������밴�������");
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
    printf("������ѧ�ţ�");
    scanf("%d", &temp->data.num);
    getchar();
    char name[20];
    printf("������������");
    safeInput(name, 19, "����");
    strcpy(temp->data.name, name);
    char clas[20];
    printf("������༶��");
    safeInput(clas, 19, "�༶");
    strcpy(temp->data.clas, clas);
    char sex[5];
    printf("�������Ա�");
    safeInput(sex, 4, "�Ա�");
    strcpy(temp->data.sex, sex);
    printf("������Ӣ��ɼ���");
    scanf("%f", &temp->data.engScore);
    printf("������c���Գɼ���");
    scanf("%f", &temp->data.cScore);
    temp->data.total = temp->data.cScore + temp->data.engScore;
    engLevel(temp->data.clas, temp);
    cLevel(temp->data.clas, temp);
    Level(temp->data.clas, temp);
    int position;
    printf("��ѡ�����λ�ã�\n");
    printf("1. ���뵽����ͷ��\n");
    printf("2. ���뵽����β��\n");
    printf("3. ���뵽ָ��λ��\n");
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
        printf("������Ҫ�����λ�ã���1��ʼ����");
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
                printf("����λ�ó��������ȣ������뵽����β����\n");
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
        printf("��Ч��ѡ�񣬽�Ĭ�ϲ��뵽����β����\n");
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
    printf("ѧ����Ϣ��ӳɹ���\n");
    int chose = 0;
    printf("������һҳ�밴1�����������밴�������");
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
    printf("��������Ҫɾ����ѧ��ѧ�ţ�");
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
            printf("ɾ��ѧ����Ϣ�ɹ���\n");
            daoChus();
            freeStudentList();
            int chose = 0;
            printf("������һҳ�밴1�����������밴�������");
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
    printf("��ѧ�Ų����ڣ�\n");
    freeStudentList();
    int chose = 0;
    printf("������һҳ�밴1�����������밴�������");
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
    printf("��ӭ����ѧ����Ϣ�޸�ҳ��\n");
    printf("������Ҫ���ĵ�ѧ��ѧ�ţ�");
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
        printf("��ѧ�Ų����ڣ�\n");
        freeStudentList();
    }else
    {
        printf("�������޸ĺ�ѧ�ţ�");
        scanf("%d",&p->data.num);
        getchar();
        char name[20];
        printf("�������޸ĺ�������");
        safeInput(name, 19, "����");
        strcpy(p->data.name, name);
        char clas[20];
        printf("�������޸ĺ�༶��");
        safeInput(clas, 19, "�༶");
        strcpy(p->data.clas, clas);
        char sex[5];
        printf("�������޸ĺ��Ա�");
        safeInput(sex, 4, "�Ա�");
        strcpy(p->data.sex, sex);
        printf("�������޸ĺ�Ӣ��ɼ���");
        scanf("%f",&p->data.engScore);
        printf("�������޸ĺ�c���Գɼ���");
        scanf("%f",&p->data.cScore);
        p->data.total=p->data.cScore+p->data.engScore;
        engLevel(p->data.clas,p);
        cLevel(p->data.clas,p);
        Level(p->data.clas,p);
        daoChus();
        printf("�޸��˺ųɹ�!\n");
    }
    freeStudentList();
    int chose = 0;
    printf("������һҳ�밴1�����������밴�������");
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
    printf("������Ҫ�鿴��ѧ�ţ�");
    scanf("%d",&num);
    while (p!=NULL)
    {
        if (p->data.num == num)
        {
            printf("ѧ�ţ�%d\n",p->data.num);
            printf("������%s\n",p->data.name);
            printf("�༶��%s\n",p->data.clas);
            printf("�Ա�%s\n",p->data.sex);
            printf("Ӣ��ɼ���%.2f\n",p->data.engScore);
            printf("Ӣ��������%d\n",p->data.engLevel);
            printf("c���Գɼ���%.2f\n",p->data.cScore);
            printf("c����������%d\n",p->data.cLevel);
            printf("�ܳɼ���%.2f\n",p->data.total);
            printf("��������%d\n",p->data.lev);
            freeStudentList();
            int chose = 0;
            printf("������һҳ�밴1�����������밴�������");
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
    printf("��ѧ�Ų����ڣ�\n");
    freeStudentList();
    int chose = 0;
    printf("������һҳ�밴1�����������밴�������");
    scanf("%d", &chose);
    if (chose == 1) {
        system("cls");
        teaMenue();
    }
    exit(0);
}
void classScore()
{
    printf("��ӭ��ѯ���ڳɼ���\n��������Ҫ��ѯ�İ༶��");
    char cl[20];
    scanf("%s",&cl);
    FILE*fp;
    fp=fopen("C:/Users/28207/Desktop/ѧ����Ϣ.txt","r");
    if(feof(fp))
    {
        printf("�˰༶�����ڣ�");
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
        printf("�˰༶�����ڻ�û��ѧ����Ϣ��\n");
        Sleep(1000);
        system("cls");
        return;
    }
    Node *now=head;
    while(now!=NULL)
    {
        printf("ѧ�ţ�%d ����:%s �༶��%s Ӣ��ɼ���%.2lf c���Գɼ���%.2f �ܳɼ���%.2f\n",now->data.num,now->data.name,now->data.clas,now->data.engScore,now->data.cScore,now->data.total);
        int choose;
        printf("����1��ʾ��һҳ������2��ʾ��һҳ");
        scanf("%d",&choose);
        if(choose==1)
        {
            now=now->prev;
        }else if(choose==2)
        {
            now=now->next;
        }else
        {
            printf("��Чָ��");
        }
    }
    int choose;
    printf("����1������һҳ�����������˳���¼");
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