#include<stdio.h>
#include"hedda.h"

//���[�`���Ȃ牽�҂����\���@
void mati_judge(int x, int y, int h, int d) {

	int roop_A, roop_B = 0;

	
	//amari��0�Ȃ�𔻒�(yaku_judge)��
	if (amari == 0) {
		yaku_judge();
	}

	//��u���@���@���Ύq����
	else if (tiitoi >= 1)
		if (iipei == 2) {
			tiitoi = 0;
			yaku_judge();
		}

	//���Ύq����
	if (amari > 3 && dual_over == 7) {
		iipei = 0;
		yaku_judge();
	}

	//�]�肪2�ȉ��̎��@�҂��`�F�b�N
	if (amari < 3 && yaku_syukai == 0) {							

		if (dual_over > 6) {
			if (debug == 1) {
				printf("���Ύq");
			}
		//�A�^�}��2�̎�
		} else if (atama > 1) {
			if (debug == 1) {
				printf("\n%d�A%d���q�A�^�}�҂�", h + 1, d + 1);
			}
			mati[h + 1]++; mati[d + 1]++;				//�҂Ă鐔�Ƃ��ċL�^
			if ((sutehai  == h)  || (sutehai == d) )	//�҂��v���̂Ă��v�ł���΃t���e���Ƃ��ċL�^
				flag_furiten = 1;
		} else if (flag_mati == 1) {					//�҂��v�Ɋւ��v��1��ނ̎�
			if (debug == 1) {
				printf("\n%d�A�^�}�P�R�҂�", x + 1);
			}
			mati[x + 1]++;
			if (sutehai == x )
				flag_furiten = 1;
		}if(atama >= 1){
		if (flag_mati == 2) {							//�҂��v�Ɋւ��v��2��ނ̎�
			if (x + 2 == y) {
				if (debug == 1) {
					printf("\n%d�҂�", x + 2);			//2��ނ̔v�̊Ԃɑ҂��v������`
				}
				mati[x + 2]++;
				if (sutehai  == x + 1)
					flag_furiten = 1;
			} else if (x != 0 && x != 7
				&& (x + 1 == y && x > 0)) {
				if (debug == 1) {
					printf("\n%d�A%d�҂�", x, x + 3);	//2��ނ̔v�������Ă��āA���̑O��ő҂Ă�`
				}
				mati[x]++; mati[x + 3]++;
				if ((sutehai + 1) == x || (sutehai + 1) == x + 3)			//
					flag_furiten = 1;
			} else if (x + 1 == y && x == 0) {			//2��ޑ����Ă���v���[�����i1��2 or 8��9�j	
				if (debug == 1) {
					printf("\n%d�҂�", x + 3);
				}
				mati[x + 3]++;
				if (sutehai + 1 == x + 3)
					flag_furiten = 1;
			} else if (x == 7 && y == 8) {				//2��ޑ����Ă���v���[�����i1��2 or 8��9�j	
				if (debug == 1) {
					printf("\n%d�҂�", x);
				}
				mati[x]++;
				if (sutehai + 1 == x)
					flag_furiten = 1;
			}
		}
		}
		
	//���Ύq��҂`
	} if (amari >= 3 && dual_over >= 6 && final_answer == 1) {
		for (roop_A = 0; roop_A < 9; roop_A++) {
			if (tehai[roop_A] == 1) {
				roop_B = roop_A + 1;
				if (flag_reverce == 0) {
					if (debug == 1) {
						printf("\n���Ύq%d�P�R�҂�", roop_B);
					}
					if (sutehai == roop_B)
						flag_furiten = 1;
				} else if (flag_reverce == 1) {
					roop_B = 10 - roop_B;
					if (debug == 1) {
						printf("\n���Ύq%d�P�R�҂�", roop_B);
					}
					if (sutehai == roop_B)
						flag_furiten = 1;
				}
			}
		}
	}

	//1���g�ݑւ��Č�����A�t���O�����ׂă��Z�b�g
	flag_mati = 0;
	amari = 0;
	iipei = 0, ittu = 0, koutu = 0, syuntu = 0, yaotyu = 0, tyuren = 0; pinflag = 0;

	for (roop_A = 0; roop_A < 10; roop_A++) {
		yaku[roop_A][yaku_syukai] = 0;
	}
}