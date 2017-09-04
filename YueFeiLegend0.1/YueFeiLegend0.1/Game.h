#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef enum PropType{
    WEAPON, ARMOR, CARD
} PropType;

/* 道具结构 */
typedef struct Prop{
    int id;
    char name[50];
    PropType propType;   //道具类型
    int level;
    union {
        int minAttack;
        int minDefence;
    };
    union {
        int maxAttack;
        int maxDefence;
    };
    double price;   //价格
    int stock;  //库存量
    char desc[1000];    //描述
} Prop;
/* 门派结构 */
typedef struct Martial{
    int id;
    char name[50];
    COORD coord;    //门派坐标
    char desc[1000];    //门派描述
} Martial;
/* 背包结构 */
typedef struct Bag {
    int id;
    char name[50];
    int playerId;   //归属玩家
    int count;  //当前玩家背包中共有多少个道具
    int max;    //当前玩家背包最大的可放道具数
    Prop props[20];
} Bag;
/* 玩家结构 */
typedef struct Player{
    int id;
    char name[50];
    char password[50];
    int level;
    int maxExp;    //升级所需经验值
    int exp;    //当前经验值
    int maxHp;   //最大生命值，即初始生命值
    int maxMp;  //最大内力值，即初始内力值 即蓝
    int hp; //当前生命值
    int mp; //当前蓝
    int minAttack;
    int maxAttack;
    int minDefence;
    int maxDefence;
    Prop weapon;
    Prop armor;
    Martial martial;    //归属门派
    COORD coord;    //玩家当前所在坐标
    Bag bag;
    int money;
} Player;

/* 地图结构 */
typedef struct Map {
    int id;
    char name[50];
    char fullName[50];  //详细名称
    COORD coord;    //地图所在坐标
    char desc[1000];    //地图描述
} Map;

typedef struct Monster {
    int id;
    char name[50];
    char desc[1000];
    COORD coord;
    int state;
    int level;  //等级
    int hp; //血量
    int minExp; //最小经验值
    int maxExp; //最大经验值
    int minAttack;  //最小攻击力
    int maxAttack;  //最大攻击力
    int minMoney;   //最小金钱
    int maxMoney;   //最大金钱
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

/* 展示商店的商品 */
void ShowStoreProps();

/* 购买道具 */
void StoreTrade(Player* player, Prop* prop, int offset, int row);
