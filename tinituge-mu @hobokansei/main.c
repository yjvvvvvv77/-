#include<stdio.h>
#include <time.h>
#include "hedda.h"
#include<stdlib.h>


int compareInt(const void *a, const void *b);

syuntu_atama = 0;

debug = 1;												// �f�o�b�O���[�h �� 1(�ʎq�g�ݗ��Ă�҂����̉���)

int main(void) {



	srand(/*(unsigned)*/time(NULL));

	//��v13�̃����_������

	for (roop_A = 0; roop_A < 13; roop_A++, e = 0) {
		tehai_data[roop_A] = rand() % 35 + 1;				//��������

		for (roop_tehai = 0; roop_tehai < roop_A; roop_tehai++) {

			if (tehai_data[roop_A] == tehai_data[roop_tehai]) {				//��v���`�F�b�N
				roop_A--;						//�����ڈ�������
			}
		}
	}
	//tehai_data[13] = 999;				//draw�ɓ����p14�v�ڂ̋󔒁i0�j����z�ɑg�ݍ��܂��΍�


	//�c���v1�̃����_������

	for (; e == 0;) {
		e = 1;
		draw = rand() % 35 + 1;

		for (roop_A = 0; roop_A < 14; roop_A++) {						//���Ԃ������������
			if (tehai_data[roop_A] == draw)
				e = 0;
		}
	}

	//13�v�̃f�[�^����`��Ɋ���U��
	for (roop_A = 0; roop_A < 13; roop_A++) {
		furiwake(tehai_data[roop_A]);
	}
	
	//����U�����v��\��
	for(roop_A = 0; roop_A < 9; roop_A++)
	haihyouji(tehai,roop_A);

	printf("\t");

	//�c���v��U�蕪�����\��
	tumo_check++;											//�c���v����t���O
	furiwake(draw);
	haihyouji(draw);
	printf("\n");

	for (roop_A = 0; roop_A < 13; roop_A++) {
		printf("�� ");
	}
	printf("\t");
	printf("��\n");
	printf(" 1  2  3  4  5  6  7  8  9 10 11 12 13  14");


	//�f�o�b�O���[�h�Ŏ�v�̃f�[�^��\��
	if(debug == 1){
	printf("\n\n%d  ", tehai_data[0]);
	printf("%d  ", tehai_data[1]);
	printf("%d  ", tehai_data[2]);
	printf("%d  ", tehai_data[3]);
	printf("%d  ", tehai_data[4]);
	printf("%d  ", tehai_data[5]);
	printf("%d  ", tehai_data[6]);
	printf("%d  ", tehai_data[7]);
	printf("%d  ", tehai_data[8]);
	printf("%d  ", tehai_data[9]);
	printf("%d  ", tehai_data[10]);
	printf("%d  ", tehai_data[11]);
	printf("%d  ", tehai_data[12]);

	printf("%d  ", draw);
	}
	printf("\n���v�c1�@�a���c0�@�s���c9\n");
	//�@�@�@�@���v�c 1�v�̂Ăă��[�`������������
	//				�@ �a���c ��v��ς������̂܂܏オ�����
	//							�s���c 1�v�������Ă����[�`���炩�����Ȃ����
	printf("���v�H�a���H�s���H:");

	//��
	scanf_s("%d", &final_answer);

	if (final_answer == 0) {
		answer_agari();
	}

	if (final_answer == 1) {
		answer_tenpai();
		}
	if (final_answer == 9) {
		answer_noten();
	}
	return 0;
	
	}
