

#define FAN		0
#define TANYAO	1
#define PINFU	2
#define TIITOI	3
#define SANAN	4
#define SUUAN   5
#define IIPEI	6
#define RYANPEI 7
#define ITTU	8
#define TYUUREN 9



extern void kotu_judge(int a[]);
extern void syuntu_judge(int a[]);
extern void mati_judge(int x, int y, int h, int d);
extern void haihyouji();
extern void furiwake(int a);
extern void yaku_judge();
extern int  answer_agari();
extern int  answer_tenpai();
extern int  answer_noten();
extern int  compareInt(const void *a, const void *b);


//面子作り
int atama, koutu, syuntu;							// 2つ同じ牌コンビ、3つ同じ牌トリオ、階段トリオ

//牌生成関連
int tehai_data[14] , draw , e, kaburi[9] ;			//手牌　ツモ牌　同一牌生成エラーフラグ
													//　　※ツモ牌＝14牌のうち直近で引いた牌（平和判定で使用）
//ツモ牌追跡
int tumo_check, tumohai;							//ツモった牌のデータを動かすフラグ的な　ツモ牌データを一～九に割り振った値


//ループや面子作り補助等
int kotu_atama, syuntu_atama, roop_A, roop_B, roop_tehai, dual_over;	//刻子、順子それぞれアタマパターンずらし　汎用ループ2種　手牌生成時ループ　同数牌2つ以上の数（その分アタマパターンが増えるのでループに使用）　


//手牌と待ち
int  tehai[9], mati[10],user_mati[10];				//牌生成データ→実際の一～九に振り分けたデータ　実際の待ち　ユーザーが選択した待ち

//フラグ関連
int final_answer, flag_sute, flag_mati, flag_agari,flag_furiten, flag_reverce,pinflag;			//「上がってますか？」の質問,　牌が余ってリーチをかけれるかフラグ,　平和いけるか判定（予定）
//役作り用フラグ
int sutehai, amari, iipei, ittu, tiitoi, tyuren;	//「聴牌」選択時の牌交換用,　役作りで余った牌の数,　組み込み時同数順子2つ処理,　123 456 789（一気通貫）が作れる時用,　2×7役,　九蓮宝燈フラグ
int yaotyu, yakuman;								//手牌の1と9を判定（0なら断幺九）,　役満フラグ

//役判定、高い方残し
int yaku_syukai, yaku[10][2];						// 1 翻数  2 断幺九  3 平和 4 七対子 5 三暗刻 6 四暗刻 7 一盃口 8 二盃口 9 一気通貫 10 九蓮宝燈

//デバッグモード用
int debug;											//　1にしたら判定の流れ等可視化