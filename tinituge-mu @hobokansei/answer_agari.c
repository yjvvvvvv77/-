#include<stdio.h>
#include"hedda.h"

//�A�K���񓚂����ꍇ
int answer_agari(){									

	//�c���v����v�Ƃ��ĉ�����
	tehai_data[13] = draw;
	for (roop_A = 0; roop_A < 9; roop_A++) {
		kaburi[roop_A] = 0;
		tehai[roop_A] = 0;
	}

	//���߂ĕ��ёւ�
	qsort(tehai_data, 13, sizeof(int), compareInt);

	//���߂ĐU�蕪��
	for (roop_A = 0; roop_A < 14; roop_A++) {
		furiwake(tehai_data[roop_A]);
	}
	printf("\n");

	//�e�X�g�p
	//tumohai = 3;				//(0~8)

	//tehai[0] = 0;
	//tehai[1] = 2;
	//tehai[2] = 2;
	//tehai[3] = 2;
	//tehai[4] = 2;
	//tehai[5] = 3;
	//tehai[6] = 3;
	//tehai[7] = 0;
	//tehai[8] = 0;

	//�c���v����t���O����
	tumo_check = 0;

	
	//���߂Ď�v�\��
	for (roop_A = 0; roop_A < 9; roop_A++)
	haihyouji(tehai);

	printf("\n");

	for (roop_A = 0; roop_A < 14; roop_A++) {
		printf("�� ");
	}

	
	//��v��g�ݑւ��Ė���҂����������ɍs��
	yaku_serch();



	//�オ��Ă邩�ǂ����Ɩ�\��

	/*for (n = 0; n<11; n++) {*/
	printf("\n��\n");
	if (flag_agari == 0) {
		printf("\n�オ��Ă܂���I�I");
	} else if (yakuman == 0) {
		printf("\n��O�����̘a");
		yaku[FAN][0] += 1;
		printf("\n����F");
		yaku[FAN][0] += 6;
		if (yaku[TANYAO][0] >= 1)
			printf("\n�f���");
		if (yaku[PINFU][0] >= 1)
			printf("\n���a");
		if (yaku[IIPEI][0] >= 1)
			printf("\n��u��");
		if (yaku[ITTU][0] >= 1)
			printf("\n��C�ʊ�");
		if (yaku[TIITOI][0] >= 1)
			printf("\n���Ύq");
		if (yaku[RYANPEI][0] >= 1)
			printf("\n��u��");
		if (yaku[SANAN][0] >= 1)
			printf("\n�O�Í�");

		printf("\n%d�|\n\n", yaku[FAN][0]);
		if (yaku[FAN][0] <= 7) {
			printf("����\t");
			printf("12000�_\n");
		} else if (yaku[FAN][0] <= 10) {
			printf("�{��\t");
			printf("16000�_\n");
		} else if (yaku[FAN][0] <= 12) {
			printf("�O�{��\t");
			printf("24000�_\n");
		}
	}
	if (yaku[SUUAN][0] >= 1)
	printf("\n�l�Í�");
	if (yaku[TYUUREN][0] >= 1)
	printf("\n��@��");
	if (yaku[FAN][0] >= 13 || yakuman > 0) {
		printf("\n��");
		printf("\t32000�_\n");
		}


	}
