#include<stdio.h>
#include <time.h>
#include "hedda.h"
#include<stdlib.h>


int compareInt(const void *a, const void *b);

syuntu_atama = 0;

debug = 1;												// デバッグモード ＝ 1(面子組み立てや待ち等の可視化)

int main(void) {



	srand(/*(unsigned)*/time(NULL));

	//手牌13個のランダム生成

	for (roop_A = 0; roop_A < 13; roop_A++, e = 0) {
		tehai_data[roop_A] = rand() % 35 + 1;				//乱数生成

		for (roop_tehai = 0; roop_tehai < roop_A; roop_tehai++) {

			if (tehai_data[roop_A] == tehai_data[roop_tehai]) {				//手牌被りチェック
				roop_A--;						//ｎ枚目引き直し
			}
		}
	}
	//tehai_data[13] = 999;				//drawに入れる用14牌目の空白（0）が手配に組み込まれる対策


	//ツモ牌1個のランダム生成

	for (; e == 0;) {
		e = 1;
		draw = rand() % 35 + 1;

		for (roop_A = 0; roop_A < 14; roop_A++) {						//かぶったら引き直し
			if (tehai_data[roop_A] == draw)
				e = 0;
		}
	}

	//13牌のデータを一～九に割り振り
	for (roop_A = 0; roop_A < 13; roop_A++) {
		furiwake(tehai_data[roop_A]);
	}
	
	//割り振った牌を表示
	for(roop_A = 0; roop_A < 9; roop_A++)
	haihyouji(tehai,roop_A);

	printf("\t");

	//ツモ牌を振り分け→表示
	tumo_check++;											//ツモ牌操作フラグ
	furiwake(draw);
	haihyouji(draw);
	printf("\n");

	for (roop_A = 0; roop_A < 13; roop_A++) {
		printf("萬 ");
	}
	printf("\t");
	printf("萬\n");
	printf(" 1  2  3  4  5  6  7  8  9 10 11 12 13  14");


	//デバッグモードで手牌のデータを表示
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
	printf("\n聴牌…1　和了…0　不聴…9\n");
	//　　　　聴牌… 1牌捨ててリーチをかけられる状態
	//				　 和了… 手牌を変えずそのまま上がれる状態
	//							不聴… 1牌交換してもリーチすらかけられない状態
	printf("聴牌？和了？不聴？:");

	//回答
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
