#include<stdio.h>
#include"hedda.h"


void kotu_judge(int a[]) {							//刻子優先役作り
	int b, kotu_tehai[9], x = 0, y = 0, h = 0, d = 0, roop_A = 0;
	
	//1周ごとにリセット
	atama = 0;
	flag_mati = 0;

	//一と九があるか確認
	for (b = 0; b < 9; b++) {
		kotu_tehai[b] = a[b];
		if ((b == 0 || b == 8)
			&& kotu_tehai[b] >= 1) {
			yaotyu++;
		}

	}

	//九蓮宝燈の条件確認
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

	//アタマをどれにするか1周ごとにずらして検討していく
	for (; atama < 1 && kotu_atama < 9; kotu_atama++) {
		if (kotu_tehai[kotu_atama] >= 2) {
			if(debug == 1){
			printf("\n%d頭", kotu_atama + 1);
			}
			atama++;						//アタマ作れたフラグ
			kotu_tehai[kotu_atama] -= 2;	//アタマ作った数牌を2つ減らす
			h = kotu_atama;

			//昇順が終わったら降順で見ていくために数値反転
			if (flag_reverce == 1)
				h = 10 - (h + 1) - 1;


		}
	}

	//刻子（同数3つ）が組めるか確認
	for (b = 0; b < 9; b++) {
		if (kotu_tehai[b] >= 3) {
			if (debug == 1) {
			printf("\n%d刻子", b + 1);
			}
			koutu++;
			kotu_tehai[b] -= 3;				//刻子作った数牌を3つ減らす
			b--;

		}

	}
	//余った数字で順子（階段）が組めるか確認
	for (b = 0; b < 9; b++) {
		//階段を同数で2つ作れる場合（一盃口、二盃口の条件）
		if (kotu_tehai[b] >= 2
			&& kotu_tehai[b + 1] >= 2
			&& kotu_tehai[b + 2] >= 2) {

			if (debug == 1) {
				printf("\n%d%d%d一盃口", b + 1, b + 2, b + 3);
			}

			//123　456　789が全部作れたら一気通貫（ittu == 3）
			if (b == 0 && ittu == 0)
				ittu++;

			if (b == 3 && ittu < 2)
				ittu++;

			if (b == 6)
				ittu++;

			iipei++;
			syuntu += 2;

			//順子（階段）が成立していて
			//bの牌が一または七でない時　かつ　ツモ牌が階段の真ん中以外に組み込まれたとき＝平和条件達成
			if ((b != 0 && b != 6)
				&& (tumohai == b + 2 || tumohai == b))
				pinflag = 1;

			//組まれた牌を手牌から消す
			kotu_tehai[b] -= 2, kotu_tehai[b + 1] -= 2, kotu_tehai[b + 2] -= 2;
			b--;

			
		// 1牌ずつ使った階段を作れる場合（基本は上の一盃口と一緒）
		} else if (kotu_tehai[b] >= 1
			&& kotu_tehai[b + 1] >= 1
			&& kotu_tehai[b + 2] >= 1) {

			if (debug == 1) {
				printf("\n%d%d%d順子", b + 1, b + 2, b + 3);
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
	//昇順降順切り替え
	for (roop_A = 0; roop_A < 4 && flag_reverce == 1; roop_A++) {
		int temp = kotu_tehai[roop_A];
		kotu_tehai[roop_A] = kotu_tehai[8 - roop_A];
		kotu_tehai[8 - roop_A] = temp;
	}

	for (b = 0; b < 9; b++) {

		if (kotu_tehai[b] != 0) {		//余り物チェック
			amari += kotu_tehai[b];
			flag_mati++;				//待ち移行フラグ

			if (kotu_tehai[b] == 2) {
				d = b;
				atama++;

			}
			if (flag_mati == 1)			//余り1つ目はxへ
				x = b;
			if (flag_mati == 2)			//2つ目はyへ
				y = b;
		}
	}

	mati_judge(x, y, h, d, yaku_syukai);

}