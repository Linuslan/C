#include <stdio.h>
#include <stdlib.h>
//商品结构 
typedef struct Prop {
	int id;
	char name[50];
	double price;
	int stock;	//库存量，如果在背包中，则表示此道具的叠加数量 
	char desc[100];
} Prop;

//背包结构 
typedef struct Bag {
	int id;
	int playerId;
	char name[50];
	int max;	//当前背包的插槽总数，即背包中一共可以放多少个道具 
	int count;	//当前所有道具的数量合
	Prop props[8];
} Bag;

//玩家结构 
typedef struct Player {
	int id;
	char name[50];
	char password[50];
	double gold;	//玩家的金币数量 
	double sysee;	//元宝数量 
	Bag bag;
} Player;

Player* players;
Prop* props;
int playerCount = 0;
int propCount = 0;

void init();
void showPlayers();
void showProps();
int main(int argc, char *argv[]) {
	system("chcp 65001");
    system("cls");
	init();
	showPlayers();
	return 0;
}

void init() {
	static Prop propArray[] = {
		{1, "双倍经验卡", 3000, 10, "双击666"},
		{2, "腐烂的道袍", 5000, 8, "只可远观不可亵玩"},
		{3, "生锈的铁剑", 8000, 10, "新手专用"},
		{4, "一级袍", 13000, 5, "刀枪不入，水火不侵"},
		{5, "直升一级丹", 83000, 8, "吃了还想吃"}
	};
	props = propArray;
	propCount = sizeof(propArray) / sizeof(Prop);
	static Player playerArray[] = {
		{1, "超级毛毛虫", "123456", .gold=50000, .bag={.playerId=1, .name="超级毛毛虫的背包", .max=8, .count=0}},
		{2, "塔罗奥特曼", "123456", .gold=100000, .bag={.playerId=2, .name="塔罗奥特曼的背包", .max=8, .count=0}},
		{3, "元始天尊之徒", "123456", .gold=1000000, .bag={.playerId=3, .name="元始天尊之徒的背包", .max=8, .count=0}},
		{4, "星河", "123456", .gold=100000000, .bag={.playerId=4, .name="星河的背包", .max=8, .count=0}}
	};
	playerCount = sizeof(playerArray) / sizeof(Player);
	players = playerArray;
}

void showPlayers() {
	int i = 0;
	printf("你好%-5s\t%-14s\t%-10s\n", "编号", "玩家名称", "金钱");
	for(i = 0; i < playerCount; i ++) {
		Player temp = *(players + i);
		printf("%-5d\t%-14s\t%-10.2lf\n", temp.id, temp.name, temp.gold);
	}
}
