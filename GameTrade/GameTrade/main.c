#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��Ʒ�ṹ
typedef struct Prop {
	int id;
	char name[50];
	double price;
	int stock;	//�����������ڱ����У����ʾ�˵��ߵĵ�������
	char desc[100];
} Prop;

//�����ṹ
typedef struct Bag {
	int id;
	int playerId;
	char name[50];
	int max;	//��ǰ�����Ĳ����������������һ�����ԷŶ��ٸ�����
	int count;	//��ǰ���е��ߵ�������
	Prop props[8];
} Bag;

//��ҽṹ
typedef struct Player {
	int id;
	char name[50];
	char password[50];
	double gold;	//��ҵĽ������
	double sysee;	//Ԫ������
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
	printf("***************************���׺�*****************************\n");
    showProps();
	showPlayers();
	return 0;
}

void init() {
	static Prop propArray[] = {
		{1, "˫�����鿨", 3000, 10, "˫��666"},
		{2, "���õĵ���", 5000, 8, "ֻ��Զ�۲�������"},
		{3, "���������", 8000, 10, "����ר��"},
		{4, "һ����", 13000, 5, "��ǹ���룬ˮ����"},
		{5, "ֱ��һ����", 83000, 8, "���˻����"}
	};
	props = propArray;
	propCount = sizeof(propArray) / sizeof(Prop);
	static Player playerArray[] = {
		{1, "����ëë��", "123456", .gold=50000, .bag={.playerId=1, .name="����ëë��ı���", .max=8, .count=0}},
		{2, "���ް�����", "123456", .gold=100000, .bag={.playerId=2, .name="���ް������ı���", .max=8, .count=0}},
		{3, "Ԫʼ����֮ͽ", "123456", .gold=1000000, .bag={.playerId=3, .name="Ԫʼ����֮ͽ�ı���", .max=8, .count=0}},
		{4, "�Ǻ�", "123456", .gold=100000000, .bag={.playerId=4, .name="�Ǻӵı���", .max=8, .count=0}}
	};
	playerCount = sizeof(playerArray) / sizeof(Player);
	players = playerArray;
}

void showPlayers() {
	int i = 0;
	int j = 0;
	printf("%-5s\t%-14s\t%-10s\n", "���", "�������", "��Ǯ");
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
    printf("%-5s\t%-14s\t%-10s\t%-10s\n\n", "���", "��������", "�۸�", "���");
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
            tradeProp = props + i;  //����Ҫ��ôд��tradeProp������Ӧ����props���������i��Ԫ�صĵ�ַ��������prop�ĵ�ַ
            break;
        }
    }
    if(tradeProp->stock <=0) {
        printf("��Ʒ��治��\n");
        return;
    }
    if(player->gold < tradeProp->price) {
        printf("���㣬�޷�����\n");
        return;
    }
    if(player->bag.count >= player->bag.max) {
        printf("�����Ų�����\n");
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
