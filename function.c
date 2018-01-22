#include "common.h"
#include "nodedata.h"

int numOfdata = 0;//������߰� ī��Ʈ
int amount = 0;//�ܾ�����
FILE *fp;
char *f_name = "wonjun.txt";

LinkedNode *createlink() {
	LinkedNode*AC = (LinkedNode*)malloc(sizeof(LinkedNode));
	AC->rear = NULL;
	AC->front = NULL;
	return AC;
}

// �����Ȯ��
void acprint(LinkedNode* ac) {
	Node* temp;
	int i;
	char dow[10];//�Ա� ��� ���

	temp = ac->front;
	fp = fopen(f_name, "r");
	if (ac->front == NULL) {
		system("cls");
		printf("empty\n");
		return;
	}

	for (i = 0; i<numOfdata; i++) {
		switch (temp->info.acdow)//acdow ���� ���, �Ա��̸� �ܾ�+ ����̸� �ܾ�-
		{
		case 1:
			strcpy(dow, "�Ա�");
			temp->info.am = amount;
			temp->info.am += temp->info.um;
			amount = temp->info.am;
			break;
		case 2:
			strcpy(dow, "���");
			temp->info.am = amount;
			temp->info.am -= temp->info.um;
			amount = temp->info.am;
			break;
		}
		system("cls");
		printf("\n%d. ",temp->info.acnumOfdata);
		printf("�̸�: %s", temp->info.acname);
		printf("\t�й�: %d", temp->info.acnum);
		printf("\t�����: %s", dow);
		printf("\t��볻��: %s", temp->info.acuse);
		printf("\t\t�ݾ�: %d��", temp->info.um);
		printf("\t\t��¥/�ð�: %s", temp->info.acday);
		printf("\t�ܾ�: %d��", amount);
		printf("\t\t���: %s\n", temp->info.x);
		
		temp = temp->link;
	} amount = 0;//����� Ȯ���ϱ����� �ܾ� �ʱ�ȭ
	
}

//����� �߰�
void acinsert(LinkedNode*ac) {
	Node* new = (Node*)malloc(sizeof(Node));
	fp = fopen(f_name, "a");
	system("cls");
	printf("\n�̸�: ");
	scanf("%s", &new->info.acname);
	printf("\n�й�: ");
	scanf("%d", &new->info.acnum);
	printf("1.�Ա�\n2.���\n: ");
	scanf("%d", &new->info.acdow);
	printf("��볻��: ");
	scanf("%s", &new->info.acuse);
	printf("�ݾ�: ");
	scanf("%d", &new->info.um);
	printf("��¥/�ð�: ");
	scanf("%s", &new->info.acday);
	printf("���: ");
	scanf("%s", &new->info.x);
	
	new->info.acnumOfdata = numOfdata + 1;
	new->link = NULL;

	if (ac->front == NULL) {
		ac->front = new;
		ac->rear = new;

	}
	else {
		ac->rear->link = new;
		ac->rear = new;
	}

	numOfdata++;
	fprintf(fp, "%s\t, %d\t, %d\t, %s\t, %d\t, %s\t, %s\n", new->info.acname, new->info.acnum, new->info.acdow, new->info.acuse, new->info.um, new->info.acday, new->info.x);
	fclose(fp);
}

void acdelete(LinkedNode*ac) {
	Node*del = (Node*)malloc(sizeof(Node)); //delete node
	Node*lin = (Node*)malloc(sizeof(Node)); //old node

	del = ac->front;
	lin = del;
	int s;//�Է��ѹ�ȣ
	system("cls");
	printf("������ �׸��� ��ȣ : ");
	scanf("%d", &s);

	if (del == NULL) {
		printf("empty\n");
		return;
	}
	else if (del->link == NULL) {
		ac->front = NULL;
		ac->rear = NULL;
		numOfdata--;
		free(del);
		return;
	}
	else {
		while (del != NULL) {
			if (del->info.acnumOfdata == s) {
				if (del == ac->front) {
					ac->front = del->link;
					free(del);
					return;
				}//delete 1 data

				while (lin->link != del)
					lin = lin->link;

				lin->link = del->link;
				free(del);
				return;

			} numOfdata--;
			del = del->link;
		}//while
	}//else
}



void acfind(LinkedNode*ac) {
	int index;
	int i;
	Node*temp;
	char dow[10];//�Ա� ��� ���
	ACdata*man = (ACdata*)malloc(sizeof(ACdata));

	temp = ac->front;
	system("cls");
	printf("\nã�� �й�: ");
	scanf("%d", &index);

	while (temp != NULL) {
		for (i = 0; i < numOfdata; i++) {
			if (temp->info.acnum == index) {

				man->acnumOfdata = temp->info.acnumOfdata;
				strcpy(man->acname, temp->info.acname);
				man->acnum = temp->info.acnum;
				man->acdow = temp->info.acdow;
				strcpy(man->acuse, temp->info.acuse);
				man->um = temp->info.um;
				strcpy(man->acday, temp->info.acday);
				strcpy(man->x, temp->info.x);

				switch (temp->info.acdow)//acdow ���� ���, �Ա��̸� �ܾ�+ ����̸� �ܾ�-
				{
				case 1:
					strcpy(dow, "�Ա�");
					break;
				case 2:
					strcpy(dow, "���");
					break;
				}
				printf("\n %d.", man->acnumOfdata);
				printf("\t �̸� : %s", man->acname);
				printf("\t �й� : %d", man->acnum);
				printf("\t ����� : %s", dow);
				printf("\t ��볻�� : %s", man->acuse);
				printf("\t �ݾ� : %d", man->um);
				printf("\t ��¥/�ð� : %s", man->acday);
				printf("\t ��� : %s\n", man->x);

				temp = temp->link;
			}
		}
		printf("ã���������ϴ�");
		return;
	}//while

	


}