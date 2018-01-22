#include "common.h"
#include "nodedata.h"
#include "screenout.h"


void main() {
	LinkedNode*ac = createlink(); //����θ���Ʈ ����

	int dw; //dowhile


	do {
		showmenu();
		scanf("%d", &dw);

		switch (dw) {

		case 1: //print
			acprint(ac);
			break;

		case 2: //insert
			acinsert(ac);
			break;
		case 3: //delete
			acdelete(ac);
			break;
		case 4: //change
			acfind(ac);
			break;
		}//sw


	} while (dw != 0);
}