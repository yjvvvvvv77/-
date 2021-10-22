#include<stdio.h>

#include"hedda.h"


//余り牌なく組めた場合

void yaku_judge() {								//上がり時の役条件確認　

	//2～8のみで構成
	if (yaotyu == 0) {
		yaku[TANYAO][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 1;
		if (debug == 1) {
			printf("断幺九");
		}
	}
	//順子4つ　かつ　ツモ牌が両面待ちに該当する場合
	if (syuntu == 4 && pinflag == 1) {
		yaku[PINFU][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 1;
		if (debug == 1) {
			printf("平和");
		}
	}
	//刻子を3つ作れた場合
	if (koutu == 3) {
		yaku[SANAN][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 2;
		if (debug == 1) {
			printf("三暗刻");
		}
	}

	//刻子を4つ作れた場合　役満
	if (koutu == 4) {
		yaku[SUUAN][yaku_syukai]++;
		yakuman++;
		if (debug == 1) {
			printf("四暗刻");
		}
	}
	//123　456　789の順子を作成出来た場合
	if (ittu >= 3) {
		yaku[ITTU][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 2;
		if (debug == 1) {
			printf("一気通貫");
		}
	}
	//同じ数の順子を2組作れた場合
	if (iipei == 1) {
		yaku[IIPEI][yaku_syukai]++;
		yaku[FAN][yaku_syukai]++;
		if (debug == 1) {
			printf("一盃口");
		}
	}
	//同じ数の順子2組を2つ作れた場合
	if (iipei == 2) {
		yaku[RYANPEI][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 3;
		if (debug == 1) {
			printf("二盃口");
		}
	}
	//同数牌2人組（対子）が7つ作れた場合
	if (tiitoi >= 1 && yaku[RYANPEI][yaku_syukai] == 0) {
		yaku[TIITOI][yaku_syukai]++;
		yaku[FAN][yaku_syukai] += 2;
		tiitoi = 0;
		if (debug == 1) {
			printf("七対子");
		}
	}
	//九蓮宝燈の条件を満たした場合　役満　　　※詳細はググってください
	if (yaku[TYUUREN][yaku_syukai] == 1) {
		yakuman++;
		if (debug == 1) {
			printf("九蓮宝燈");
		}
	}
	//より得点の高い周回を yaku[FAN][0]に保存していく
	if (yaku[FAN][0] < yaku[FAN][1]) {
		for (roop_A = 0; roop_A < 10; roop_A++) {
			yaku[roop_A][0] = yaku[roop_A][1];
		}
	}
	if (yaku_syukai < 1)
		yaku_syukai++;
	
	//一度でも上がれたら上がれたフラグON
	flag_agari = 1;
}