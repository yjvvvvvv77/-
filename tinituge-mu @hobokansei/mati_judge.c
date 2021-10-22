#include<stdio.h>
#include"hedda.h"

//リーチ時なら何待ちか表示　
void mati_judge(int x, int y, int h, int d) {

	int roop_A, roop_B = 0;

	
	//amariが0なら役判定(yaku_judge)へ
	if (amari == 0) {
		yaku_judge();
	}

	//二盃口　＞　七対子処理
	else if (tiitoi >= 1)
		if (iipei == 2) {
			tiitoi = 0;
			yaku_judge();
		}

	//七対子処理
	if (amari > 3 && dual_over == 7) {
		iipei = 0;
		yaku_judge();
	}

	//余りが2つ以下の時　待ちチェック
	if (amari < 3 && yaku_syukai == 0) {							

		if (dual_over > 6) {
			if (debug == 1) {
				printf("七対子");
			}
		//アタマが2つの時
		} else if (atama > 1) {
			if (debug == 1) {
				printf("\n%d、%d刻子アタマ待ち", h + 1, d + 1);
			}
			mati[h + 1]++; mati[d + 1]++;				//待てる数として記録
			if ((sutehai  == h)  || (sutehai == d) )	//待ち牌が捨てた牌であればフリテンとして記録
				flag_furiten = 1;
		} else if (flag_mati == 1) {					//待ち牌に関わる牌が1種類の時
			if (debug == 1) {
				printf("\n%dアタマ単騎待ち", x + 1);
			}
			mati[x + 1]++;
			if (sutehai == x )
				flag_furiten = 1;
		}if(atama >= 1){
		if (flag_mati == 2) {							//待ち牌に関わる牌が2種類の時
			if (x + 2 == y) {
				if (debug == 1) {
					printf("\n%d待ち", x + 2);			//2種類の牌の間に待ち牌が入る形
				}
				mati[x + 2]++;
				if (sutehai  == x + 1)
					flag_furiten = 1;
			} else if (x != 0 && x != 7
				&& (x + 1 == y && x > 0)) {
				if (debug == 1) {
					printf("\n%d、%d待ち", x, x + 3);	//2種類の牌が続いていて、その前後で待てる形
				}
				mati[x]++; mati[x + 3]++;
				if ((sutehai + 1) == x || (sutehai + 1) == x + 3)			//
					flag_furiten = 1;
			} else if (x + 1 == y && x == 0) {			//2種類続いている牌が端っこ（1＆2 or 8＆9）	
				if (debug == 1) {
					printf("\n%d待ち", x + 3);
				}
				mati[x + 3]++;
				if (sutehai + 1 == x + 3)
					flag_furiten = 1;
			} else if (x == 7 && y == 8) {				//2種類続いている牌が端っこ（1＆2 or 8＆9）	
				if (debug == 1) {
					printf("\n%d待ち", x);
				}
				mati[x]++;
				if (sutehai + 1 == x)
					flag_furiten = 1;
			}
		}
		}
		
	//七対子を待つ形
	} if (amari >= 3 && dual_over >= 6 && final_answer == 1) {
		for (roop_A = 0; roop_A < 9; roop_A++) {
			if (tehai[roop_A] == 1) {
				roop_B = roop_A + 1;
				if (flag_reverce == 0) {
					if (debug == 1) {
						printf("\n七対子%d単騎待ち", roop_B);
					}
					if (sutehai == roop_B)
						flag_furiten = 1;
				} else if (flag_reverce == 1) {
					roop_B = 10 - roop_B;
					if (debug == 1) {
						printf("\n七対子%d単騎待ち", roop_B);
					}
					if (sutehai == roop_B)
						flag_furiten = 1;
				}
			}
		}
	}

	//1周組み替えて検討後、フラグをすべてリセット
	flag_mati = 0;
	amari = 0;
	iipei = 0, ittu = 0, koutu = 0, syuntu = 0, yaotyu = 0, tyuren = 0; pinflag = 0;

	for (roop_A = 0; roop_A < 10; roop_A++) {
		yaku[roop_A][yaku_syukai] = 0;
	}
}