
typedef struct ACdata {
	int acnumOfdata;//가계부번호
	char acname[100]; //이름
	int acnum;//학번
	int acdow;//Deposit or withdrawal
	char acuse[100]; //사용내역
	int um;// 사용금액
	char acday[50];
	int am;//잔액
	char x[50];//비고
}ACdata;

typedef struct {
	ACdata info;
	struct Node* link;
}Node;

typedef struct {
	Node*front, *rear;
}LinkedNode;
#pragma once
