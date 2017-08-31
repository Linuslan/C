#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/* 道具结构 */
typedef struct Prop{
    int id;
    char name[50];
    int type;   //道具类型
    union minProperty {
        int minAttack;
        int minDefence;
    };
    union maxProperty {
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
    Prop weapon;
    Prop armor;
    int life;   //初始生命值
    int force;  //初始内力值 即蓝
    int hp; //当前生命值
    int mp; //当前蓝
    int minAttack;
    int maxAttack;
    int minDefence;
    int maxDefence;
    Martial martial;    //归属门派
    COORD coord;    //玩家当前所在坐标
    Bag bag;
} Player;

/* 地图结构 */
typedef struct Map {
    int id;
    char name[50];
    char fullName[50];  //详细名称
    COORD coord;    //地图所在坐标
    char desc[1000];    //地图描述
} Map;
