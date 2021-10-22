#include<stdio.h>
#include"hedda.h"

void haihyouji() {							//牌表示　兼　0～35を一～九に振り分け	兼　ツモ牌の数値を区別
	int n = 0;

	for (; roop_A < 9; ) {
		if (tehai[roop_A] != 0) {
			break;
		} else
			break;
	}

	if (roop_A >= 0 && roop_A <= 8){								//エラー回避用
	if (tehai[roop_A] >= 0 && tehai[roop_A] <= 9) {					//エラー回避用
		n = tehai[roop_A];
	}
	}
	
	
	if (tumo_check == 1) {											//ツモ牌の振り分け時
		n = 1;
		roop_A = tumohai;
	}
	for (; n > 0; n--) {



		if (roop_A == 0)
			printf("一 ");
		else if (roop_A == 1)
			printf("二 ");
		else if (roop_A == 2)
			printf("三 ");
		else if (roop_A == 3)
			printf("四 ");
		else if (roop_A == 4)
			printf("伍 ");
		else if (roop_A == 5)
			printf("六 ");
		else if (roop_A == 6)
			printf("七 ");
		else if (roop_A == 7)
			printf("八 ");
		else if (roop_A == 8)
			printf("九 ");
	}

}


void furiwake(int a) {
	int b = 0;

	if (a < 4)
		b = 0;
	else if (a < 8)
		b = 1;
	else if (a < 12)
		b = 2;
	else if (a < 16)
		b = 3;
	else if (a < 20)
		b = 4;
	else if (a < 24)
		b = 5;
	else if (a < 28)
		b = 6;
	else if (a < 32)
		b = 7;
	else if (a < 36)
		b = 8;
	if (flag_sute == 0) {						
		tehai[b]++;
		tumohai = b;
	}
	if (flag_sute == 1) {
		sutehai = b;
	}
}