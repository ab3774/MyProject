#include "common.h"
#include "screenout.h"

void showmenu() {
	printf("===============");
	printf("\n1. 가계부확인");
	printf("\n2. 가계부추가");
	printf("\n3. 가계부삭제");
	printf("\n5. 개인사용내역");
	printf("\n0. 종료\n");
	printf("===============\n");
	fflush(stdin);
}
