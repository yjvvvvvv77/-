#include<stdio.h>
#include"hedda.h"

void yaku_serch(){


	//2�ȏ�̐��������邩�J�E���g
	for (roop_A = 0; roop_A < 9; roop_A++) {
		if (tehai[roop_A] >= 2)
			dual_over++;
	}
//if (dual_over == 7) {
//	tiitoi++;
//}

	//2�ȏ�̐����A�^�}�̉񐔕����q�D��Ŗ���g�݂ɂ���
	for (roop_A = 0; dual_over + 1 >= roop_A; roop_A++) {
		printf("\n");
		kotu_judge(tehai);
	}
	if (debug == 1) {
		printf("\n\n���q�W���b�W(����)�I��\n");
	}
	//�����̑S�A�^�}�p�^�[����������~���؂�ւ�
	for (roop_A = 0; roop_A < 4; roop_A++) {
		int temp = tehai[roop_A];
		tehai[roop_A] = tehai[8 - roop_A];
		tehai[8 - roop_A] = temp;
	}
	kotu_atama = 0;								//���Z�b�g
	flag_reverce = 1;							//�~���؂�ւ��Ă�t���O
	tumohai = 10 - (tumohai + 1) - 1;			//�c���v�����]������
	

	//�~���ō��q�W���b�W����1��
	for (roop_B = 0; dual_over + 1 >= roop_B; roop_B++) {
		printf("\n");
		kotu_judge(tehai);
	}
	if (debug == 1) {
		printf("\n\n���q�W���b�W(�~��)�I��\n");
	}
	//�~���I�����A�~���؂�ւ��Ă�t���O����
	flag_reverce = 0;


	//�����ɖ߂�
	for (roop_A = 0; roop_A < 4; roop_A++) {
		int temp = tehai[roop_A];
		tehai[roop_A] = tehai[8 - roop_A];
		tehai[8 - roop_A] = temp;
	}
	tumohai = 10 - (tumohai + 1) - 1;			//�c���v���߂�


	//���q���Ɠ����v�̂ŏ��q�D�����
	for (roop_B = 0; dual_over + 1 >= roop_B; roop_B++) {
		printf("\n");
		syuntu_judge(tehai);
	}
	if (debug == 1) {
		printf("\n\n���q�W���b�W(����)�I��\n");
	}
	for (roop_A = 0; roop_A < 4; roop_A++) {
		int temp = tehai[roop_A];
		tehai[roop_A] = tehai[8 - roop_A];
		tehai[8 - roop_A] = temp;
	}
	syuntu_atama = 0;
	flag_reverce = 1;
	tumohai = 10 - (tumohai + 1) - 1;

	for (roop_A = 0; dual_over + 1 >= roop_A; roop_A++) {
		printf("\n");
		syuntu_judge(tehai);
	}
	if (debug == 1) {
		printf("\n\n���q�W���b�W(�~��)�I��\n");
	}


}