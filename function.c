#include "common.h"
#include "nodedata.h"

int numOfdata = 0;//가계부추가 카운트
int amount = 0;//잔액저장
FILE *fp;
char *f_name = "wonjun.txt";

LinkedNode *createlink() {
	LinkedNode*AC = (LinkedNode*)malloc(sizeof(LinkedNode));
	AC->rear = NULL;
	AC->front = NULL;
	return AC;
}

// 가계부확인
void acprint(LinkedNode* ac) {
	Node* temp;
	int i;
	char dow[10];//입금 출금 출력

	temp = ac->front;
	fp = fopen(f_name, "r");
	if (ac->front == NULL) {
		system("cls");
		printf("empty\n");
		return;
	}

	for (i = 0; i<numOfdata; i++) {
		switch (temp->info.acdow)//acdow 문자 출력, 입금이면 잔액+ 출력이면 잔액-
		{
		case 1:
			strcpy(dow, "입금");
			temp->info.am = amount;
			temp->info.am += temp->info.um;
			amount = temp->info.am;
			break;
		case 2:
			strcpy(dow, "출금");
			temp->info.am = amount;
			temp->info.am -= temp->info.um;
			amount = temp->info.am;
			break;
		}
		system("cls");
		printf("\n%d. ",temp->info.acnumOfdata);
		printf("이름: %s", temp->info.acname);
		printf("\t학번: %d", temp->info.acnum);
		printf("\t입출금: %s", dow);
		printf("\t사용내역: %s", temp->info.acuse);
		printf("\t\t금액: %d원", temp->info.um);
		printf("\t\t날짜/시간: %s", temp->info.acday);
		printf("\t잔액: %d원", amount);
		printf("\t\t비고: %s\n", temp->info.x);
		
		temp = temp->link;
	} amount = 0;//가계부 확인하기전에 잔액 초기화
	
}

//가계부 추가
void acinsert(LinkedNode*ac) {
	Node* new = (Node*)malloc(sizeof(Node));
	fp = fopen(f_name, "a");
	system("cls");
	printf("\n이름: ");
	scanf("%s", &new->info.acname);
	printf("\n학번: ");
	scanf("%d", &new->info.acnum);
	printf("1.입금\n2.출금\n: ");
	scanf("%d", &new->info.acdow);
	printf("사용내역: ");
	scanf("%s", &new->info.acuse);
	printf("금액: ");
	scanf("%d", &new->info.um);
	printf("날짜/시간: ");
	scanf("%s", &new->info.acday);
	printf("비고: ");
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
	int s;//입력한번호
	system("cls");
	printf("삭제할 항목의 번호 : ");
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
	char dow[10];//입금 출금 출력
	ACdata*man = (ACdata*)malloc(sizeof(ACdata));

	temp = ac->front;
	system("cls");
	printf("\n찾을 학번: ");
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

				switch (temp->info.acdow)//acdow 문자 출력, 입금이면 잔액+ 출력이면 잔액-
				{
				case 1:
					strcpy(dow, "입금");
					break;
				case 2:
					strcpy(dow, "출금");
					break;
				}
				printf("\n %d.", man->acnumOfdata);
				printf("\t 이름 : %s", man->acname);
				printf("\t 학번 : %d", man->acnum);
				printf("\t 입출금 : %s", dow);
				printf("\t 사용내역 : %s", man->acuse);
				printf("\t 금액 : %d", man->um);
				printf("\t 날짜/시간 : %s", man->acday);
				printf("\t 비고 : %s\n", man->x);

				temp = temp->link;
			}
		}
		printf("찾을수없습니다");
		return;
	}//while

	


}