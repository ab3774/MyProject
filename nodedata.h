
typedef struct ACdata {
	int acnumOfdata;//����ι�ȣ
	char acname[100]; //�̸�
	int acnum;//�й�
	int acdow;//Deposit or withdrawal
	char acuse[100]; //��볻��
	int um;// ���ݾ�
	char acday[50];
	int am;//�ܾ�
	char x[50];//���
}ACdata;

typedef struct {
	ACdata info;
	struct Node* link;
}Node;

typedef struct {
	Node*front, *rear;
}LinkedNode;
#pragma once
