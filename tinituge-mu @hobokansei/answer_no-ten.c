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

	
	//デバッグ用
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
		printf("上がれてます！");
		return 0;										//上がれるか判定
	}

	if (debug == 1) {
		printf("\n聴牌サーチ\n");
	}

	for (roop_B= 0, e = 0; roop_B < 9; roop_B++) {							//聴牌判定
		kotu_atama = 0; syuntu_atama = 0; e = 0;								//リセット
		for (roop_A = 0; roop_A < 4; roop_A++) {
			int temp = tehai[roop_A];
			tehai[roop_A] = tehai[8 - roop_A];
			tehai[8 - roop_A] = temp;
		}

		//どの牌を捨てても聴牌にならないか1種類ずつ捨てて検討
		
		if (tehai[roop_B] != 0) {
			tehai[roop_B] --;
			if (debug == 1) {
				printf("\n%d捨て", roop_B + 1);
			}
		}
		else {
			//持ってない牌の順番スキップ
			e++;				
			roop_A++;
		}
		if (e == 0) {							

			dual_over = 0;
			yaku_serch();
			tehai[roop_B] += 1;
			for (roop_A = 0; roop_A < 9; roop_A++) {
				if (mati[roop_A] != 0) {
					printf("テンパれてます！");

					return 0;
				}
			}
		}
		
	}printf("\nたしかに\n");
}