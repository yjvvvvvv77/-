#include<stdio.h>
#include"hedda.h"

//刻子と順子の順番が変わってる以外はkotu_judgeと同じ

void syuntu_judge(int a[]) {						//順子優先役作り
	int b, syuntu_tehai[9], x = 0, y = 0, h = 0, d = 0, roop_A = 0;
	atama = 0;
	flag_mati = 0;

	for (b = 0; b < 9; b++) {
		syuntu_tehai[b] = a[b];

		if ((b == 0 || b == 8)
			&& syuntu_tehai[b] >= 1) {
			yaotyu++;
		}

	}
	if (syuntu_tehai[0] == 3 && syuntu_tehai[8] == 3) {

		for (b = 1; b < 8; b++) {
			if (syuntu_tehai[b] >= 1)
				tyuren++;
			if (syuntu_tehai[b] >= 2)
				tyuren += 2;
			if (tyuren == 8) {
				yaku[TYUUREN][0]++;
				yaku_judge();
			}
		}
	}
	for (; atama < 1 && syuntu_atama < 9; syuntu_atama++) {

		if (syuntu_tehai[syuntu_atama] >= 2) {
			if (debug == 1) {
				printf("\n%d頭", syuntu_atama + 1);
			}
			atama++;
			syuntu_tehai[syuntu_atama] -= 2;
			h = syuntu_atama;
			if (flag_reverce == 1)
				h = 10 - (h + 1) - 1;
		}
	}

	for (b = 0; b < 9; b++) {

		if (syuntu_tehai[b] >= 2
			&& syuntu_tehai[b + 1] >= 2
			&& syuntu_tehai[b + 2] >= 2) {

			if (debug == 1) {
				printf("\n%d%d%d一盃口", b + 1, b + 2, b + 3);
			}
			if ((b != 0 && b != 6)
				&& (tumohai == b + 2 || tumohai == b))
				pinflag = 1;

			syuntu_tehai[b] -= 2, syuntu_tehai[b + 1] -= 2, syuntu_tehai[b + 2] -= 2;
			b--;
			iipei++;
			syuntu += 2;

		} else if (syuntu_tehai[b] >= 1
			&& syuntu_tehai[b + 1] >= 1
			&& syuntu_tehai[b + 2] >= 1) {

			if (debug == 1) {
				printf("\n%d%d%d順子", b + 1, b + 2, b + 3);
			}
			syuntu++;

			if ((b != 0 && b != 6)
				&& (tumohai == b + 2 || tumohai == b))
				pinflag = 1;

			syuntu_tehai[b] -= 1, syuntu_tehai[b + 1] -= 1, syuntu_tehai[b + 2] -= 1;
			b--;

		} else if (syuntu_tehai[b] == 3) {
			if (debug == 1) {
				printf("\n%d刻子", b + 1);
			}
			koutu++;
			syuntu_tehai[b] -= 3;
			b--;
		}
	}
	for (roop_A = 0; roop_A < 4 && flag_reverce == 1; roop_A++) {
		int temp = syuntu_tehai[roop_A];
		syuntu_tehai[roop_A] = syuntu_tehai[8 - roop_A];
		syuntu_tehai[8 - roop_A] = temp;
	}
	for (b = 0; b < 9; b++) {

		if (syuntu_tehai[b] != 0) {			//余り物チェック
			amari += syuntu_tehai[b];
			flag_mati++;					//待ち移行フラグ

			if (syuntu_tehai[b] == 2) {
				d = b;
				atama++;

			}

			if (flag_mati == 1) {
				x = b;

			}
			if (flag_mati == 2) {
				y = b;

			}
		}

	}
	mati_judge(x, y, h, d);
}