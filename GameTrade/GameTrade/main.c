#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void trade(Player* player, int propId);
int main() {
	init();
	showProps();
	showPlayers();
	Player* player = &(players[3]);
	trade(player, 2);
	printf("***************************交易后*****************************\n");
    showProps();
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
	int j = 0;
	printf("%-5s\t%-14s\t%-10s\n", "编号", "玩家名称", "金钱");
	for(; i < playerCount; i ++) {
		Player temp = *(players + i);
		printf("%-5d\t%-14s\t%-10.2lf\n\n", temp.id, temp.name, temp.gold);
		for(; j < temp.bag.count; j ++) {
            printf("%-5d\t%-14s\t%-10.2lf\n", temp.bag.props[j].stock, temp.bag.props[j].name, temp.bag.props[j].price);
		}
		printf("\n");
	}
	printf("\n\n");
}

void showProps() {
    int i = 0;
    printf("%-5s\t%-14s\t%-10s\t%-10s\n\n", "编号", "道具名称", "价格", "库存");
    for(; i < propCount; i ++) {
        Prop prop = *(props + i);
        printf("%-5d\t%-14s\t%-10.2f\t%-10d\n\n", prop.id, prop.name, prop.price, prop.stock);
    }
    printf("\n\n");
}

void trade(Player* player, int propId) {
    int i = 0;
    Prop* tradeProp = NULL;
    for(; i < propCount; i ++) {
        Prop prop = *(props + i);
        if(prop.id == propId) {
            tradeProp = props + i;  //必须要这么写，tradeProp里面存的应该是props数组里面第i个元素的地址，而不是prop的地址
            break;
        }
    }
    if(tradeProp->stock <=0) {
        printf("商品库存不足\n");
        return;
    }
    if(player->gold < tradeProp->price) {
        printf("金额不足，无法购买\n");
        return;
    }
    if(player->bag.count >= player->bag.max) {
        printf("背包放不下啦\n");
        return;
    }
    tradeProp->stock --;
    player->gold -= tradeProp->price;
    Prop* prop = NULL;
    for(i = 0; i < player->bag.count; i ++) {
        prop = &(player->bag.props[i]);
        if(prop->id == tradeProp->id) {
            prop->stock ++;
        }
    }
    if(i == player->bag.count) {
        player->bag.props[i].id = tradeProp->id;
        strcpy(player->bag.props[i].name, tradeProp->name);
        strcpy(player->bag.props[i].desc, tradeProp->desc);
        player->bag.props[i].price = tradeProp->price;
        player->bag.props[i].stock = 1;
    }
    player->bag.count++;
}
