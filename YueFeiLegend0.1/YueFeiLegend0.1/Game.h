#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef enum PropType{
    WEAPON, ARMOR, CARD
} PropType;

/* ���߽ṹ */
typedef struct Prop{
    int id;
    char name[50];
    PropType propType;   //��������
    int level;
    union {
        int minAttack;
        int minDefence;
    };
    union {
        int maxAttack;
        int maxDefence;
    };
    double price;   //�۸�
    int stock;  //�����
    char desc[1000];    //����
} Prop;
/* ���ɽṹ */
typedef struct Martial{
    int id;
    char name[50];
    COORD coord;    //��������
    char desc[1000];    //��������
} Martial;
/* �����ṹ */
typedef struct Bag {
    int id;
    char name[50];
    int playerId;   //�������
    int count;  //��ǰ��ұ����й��ж��ٸ�����
    int max;    //��ǰ��ұ������Ŀɷŵ�����
    Prop props[20];
} Bag;
/* ��ҽṹ */
typedef struct Player{
    int id;
    char name[50];
    char password[50];
    int level;
    int maxExp;    //�������辭��ֵ
    int exp;    //��ǰ����ֵ
    int maxHp;   //�������ֵ������ʼ����ֵ
    int maxMp;  //�������ֵ������ʼ����ֵ ����
    int hp; //��ǰ����ֵ
    int mp; //��ǰ��
    int minAttack;
    int maxAttack;
    int minDefence;
    int maxDefence;
    Prop weapon;
    Prop armor;
    Martial martial;    //��������
    COORD coord;    //��ҵ�ǰ��������
    Bag bag;
    int money;
} Player;

/* ��ͼ�ṹ */
typedef struct Map {
    int id;
    char name[50];
    char fullName[50];  //��ϸ����
    COORD coord;    //��ͼ��������
    char desc[1000];    //��ͼ����
} Map;

typedef struct Monster {
    int id;
    char name[50];
    char desc[1000];
    COORD coord;
    int state;
    int level;  //�ȼ�
    int hp; //Ѫ��
    int minExp; //��С����ֵ
    int maxExp; //�����ֵ
    int minAttack;  //��С������
    int maxAttack;  //��󹥻���
    int minMoney;   //��С��Ǯ
    int maxMoney;   //����Ǯ
} Monster;

void Init();

void RefreshMap(int x, int y);

void Move(int x, int y);

void ShowWelcome();

void RefreshInfo();

void InitMenu();

void GetMapSize(int* x, int* y);

void ProcessMenu(char key);

void ShowPlayer();

void WatchAround(int x, int y);

Monster* CreateMonster(const Monster* monster);

int RefreshMonster(Monster* monsterArr, int* monsterCount, int row);

void Fight(Player* player, Monster* monster, int row);

/* չʾ�̵����Ʒ */
void ShowStoreProps();

/* ������� */
void StoreTrade(Player* player, Prop* prop, int offset, int row);
