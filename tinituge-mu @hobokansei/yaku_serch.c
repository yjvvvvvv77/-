#include<stdio.h>
#include"hedda.h"

void yaku_serch(){


	//2つ以上の数が何個あるかカウント
	for (roop_A = 0; roop_A < 9; roop_A++) {
		if (tehai[roop_A] >= 2)
			dual_over++;
	}
//if (dual_over == 7) {
//	tiitoi++;
//}

	//2つ以上の数＝アタマの回数分刻子優先で役を組みにいく
	for (roop_A = 0; dual_over + 1 >= roop_A; roop_A++) {
		printf("\n");
		kotu_judge(tehai);
	}
	if (debug == 1) {
		printf("\n\n刻子ジャッジ(昇順)終了\n");
	}
	//昇順の全アタマパターンを見たら降順切り替え
	for (roop_A = 0; roop_A < 4; roop_A++) {
		int temp = tehai[roop_A];
		tehai[roop_A] = tehai[8 - roop_A];
		tehai[8 - roop_A] = temp;
	}
	kotu_atama = 0;								//リセット
	flag_reverce = 1;							//降順切り替えてるフラグ
	tumohai = 10 - (tumohai + 1) - 1;			//ツモ牌も反転させる
	

	//降順で刻子ジャッジもう1周
	for (roop_B = 0; dual_over + 1 >= roop_B; roop_B++) {
		printf("\n");
		kotu_judge(tehai);
	}
	if (debug == 1) {
		printf("\n\n刻子ジャッジ(降順)終了\n");
	}
	//降順終了し、降順切り替えてるフラグ消灯
	flag_reverce = 0;


	//昇順に戻す
	for (roop_A = 0; roop_A < 4; roop_A++) {
		int temp = tehai[roop_A];
		tehai[roop_A] = tehai[8 - roop_A];
		tehai[8 - roop_A] = temp;
	}
	tumohai = 10 - (tumohai + 1) - 1;			//ツモ牌も戻す


	//刻子時と同じ要領で順子優先周回
	for (roop_B = 0; dual_over + 1 >= roop_B; roop_B++) {
		printf("\n");
		syuntu_judge(tehai);
	}
	if (debug == 1) {
		printf("\n\n順子ジャッジ(昇順)終了\n");
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
		printf("\n\n順子ジャッジ(降順)終了\n");
	}


}