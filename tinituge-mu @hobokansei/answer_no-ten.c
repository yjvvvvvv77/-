#include<stdio.h>
#include"hedda.h"

int answer_noten() {

	tehai_data[13] = draw;
	for (roop_A = 0; roop_A < 9; roop_A++) {
		kaburi[roop_A] = 0;
		tehai[roop_A] = 0;
	}

	qsort(tehai_data, 13, sizeof(int), compareInt);

	for (roop_A = 0; roop_A < 14; roop_A++) {
		furiwake(tehai_data[roop_A]);
	}
	printf("\n");

	
	//�f�o�b�O�p
	/*tehai[0] = 1;
	tehai[1] = 2;
	tehai[2] = 2;
	tehai[3] = 2;
	tehai[4] = 1;
	tehai[5] = 2;
	tehai[6] = 3;
	tehai[7] = 0;
	tehai[8] = 1;*/



	yaku_serch();

	if (flag_agari != 0) {
		printf("�オ��Ă܂��I");
		return 0;										//�オ��邩����
	}

	if (debug == 1) {
		printf("\n���v�T�[�`\n");
	}

	for (roop_B= 0, e = 0; roop_B < 9; roop_B++) {							//���v����
		kotu_atama = 0; syuntu_atama = 0; e = 0;								//���Z�b�g
		for (roop_A = 0; roop_A < 4; roop_A++) {
			int temp = tehai[roop_A];
			tehai[roop_A] = tehai[8 - roop_A];
			tehai[8 - roop_A] = temp;
		}

		//�ǂ̔v���̂ĂĂ����v�ɂȂ�Ȃ���1��ނ��̂ĂČ���
		
		if (tehai[roop_B] != 0) {
			tehai[roop_B] --;
			if (debug == 1) {
				printf("\n%d�̂�", roop_B + 1);
			}
		}
		else {
			//�����ĂȂ��v�̏��ԃX�L�b�v
			e++;				
			roop_A++;
		}
		if (e == 0) {							

			dual_over = 0;
			yaku_serch();
			tehai[roop_B] += 1;
			for (roop_A = 0; roop_A < 9; roop_A++) {
				if (mati[roop_A] != 0) {
					printf("�e���p��Ă܂��I");

					return 0;
				}
			}
		}
		
	}printf("\n��������\n");
}