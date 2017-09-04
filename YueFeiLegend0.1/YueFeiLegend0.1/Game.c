#include <time.h>
#include <ctype.h>
#include "Game.h"
#include "GameLib.h"
#include "Constant.h"
int welcom_start_row = 0;
int map_start_row = 0;
int init_menu_start_row = 0;
int init_info_start_row = 0;
Player* loginPlayer = NULL;
extern int x;
extern int y;

/* ��ʼ�������Ϣ */
Player players[] = {
    {1, "�Է���", "123456", .money=50000, .level=1, .maxExp=20, .exp=0, .maxHp=100, .hp=100, .maxMp=50, .mp=50, .minAttack=5, .maxAttack=10, .minDefence=5, .maxDefence=10,
     .weapon={1, "���������", WEAPON, 1, .minAttack=5, .maxAttack=10, .price=100, .desc="����ר��"},
     .armor={2, "�ƾɵĻ���", ARMOR, 2, .minDefence=5, .maxDefence=10, .price=500, .desc="����ר��"},
     .martial={3, "���Ҿ�"}, .coord={0, 0},
     .bag={
         .count=1, .max=9,
        .props={
            {
            3, "ľǹ", WEAPON, .level=5, .minAttack=10, .maxAttack=15, .price=500, .stock=1, .desc="�ʺϳ��뽭��������"
            }
        }
     }},
    {2, "GM", "123456", .money=65535, .level=9999, .maxExp=65535, .exp=65535, .maxHp=65535, .maxMp=65535, .minAttack=65535, .maxAttack=65535, .minDefence=65535, .maxDefence=65535, .weapon={}, .armor={}, .martial={}, .coord={}, .bag={}}
};
/* ��ʼ������ */
Prop props[] = {
    {
        1, "���������", WEAPON, .level=1, .minAttack=5, .maxAttack=10, .price=100, .stock=50, .desc="����ר��"
    }, {
        2, .name="�ƾɵĻ���", ARMOR, .level=2, .minDefence=5, .maxDefence=10, .price=500, .stock=50, .desc="����ר��"
    }, {
        3, .name="ľǹ", WEAPON, .level=5, .minAttack=10, .maxAttack=15, .price=500, .stock=50, .desc="�ʺϳ��뽭��������"
    }
};

/* ��ʼ����ͼ */
Map maps[][8] = {
    {
        {
            .id=1, .name="�����", .fullName="�������ڻ��������", .coord={0, 0}, .desc="���ɶ�ʱƯ������"
        },
        {
            .id=2, .name="�ڻ���", .fullName="�������ڻ���", .coord={1, 0}, .desc="�������ڻ��أ�����������"
        },
        {
            .id=3, .name="������", .fullName="������", .coord={2, 0}, .desc="������"
        },
        {
            .id=4, .name="������", .fullName="����������", .coord={3, 0}, .desc="����������"
        },
        {
            .id=5, .name="����", .fullName="����", .coord={4, 0}, .desc="����"
        },
        {
            .id=6, .name="��Ȫɽ", .fullName="������Ȫɽ", .coord={5, 0}, .desc=""
        },
        {
            .id=7, .name="��Ȫ��", .fullName="��Ȫ��", .coord={6, 0}, .desc=""
        },
        {
            .id=8, .name="�Ҳݸ�", .fullName="�Ҳݸ�", .coord={7, 0}, .desc=""
        }
    },
    {
        {
            .id=1, .name="�����1", .fullName="�������ڻ��������", .coord={0, 1}, .desc="���ɶ�ʱƯ������"
        },
        {
            .id=2, .name="�ڻ���2", .fullName="�������ڻ���", .coord={1, 1}, .desc="�������ڻ��أ�����������"
        },
        {
            .id=3, .name="������3", .fullName="������", .coord={2, 1}, .desc="������"
        },
        {
            .id=4, .name="������4", .fullName="����������", .coord={3, 1}, .desc="����������"
        },
        {
            .id=5, .name="����5", .fullName="����", .coord={4, 1}, .desc="����"
        },
        {
            .id=6, .name="��Ȫɽ6", .fullName="������Ȫɽ", .coord={5, 1}, .desc=""
        },
        {
            .id=7, .name="��Ȫ��7", .fullName="��Ȫ��", .coord={6, 1}, .desc=""
        },
        {
            .id=8, .name="�Ҳݸ�8", .fullName="�Ҳݸ�", .coord={7, 1}, .desc=""
        }
    }

};
Martial martial[] = {
    {
        1, "����", {0, 1}, "�����书������"
    },
    {
        2, "�䵱", {1, 0}, "��ɽ��"
    },
    {
        3, "���Ҿ�", {0, 0}, "��ʼ������"
    }
};

Monster monsters[] = {
    {
        1, "��å", "�������Ľ�ɫ", {0, 0}, .state=0, 1, 50, .minExp=1, .maxExp=5, .minAttack=1, .maxAttack=5, .minMoney=1, .maxMoney=5
    },
    {
        2, "��Ʀ", "�������Ľ�ɫ", {0, 0}, .state=0, 1, 50, .minExp=1, .maxExp=5, .minAttack=1, .maxAttack=5, .minMoney=1, .maxMoney=5
    },
    {
        3, "���", "��һ���Ĺ�����", {0, 0}, .state=0, 2, 100, .minExp=2, .maxExp=10, .minAttack=2, .maxAttack=10, .minMoney=2, .maxMoney=20
    },
    {
        4, "���ͷĿ", "СȺ�������ͷĿ", {0, 0}, .state=0, 3, 200, .minExp=2, .maxExp=20, .minAttack=2, .maxAttack=20, .minMoney=2, .maxMoney=30
    },
    {
        5, "����ϴ�", "��ȺȺ��������쵼�ˣ����켸�����ͷĿ", {0,0}, .state=0, 5, 300, .minExp=3, .maxExp=30, .minAttack=3, .maxAttack=30, .minMoney=3, .maxMoney=50
    }
};

void SavePlayers() {
    FILE* playerFile = NULL;
    char* playerFileName = "player.data";
    playerFile = fopen(playerFileName, "wb");
    if(!playerFile) {
        printf("������������쳣");
        return;
    }
    int size = sizeof(players) / sizeof(Player);
    for(int i = 0; i < size; i ++) {
        Player player = players[i];
        fwrite(&player, sizeof(Player), 1, playerFile);
    }
}

void ReadPlayer() {
    FILE* playerFile = NULL;
    char* playerFileName = "player.data";
    playerFile = fopen(playerFileName, "rb");
    if(!playerFile) {
        printf("��ʼ����������쳣");
        return;
    }
    Player* player = (Player*)malloc(sizeof(Player));
    printf("��ʼ������\n");
    while(fread(player, sizeof(Player), 1, playerFile) > 0) {

    }
}

void Init() {
    map_start_row = 3;
    init_info_start_row = map_start_row + sizeof(maps) / sizeof(maps[0]) + 1;
    init_menu_start_row = init_info_start_row + 11;
    loginPlayer = &players[0];
}

void ShowWelcome() {
    SetPosition(MARGIN_X, welcom_start_row);
    printf(SEP);
    SetPosition(MARGIN_X, ++welcom_start_row);
    printf("|");
    SetPosition(MARGIN_X+45, welcom_start_row);
    printf("��ӭ�������ɵ�����");
    SetPosition(MARGIN_X+OFFSET_X, welcom_start_row);
    printf("|");
    SetPosition(MARGIN_X, ++welcom_start_row);
    printf(SEP);
}

void RefreshMap(int x, int y) {
    int map_y = map_start_row;
    int i, j;
    int size = sizeof(maps) / sizeof(maps[0]);
    int size2 = sizeof(maps[0]) / sizeof(Map);
    for(i = 0; i < size; i ++) {
        SetPosition(MARGIN_X, map_y);
        printf("|");
        SetPosition(MARGIN_X+15, map_y);
        for(j = 0; j < size2; j ++) {
            Map map = maps[i][j];
            if(x == j && y == i) {
                SetColor(7, 4);
            }
            printf("%-9s", map.name);
            SetColor(10, 0);
        }
        SetPosition(MARGIN_X+OFFSET_X, map_y++);
        printf("|");
    }
    SetPosition(MARGIN_X, map_y);
    printf(SEP);
}

void RefreshInfo() {
    int info_start_row = init_info_start_row;
    for(int i = 0; i < 10; i ++) {
        SetPosition(MARGIN_X, info_start_row);
        printf("|");
        for(int j = 0; j < OFFSET_X-1; j ++) {
            printf(" ");
        }
        SetPosition(MARGIN_X+OFFSET_X, info_start_row++);
        printf("|");
    }
    SetPosition(MARGIN_X, info_start_row);
    printf(SEP);
}

void InitMenu() {
    int menu_start_row = init_menu_start_row;
    SetPosition(MARGIN_X, menu_start_row);
    printf("��Ϸ�˵�");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("1���鿴����");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("2���۲���Χ");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("3�����ܲ�");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("4������װ��");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf(CLEAR_SPACE);
    SetPosition(MARGIN_X, menu_start_row);
    printf("��ѡ��������߶�:");
}

void GetMapSize(int* x, int* y) {
    *y = sizeof(maps) / sizeof(maps[0]);
    *x = sizeof(maps[0]) / sizeof(Map);
}

void ProcessMenu(char key) {
    if(key == '1') {    //ִ���������չʾ
        ShowPlayer();
    } else if(key == '2') {
        WatchAround(x, y);
    } else if(key == '4') {
        ShowStoreProps();
    }
}

void ShowPlayer() {
    int info_start_row = init_info_start_row;
    RefreshInfo();
    SetPosition(MARGIN_X+45, info_start_row++);
    printf("��������");
    SetPosition(MARGIN_X+7, info_start_row++);
    printf("������%-10s����%d(%d/%d)\tHP��%d/%d\tMP��%d/%d\t��Ǯ��%-10d", loginPlayer->name, loginPlayer->level, loginPlayer->exp,
            loginPlayer->maxExp, loginPlayer->hp, loginPlayer->maxHp, loginPlayer->mp, loginPlayer->maxMp, loginPlayer->money);
    SetPosition(MARGIN_X+7, info_start_row++);
    printf("���ɣ�%-10s������%s(��С������%d����󹥻���%d)", loginPlayer->martial.name,
            loginPlayer->weapon.name, loginPlayer->weapon.minAttack, loginPlayer->weapon.maxAttack);
    SetPosition(MARGIN_X+7, info_start_row++);
    printf("���ߣ�%s(��С������%d����������%d)", loginPlayer->armor.name, loginPlayer->armor.minDefence, loginPlayer->armor.maxDefence);
    SetPosition(MARGIN_X+7, info_start_row++);
    printf("-------------------------------����-------------------------------");
    SetPosition(MARGIN_X+7, info_start_row++);
    if(loginPlayer->bag.count <= 0) {
        printf("��ǰ�����տ���Ҳ�����⽭�����ܺ���׼��");
    } else {
        int count = 0;
        for(int i = 0; i < loginPlayer->bag.count; i ++) {
            if(count >= loginPlayer->bag.count) {
                break;
            }
            Prop prop = loginPlayer->bag.props[i];
            if(i%4 == 0) {
                SetPosition(MARGIN_X+7, info_start_row++);
            }
            printf("%d��%s(%d)\t", i+1, prop.name, prop.stock);
            count += prop.stock;
        }
    }
}

void WatchAround(int x, int y) {
    int len = 5;
    int targetIdx = 0;  //������Ŀ�����
    Monster* monsterArr = calloc(len, sizeof(Monster));
    int size = sizeof(monsters)/sizeof(Monster);
    int idx = 0;
    for(int i = 0; i < size; i ++) {
        Monster monster = monsters[i];
        if(monster.coord.X == x && monster.coord.Y == y) {
            if(idx >= len) {
                len = len + 5;
                Monster* temp = realloc(monsterArr, len);
                if(!temp) {
                    monsterArr = temp;
                }
            }

            Monster* newMonster = (Monster*)CreateMonster(&monster);
            if(!newMonster) {
                continue;
            }
            *(monsterArr + idx) = *(newMonster);
            idx ++;
        }
    }
    int info_start_row = init_info_start_row;
    int row = info_start_row;
    info_start_row = RefreshMonster(monsterArr, &idx, row);
    while(1) {
        if(info_start_row < 0) {
            break;
        }
        if(targetIdx == -1) {
            info_start_row = RefreshMonster(monsterArr, &idx, row);
            if(info_start_row < 0) {
                break;
            }
        }
        SetPosition(MARGIN_X+7, info_start_row);
        printf(CLEAR_SPACE);
        SetPosition(MARGIN_X+7, info_start_row);
        fflush(stdin);
        printf("��ѡ�񹥻���Ŀ���0����:");
        scanf("%d", &targetIdx);
        fflush(stdin);
        SetPosition(MARGIN_X+7, info_start_row);
        if(targetIdx == 0) {
            RefreshInfo();
            break;
        }
        Monster* target = monsterArr + --targetIdx;
        Fight(loginPlayer, target, info_start_row);
        targetIdx = -1;
    }
    for(int i = 0; i < idx; i ++) {
        free(monsterArr+i);
    }
    monsterArr = NULL;
}

Monster* CreateMonster(const Monster* monster) {
    Monster* pMonster = (Monster*)malloc(sizeof(Monster));
    if(pMonster == NULL) {
        return NULL;
    }
    strcpy(pMonster->name, monster->name);
    pMonster->coord = monster->coord;
    strcpy(pMonster->desc, monster->desc);
    pMonster->hp = monster->hp;
    pMonster->id = monster->id;
    pMonster->level = monster->level;
    pMonster->maxAttack = monster->maxAttack;
    pMonster->maxExp = monster->maxExp;
    pMonster->maxMoney = monster->maxMoney;
    pMonster->minAttack = monster->minAttack;
    pMonster->minExp = monster->minExp;
    pMonster->minMoney = monster->minMoney;
    pMonster->state = monster->state;
    return pMonster;
}

int RefreshMonster(Monster* monsterArr, int* monsterCount, int info_start_row) {
    RefreshInfo();
    SetPosition(MARGIN_X+35, info_start_row++);
    printf("�������˿�����");
    SetPosition(MARGIN_X+7, info_start_row++);
    if(*monsterCount <= 0) {
        printf("����һ���������ĵط��������ֶ�û��");
        return -1;
    }
    Monster* monster = NULL;
    int count = 0;
    int j = 0;
    for(int i = 0; i < *monsterCount; i ++) {
        monster = monsterArr+i;
        if(monster->state == 1) {
            j = i;
            while(j < *monsterCount) {
                free(monster);
                *(monsterArr + j) = *(monsterArr + ++j);
            }
            continue;
        }
        count ++;
    }
    *monsterCount = count;
    monster = NULL;
    for(int i = 0; i < count; i ++) {
        monster = monsterArr + i;
        if(i != 0 && i % 4 == 0) {
            SetPosition(MARGIN_X+7, info_start_row++);
        }
        printf("%d��%s(%d��)\t", i + 1, monster->name, monster->level);
    }
    return info_start_row;
}

void Fight(Player* player, Monster* monster, int row) {
    time_t seed;
    int isFinished = 1;
    char confirm = 'N';
    int fightCount = 0;
    while(player->hp > 0 && monster->hp > 0) {
        SetPosition(MARGIN_X+7, row);
        printf(CLEAR_SPACE);
        SetPosition(MARGIN_X+7, row);
        if(player->mp <= 0 && toupper(confirm) == 'N') {
            printf("��������ֵ�����ˣ��������ɣ�(��0����ս��)");
            scanf("%d", &isFinished);
            fflush(stdin);
            if(isFinished == 0) {
                break;
            } else {
                SetPosition(MARGIN_X+7, row);
                printf(CLEAR_SPACE);
                SetPosition(MARGIN_X+7, row);
                printf("��ȷ������ս����(y/n)");
                fflush(stdin);
                scanf("%c", &confirm);
                fflush(stdin);
                if(toupper(confirm) == 'N') {
                    break;
                } else {
                    SetPosition(MARGIN_X+7, row);
                }
            }
        }
        srand(time(&seed));
        int monsterAttack = rand() % (monster->maxAttack-monster->minAttack+1) + monster->minAttack;
        int playerAttack = 0;
        if(player->mp > 0) {
            playerAttack = rand() %(player->maxAttack-player->minAttack+1)+player->minAttack;
        }
        player->hp -= monsterAttack;
        player->mp -= 5;
        monster->hp -= playerAttack;
        if(player->hp <= 0) {
            printf("�������ˣ���������һ���ú�(�س�����)");
            getch();
            fflush(stdin);
            SetPosition(MARGIN_X+7, row);
            printf(CLEAR_SPACE);
            break;
        }
        if(monster->hp <= 0) {
            int exp = rand()%(monster->maxExp-monster->minExp+1) + monster->minExp;
            int money = rand() %(monster->maxMoney-monster->minMoney+1) + monster->minMoney;
            printf("���������֣�����Ӯ��ʤ������þ���%d����Ǯ%d(�س�����)", exp, money);
            player->exp += exp;
            player->money += money;
            monster->state=1;
            getch();
            fflush(stdin);
            SetPosition(MARGIN_X+7, row);
            printf(CLEAR_SPACE);
            break;
        }
        fightCount ++;
        printf("��%d��ս��������������:%d��ʣ��HP:%d��ʣ��MP:%d��%s������:%d��ʣ��HP:%d", fightCount, playerAttack, player->hp,
               player->mp, monster->name, monsterAttack, monster->hp);
        Sleep(500);
    }
}

int RefreshProps(int offset) {

    RefreshInfo();
    int infoStartRow = init_info_start_row;
    SetPosition(MARGIN_X+45, infoStartRow++);
    printf("�߹�·������Ҫ���");
    Prop prop;
    int size = sizeof(props) / sizeof(Prop);
    for(int i = 0; i < size; i ++) {
        prop = props[i];
        if(i % 4 == 0) {
            SetPosition(offset, infoStartRow++);
        }
        printf("%d��%s(%d�������:%d)\t", i + 1, prop.name, prop.level, prop.stock);
    }
    return infoStartRow;
}

/* չʾ�̵����Ʒ */
void ShowStoreProps() {
    int offset = MARGIN_X+7;
    int size = sizeof(props) / sizeof(Prop);
    int infoStartRow = RefreshProps(offset);
    int targetId = 0;
    while(1) {
        SetPosition(offset, infoStartRow);
        printf(CLEAR_SPACE);
        SetPosition(offset, infoStartRow);
        printf("��ѡ����Ʒ���(0�˳�):");
        scanf("%d", &targetId);
        if(targetId == 0) {
            RefreshInfo();
            break;
        } else {
            targetId--;
            if(targetId < 0 || targetId >= size) {
                SetPosition(offset, infoStartRow);
                printf(CLEAR_SPACE);
                SetPosition(offset, infoStartRow);
                printf("������Ч");
                getch();
                fflush(stdin);
                continue;
            }
            Prop* pProp = &props[targetId];
            StoreTrade(loginPlayer, pProp, offset, infoStartRow);
            infoStartRow = RefreshProps(offset);
        }
    }
}

/* ������� */
void StoreTrade(Player* player, Prop* prop, int offset, int row) {
    if(prop->stock <= 0) {
        SetPosition(offset, row);
        printf(CLEAR_SPACE);
        SetPosition(offset, row);
        printf("��Ʒ��治��");
        getch();
        fflush(stdin);
        return;
    }
    if(player->bag.count >= player->bag.max) {
        SetPosition(offset, row);
        printf(CLEAR_SPACE);
        SetPosition(offset, row);
        printf("���ı����ռ䲻��");
        getch();
        fflush(stdin);
        return;
    }
    if(player->money < prop->price) {
        SetPosition(offset, row);
        printf(CLEAR_SPACE);
        SetPosition(offset, row);
        printf("���Ľ�Ǯ����");
        getch();
        fflush(stdin);
        return;
    }
    Prop* bought;
    int i = 0;
    for(; i < player->bag.count; i ++) {
        bought = &player->bag.props[i];
        if(bought->id == prop->id) {
            bought->stock++;
            break;
        }
    }
    if(i == player->bag.count) {
        Prop* newProp = &player->bag.props[i];
        newProp->id = prop->id;
        strcpy(newProp->desc, prop->desc);
        newProp->level = prop->level;
        newProp->maxAttack = prop->maxAttack;
        newProp->maxDefence = prop->maxDefence;
        newProp->minAttack = prop->minAttack;
        newProp->minDefence = prop->minDefence;
        strcpy(newProp->name, prop->name);
        newProp->price = prop->price;
        newProp->propType = prop->propType;
        newProp->stock = 1;
    }
    player->bag.count ++;
    player->money -= prop->price;
    prop->stock --;
}

