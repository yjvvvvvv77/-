#include<stdio.h>
#include"hedda.h"

int answer_tenpai() {

	printf("�ǂ���̂Ă܂����H");
	scanf_s("%d", &sutehai);
	qsort(tehai_data, 13, sizeof(int), compareInt);
	flag_sute++;



	if(sutehai<14){
	for (roop_A = 0; roop_A < 14; roop_A++) {
		if (roop_A == sutehai - 1) {
			sutehai = tehai_data[roop_A];
			break;
		}

	}
	furiwake(sutehai);

	if (sutehai >= 0 && sutehai <= 8) {					//�G���[���p
		tehai[sutehai]--;
	}
	}
	if (sutehai == 14)
		tehai[tumohai] --;

	tumo_check = 0;
	flag_sute = 0;
	if(sutehai >= 1 && sutehai <=9){					//�G���[���p
		tehai_data[sutehai - 1] = draw;	
	}
	

	qsort(tehai_data, 13, sizeof(int), compareInt);

	//for (n = 0; n < 13; n++) {
		//furiwake(tehai_data[n]);
	//}
	for (roop_A = 0; roop_A < 9; roop_A++)
		haihyouji(tehai);

	printf("\n");

	for (roop_A = 0; roop_A < 13; roop_A++) {
		printf("�� ");
	}

	//�e�X�g�p
	/*tehai[0] = 1;
	tehai[1] = 1;
	tehai[2] = 2;
	tehai[3] = 2;
	tehai[4] = 1;
	tehai[5] = 2;
	tehai[6] = 3;
	tehai[7] = 0;
	tehai[8] = 1;*/

	yaku_serch();

	printf("��1�v����Enter�������āA�Ō��0��Enter�������ĉ�����\n");
	printf("���҂��ł����H�F");
	
	roop_B = 0;
	while (roop_B < 1) {
		scanf_s("%d", &roop_A);
		user_mati[roop_A] = 1;
		if (roop_A == 0)
			roop_B++;
	}

	for (roop_A = 0; roop_A <= 9; roop_A++) {
		if (mati[roop_A] != 0) {
			mati[roop_A] = 1;
		}
	}

	for (roop_A = 1, roop_B = 0; roop_A <= 9; roop_A++) {
		if (mati[roop_A] != user_mati[roop_A]) {
			printf("�s�����ł��B�B�B");
			break;
		} else
			roop_B++;
	}
	if (roop_B == 9) {
		printf("�����ł��I���߂łƂ��I");
	}


	for (roop_A = 0; roop_A <= 9; roop_A++) {
		if (mati[roop_A] != 0) {
			printf("\n%d", roop_A);
			
		}
		if (roop_A >= 9)
			printf("�҂�");
	}if (flag_furiten == 1) {
		printf("\n���t���e���ł���");
	}

}