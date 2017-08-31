#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/* ���߽ṹ */
typedef struct Prop{
    int id;
    char name[50];
    int type;   //��������
    union minProperty {
        int minAttack;
        int minDefence;
    };
    union maxProperty {
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
    Prop weapon;
    Prop armor;
    int life;   //��ʼ����ֵ
    int force;  //��ʼ����ֵ ����
    int hp; //��ǰ����ֵ
    int mp; //��ǰ��
    int minAttack;
    int maxAttack;
    int minDefence;
    int maxDefence;
    Martial martial;    //��������
    COORD coord;    //��ҵ�ǰ��������
    Bag bag;
} Player;

/* ��ͼ�ṹ */
typedef struct Map {
    int id;
    char name[50];
    char fullName[50];  //��ϸ����
    COORD coord;    //��ͼ��������
    char desc[1000];    //��ͼ����
} Map;
