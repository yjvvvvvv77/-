#include<stdio.h>
#include"hedda.h"

//アガリ回答した場合
int answer_agari(){									

	//ツモ牌を手牌として加える
	tehai_data[13] = draw;
	for (roop_A = 0; roop_A < 9; roop_A++) {
		kaburi[roop_A] = 0;
		tehai[roop_A] = 0;
	}

	//改めて並び替え
	qsort(tehai_data, 13, sizeof(int), compareInt);

	//改めて振り分け
	for (roop_A = 0; roop_A < 14; roop_A++) {
		furiwake(tehai_data[roop_A]);
	}
	printf("\n");

	//テスト用
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

	//ツモ牌操作フラグ解除
	tumo_check = 0;

	
	//改めて手牌表示
	for (roop_A = 0; roop_A < 9; roop_A++)
	haihyouji(tehai);

	printf("\n");

	for (roop_A = 0; roop_A < 14; roop_A++) {
		printf("萬 ");
	}

	
	//手牌を組み替えて役や待ちを検討しに行く
	yaku_serch();



	//上がれてるかどうかと役表示

	/*for (n = 0; n<11; n++) {*/
	printf("\n役\n");
	if (flag_agari == 0) {
		printf("\n上がれてません！！");
	} else if (yakuman == 0) {
		printf("\n門前清自摸和");
		yaku[FAN][0] += 1;
		printf("\n清一色");
		yaku[FAN][0] += 6;
		if (yaku[TANYAO][0] >= 1)
			printf("\n断幺九");
		if (yaku[PINFU][0] >= 1)
			printf("\n平和");
		if (yaku[IIPEI][0] >= 1)
			printf("\n一盃口");
		if (yaku[ITTU][0] >= 1)
			printf("\n一気通貫");
		if (yaku[TIITOI][0] >= 1)
			printf("\n七対子");
		if (yaku[RYANPEI][0] >= 1)
			printf("\n二盃口");
		if (yaku[SANAN][0] >= 1)
			printf("\n三暗刻");

		printf("\n%d翻\n\n", yaku[FAN][0]);
		if (yaku[FAN][0] <= 7) {
			printf("跳満\t");
			printf("12000点\n");
		} else if (yaku[FAN][0] <= 10) {
			printf("倍満\t");
			printf("16000点\n");
		} else if (yaku[FAN][0] <= 12) {
			printf("三倍満\t");
			printf("24000点\n");
		}
	}
	if (yaku[SUUAN][0] >= 1)
	printf("\n四暗刻");
	if (yaku[TYUUREN][0] >= 1)
	printf("\n九蓮宝燈");
	if (yaku[FAN][0] >= 13 || yakuman > 0) {
		printf("\n役満");
		printf("\t32000点\n");
		}


	}
