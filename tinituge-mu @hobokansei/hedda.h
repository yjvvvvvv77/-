

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


//�ʎq���
int atama, koutu, syuntu;							// 2�����v�R���r�A3�����v�g���I�A�K�i�g���I

//�v�����֘A
int tehai_data[14] , draw , e, kaburi[9] ;			//��v�@�c���v�@����v�����G���[�t���O
													//�@�@���c���v��14�v�̂������߂ň������v�i���a����Ŏg�p�j
//�c���v�ǐ�
int tumo_check, tumohai;							//�c�������v�̃f�[�^�𓮂����t���O�I�ȁ@�c���v�f�[�^����`��Ɋ���U�����l


//���[�v��ʎq���⏕��
int kotu_atama, syuntu_atama, roop_A, roop_B, roop_tehai, dual_over;	//���q�A���q���ꂼ��A�^�}�p�^�[�����炵�@�ėp���[�v2��@��v���������[�v�@�����v2�ȏ�̐��i���̕��A�^�}�p�^�[����������̂Ń��[�v�Ɏg�p�j�@


//��v�Ƒ҂�
int  tehai[9], mati[10],user_mati[10];				//�v�����f�[�^�����ۂ̈�`��ɐU�蕪�����f�[�^�@���ۂ̑҂��@���[�U�[���I�������҂�

//�t���O�֘A
int final_answer, flag_sute, flag_mati, flag_agari,flag_furiten, flag_reverce,pinflag;			//�u�オ���Ă܂����H�v�̎���,�@�v���]���ă��[�`��������邩�t���O,�@���a�����邩����i�\��j
//�����p�t���O
int sutehai, amari, iipei, ittu, tiitoi, tyuren;	//�u���v�v�I�����̔v�����p,�@�����ŗ]�����v�̐�,�@�g�ݍ��ݎ��������q2����,�@123 456 789�i��C�ʊсj�����鎞�p,�@2�~7��,�@��@�󓕃t���O
int yaotyu, yakuman;								//��v��1��9�𔻒�i0�Ȃ�f���j,�@�𖞃t���O

//�𔻒�A�������c��
int yaku_syukai, yaku[10][2];						// 1 �|��  2 �f���  3 ���a 4 ���Ύq 5 �O�Í� 6 �l�Í� 7 ��u�� 8 ��u�� 9 ��C�ʊ� 10 ��@��

//�f�o�b�O���[�h�p
int debug;											//�@1�ɂ����画��̗��ꓙ����