#include<stdio.h>
#include"hedda.h"

void haihyouji() {							//�v�\���@���@0�`35����`��ɐU�蕪��	���@�c���v�̐��l�����
	int n = 0;

	for (; roop_A < 9; ) {
		if (tehai[roop_A] != 0) {
			break;
		} else
			break;
	}

	if (roop_A >= 0 && roop_A <= 8){								//�G���[���p
	if (tehai[roop_A] >= 0 && tehai[roop_A] <= 9) {					//�G���[���p
		n = tehai[roop_A];
	}
	}
	
	
	if (tumo_check == 1) {											//�c���v�̐U�蕪����
		n = 1;
		roop_A = tumohai;
	}
	for (; n > 0; n--) {



		if (roop_A == 0)
			printf("�� ");
		else if (roop_A == 1)
			printf("�� ");
		else if (roop_A == 2)
			printf("�O ");
		else if (roop_A == 3)
			printf("�l ");
		else if (roop_A == 4)
			printf("�� ");
		else if (roop_A == 5)
			printf("�Z ");
		else if (roop_A == 6)
			printf("�� ");
		else if (roop_A == 7)
			printf("�� ");
		else if (roop_A == 8)
			printf("�� ");
	}

}


void furiwake(int a) {
	int b = 0;

	if (a < 4)
		b = 0;
	else if (a < 8)
		b = 1;
	else if (a < 12)
		b = 2;
	else if (a < 16)
		b = 3;
	else if (a < 20)
		b = 4;
	else if (a < 24)
		b = 5;
	else if (a < 28)
		b = 6;
	else if (a < 32)
		b = 7;
	else if (a < 36)
		b = 8;
	if (flag_sute == 0) {						
		tehai[b]++;
		tumohai = b;
	}
	if (flag_sute == 1) {
		sutehai = b;
	}
}