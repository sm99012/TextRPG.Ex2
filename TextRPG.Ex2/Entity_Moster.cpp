#include <iostream>
#include <queue>
#include <conio.h>
#include <ctime>
#include "Entity.h"
#include "Entity_Monster.h"
#include "Entity_Player.h"
#include "Item.h"

// ������
Monster::Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold = 0) : Entity(name, lv, hp, mp, sp, dp, speed)
{
	this->nEXP = exp;
	this->nDropGold = gold;
	//EntityStatus();
}
// ��ü����
void Monster::EntityStatus()
{
	cout << "[�̸�: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", EXP: " << nEXP << "]" << endl;
}
// ��ü����
void Monster::MonsterBattleStatus()
{
	cout << "[�̸�: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << "]" << endl;
	cout << endl;
}
// ������ ������ ����ý���
void Monster::MonsterDropSystem(Player* player) // ��ü���⿡ �����ϴ� ����? -> GameManager �� ����ұ�???
{
	player->nHaveGold += this->nDropGold;
	srand(time(0));
	queue <Item*> Queue = Queue_nDropItemList;
	queue <int> Rate = Queue_nDropItem_Rate;
	while (!Queue.empty())
	{
		int nRandom = rand() % 101;
		int nDropRate = Rate.front();
		Item* nDropItem = Queue.front();
		if (nDropRate >= nRandom)
		{
			player->PlayerDrop(nDropItem);
			cout << "[" << player->GetName() << "] [���: + " << Queue.front()->GetItemName() << "]" << endl;
		}
		Queue.pop();
		Rate.pop();
	}
}
// ���Ͱ� ����ϴ� ������ ��ϼ���(������, �����)
void Monster::SetDropItem(Item* item, int rate)
{
	Queue_nDropItemList.push(item);
	Queue_nDropItem_Rate.push(rate);
}
// ��� ������ ���
void Monster::DisplayDropItem()
{
	queue <Item*> Queue = Queue_nDropItemList;
	queue <int> Rate = Queue_nDropItem_Rate;
	int Count = 1;
	while (!Queue.empty())
	{
		cout << Count << ": " << Queue.front()->GetItemName() << ", ���%: " << Rate.front() << endl;
		Queue.pop();
		Rate.pop();
		Count++;
	}
}