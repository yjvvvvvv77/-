#include<stdio.h>
#include"hedda.h"


void kotu_judge(int a[]) {							//���q�D������
	int b, kotu_tehai[9], x = 0, y = 0, h = 0, d = 0, roop_A = 0;
	
	//1�����ƂɃ��Z�b�g
	atama = 0;
	flag_mati = 0;

	//��Ƌオ���邩�m�F
	for (b = 0; b < 9; b++) {
		kotu_tehai[b] = a[b];
		if ((b == 0 || b == 8)
			&& kotu_tehai[b] >= 1) {
			yaotyu++;
		}

	}

	//��@�󓕂̏����m�F
	if (kotu_tehai[0] == 3
		&& kotu_tehai[8] == 3) {
		for (b = 1; b < 8; b++) {
			if (kotu_tehai[b] >= 1)
				tyuren++;
			if (kotu_tehai[b] >= 2)
				tyuren += 2;
			if (tyuren == 8) {
				yaku[TYUUREN][0]++;
				yaku_judge();
			}
		}
	}

	//�A�^�}���ǂ�ɂ��邩1�����Ƃɂ��炵�Č������Ă���
	for (; atama < 1 && kotu_atama < 9; kotu_atama++) {
		if (kotu_tehai[kotu_atama] >= 2) {
			if(debug == 1){
			printf("\n%d��", kotu_atama + 1);
			}
			atama++;						//�A�^�}��ꂽ�t���O
			kotu_tehai[kotu_atama] -= 2;	//�A�^�}��������v��2���炷
			h = kotu_atama;

			//�������I�������~���Ō��Ă������߂ɐ��l���]
			if (flag_reverce == 1)
				h = 10 - (h + 1) - 1;


		}
	}

	//���q�i����3�j���g�߂邩�m�F
	for (b = 0; b < 9; b++) {
		if (kotu_tehai[b] >= 3) {
			if (debug == 1) {
			printf("\n%d���q", b + 1);
			}
			koutu++;
			kotu_tehai[b] -= 3;				//���q��������v��3���炷
			b--;

		}

	}
	//�]���������ŏ��q�i�K�i�j���g�߂邩�m�F
	for (b = 0; b < 9; b++) {
		//�K�i�𓯐���2����ꍇ�i��u���A��u���̏����j
		if (kotu_tehai[b] >= 2
			&& kotu_tehai[b + 1] >= 2
			&& kotu_tehai[b + 2] >= 2) {

			if (debug == 1) {
				printf("\n%d%d%d��u��", b + 1, b + 2, b + 3);
			}

			//123�@456�@789���S����ꂽ���C�ʊсiittu == 3�j
			if (b == 0 && ittu == 0)
				ittu++;

			if (b == 3 && ittu < 2)
				ittu++;

			if (b == 6)
				ittu++;

			iipei++;
			syuntu += 2;

			//���q�i�K�i�j���������Ă���
			//b�̔v����܂��͎��łȂ����@���@�c���v���K�i�̐^�񒆈ȊO�ɑg�ݍ��܂ꂽ�Ƃ������a�����B��
			if ((b != 0 && b != 6)
				&& (tumohai == b + 2 || tumohai == b))
				pinflag = 1;

			//�g�܂ꂽ�v����v�������
			kotu_tehai[b] -= 2, kotu_tehai[b + 1] -= 2, kotu_tehai[b + 2] -= 2;
			b--;

			
		// 1�v���g�����K�i������ꍇ�i��{�͏�̈�u���ƈꏏ�j
		} else if (kotu_tehai[b] >= 1
			&& kotu_tehai[b + 1] >= 1
			&& kotu_tehai[b + 2] >= 1) {

			if (debug == 1) {
				printf("\n%d%d%d���q", b + 1, b + 2, b + 3);
			}
			if (b == 0 && ittu == 0)
				ittu++;

			if (b == 3 && ittu < 2)
				ittu++;

			if (b == 6)
				ittu++;

			syuntu++;

			if ((b != 0 && b != 6)
				&& (tumohai == b + 2 || tumohai == b))
				pinflag = 1;

			kotu_tehai[b] -= 1, kotu_tehai[b + 1] -= 1, kotu_tehai[b + 2] -= 1;
			b--;
		}
	}
	//�����~���؂�ւ�
	for (roop_A = 0; roop_A < 4 && flag_reverce == 1; roop_A++) {
		int temp = kotu_tehai[roop_A];
		kotu_tehai[roop_A] = kotu_tehai[8 - roop_A];
		kotu_tehai[8 - roop_A] = temp;
	}

	for (b = 0; b < 9; b++) {

		if (kotu_tehai[b] != 0) {		//�]�蕨�`�F�b�N
			amari += kotu_tehai[b];
			flag_mati++;				//�҂��ڍs�t���O

			if (kotu_tehai[b] == 2) {
				d = b;
				atama++;

			}
			if (flag_mati == 1)			//�]��1�ڂ�x��
				x = b;
			if (flag_mati == 2)			//2�ڂ�y��
				y = b;
		}
	}

	mati_judge(x, y, h, d, yaku_syukai);

}