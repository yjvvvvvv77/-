#include<stdio.h>
#include"hedda.h"

//ƒAƒKƒ‰ρ“‚µ‚½κ‡
int answer_agari(){									

	//ƒcƒ‚”v‚πθ”v‚Ζ‚µ‚Δ‰Α‚¦‚ι
	tehai_data[13] = draw;
	for (roop_A = 0; roop_A < 9; roop_A++) {
		kaburi[roop_A] = 0;
		tehai[roop_A] = 0;
	}

	//‰ό‚ί‚Δ•ΐ‚Ρ‘Φ‚¦
	qsort(tehai_data, 13, sizeof(int), compareInt);

	//‰ό‚ί‚ΔU‚θ•ª‚―
	for (roop_A = 0; roop_A < 14; roop_A++) {
		furiwake(tehai_data[roop_A]);
	}
	printf("\n");

	//ƒeƒXƒg—p
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

	//ƒcƒ‚”v‘€μƒtƒ‰ƒO‰π
	tumo_check = 0;

	
	//‰ό‚ί‚Δθ”v•\¦
	for (roop_A = 0; roop_A < 9; roop_A++)
	haihyouji(tehai);

	printf("\n");

	for (roop_A = 0; roop_A < 14; roop_A++) {
		printf("δέ ");
	}

	
	//θ”v‚π‘g‚έ‘Φ‚¦‚Δ–π‚β‘Ò‚Ώ‚π“Ά‚µ‚Ιs‚­
	yaku_serch();



	//γ‚ª‚κ‚Δ‚ι‚©‚Η‚¤‚©‚Ζ–π•\¦

	/*for (n = 0; n<11; n++) {*/
	printf("\n–π\n");
	if (flag_agari == 0) {
		printf("\nγ‚ª‚κ‚Δ‚ά‚Ή‚ρII");
	} else if (yakuman == 0) {
		printf("\n–ε‘O΄©–Μa");
		yaku[FAN][0] += 1;
		printf("\n΄κF");
		yaku[FAN][0] += 6;
		if (yaku[TANYAO][0] >= 1)
			printf("\n’f›τ‹γ");
		if (yaku[PINFU][0] >= 1)
			printf("\n•½a");
		if (yaku[IIPEI][0] >= 1)
			printf("\nκ”uϋ");
		if (yaku[ITTU][0] >= 1)
			printf("\nκ‹C’ΚΡ");
		if (yaku[TIITOI][0] >= 1)
			printf("\nµ‘Ξq");
		if (yaku[RYANPEI][0] >= 1)
			printf("\n“ρ”uϋ");
		if (yaku[SANAN][0] >= 1)
			printf("\nOΓ");

		printf("\n%d–|\n\n", yaku[FAN][0]);
		if (yaku[FAN][0] <= 7) {
			printf("’µ–\t");
			printf("12000“_\n");
		} else if (yaku[FAN][0] <= 10) {
			printf("”{–\t");
			printf("16000“_\n");
		} else if (yaku[FAN][0] <= 12) {
			printf("O”{–\t");
			printf("24000“_\n");
		}
	}
	if (yaku[SUUAN][0] >= 1)
	printf("\nlΓ");
	if (yaku[TYUUREN][0] >= 1)
	printf("\n‹γ@•σ“•");
	if (yaku[FAN][0] >= 13 || yakuman > 0) {
		printf("\n–π–");
		printf("\t32000“_\n");
		}


	}
