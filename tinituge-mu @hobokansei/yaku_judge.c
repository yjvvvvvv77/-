#include<stdio.h>

#include"hedda.h"


//�]��v�Ȃ��g�߂��ꍇ

void yaku_judge() {								//�オ�莞�̖������m�F�@

	//2�`8�݂̂ō\��
	if (yaotyu == 0) {
		yaku[TANYAO][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 1;
		if (debug == 1) {
			printf("�f���");
		}
	}
	//���q4�@���@�c���v�����ʑ҂��ɊY������ꍇ
	if (syuntu == 4 && pinflag == 1) {
		yaku[PINFU][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 1;
		if (debug == 1) {
			printf("���a");
		}
	}
	//���q��3��ꂽ�ꍇ
	if (koutu == 3) {
		yaku[SANAN][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 2;
		if (debug == 1) {
			printf("�O�Í�");
		}
	}

	//���q��4��ꂽ�ꍇ�@��
	if (koutu == 4) {
		yaku[SUUAN][yaku_syukai]++;
		yakuman++;
		if (debug == 1) {
			printf("�l�Í�");
		}
	}
	//123�@456�@789�̏��q���쐬�o�����ꍇ
	if (ittu >= 3) {
		yaku[ITTU][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 2;
		if (debug == 1) {
			printf("��C�ʊ�");
		}
	}
	//�������̏��q��2�g��ꂽ�ꍇ
	if (iipei == 1) {
		yaku[IIPEI][yaku_syukai]++;
		yaku[FAN][yaku_syukai]++;
		if (debug == 1) {
			printf("��u��");
		}
	}
	//�������̏��q2�g��2��ꂽ�ꍇ
	if (iipei == 2) {
		yaku[RYANPEI][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 3;
		if (debug == 1) {
			printf("��u��");
		}
	}
	//�����v2�l�g�i�Ύq�j��7��ꂽ�ꍇ
	if (tiitoi >= 1 && yaku[RYANPEI][yaku_syukai] == 0) {
		yaku[TIITOI][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 2;
		tiitoi = 0;
		if (debug == 1) {
			printf("���Ύq");
		}
	}
	//��@�󓕂̏����𖞂������ꍇ�@�𖞁@�@�@���ڍׂ̓O�O���Ă�������
	if (yaku[TYUUREN][yaku_syukai] == 1) {
		yakuman++;
		if (debug == 1) {
			printf("��@��");
		}
	}
	//��蓾�_�̍�������� yaku[FAN][0]�ɕۑ����Ă���
	if (yaku[FAN][0] < yaku[FAN][1]) {
		for (roop_A = 0; roop_A < 10; roop_A++) {
			yaku[roop_A][0] = yaku[roop_A][1];
		}
	}
	if (yaku_syukai < 1)
		yaku_syukai++;
	
	//��x�ł��オ�ꂽ��オ�ꂽ�t���OON
	flag_agari = 1;
}