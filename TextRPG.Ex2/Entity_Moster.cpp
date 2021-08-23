#include <iostream>
#include <queue>
#include <conio.h>
#include <ctime>
#include "Entity.h"
#include "Entity_Monster.h"
#include "Entity_Player.h"
#include "Item.h"

// 생성자
Monster::Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold = 0) : Entity(name, lv, hp, mp, sp, dp, speed)
{
	this->nEXP = exp;
	this->nDropGold = gold;
	//EntityStatus();
}
// 개체상태
void Monster::EntityStatus()
{
	cout << "[이름: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", EXP: " << nEXP << "]" << endl;
}
// 개체정보
void Monster::MonsterBattleStatus()
{
	cout << "[이름: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << "]" << endl;
	cout << endl;
}
// 몬스터의 아이템 드랍시스템
void Monster::MonsterDropSystem(Player* player) // 객체지향에 위반하는 사항? -> GameManager 를 써야할까???
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
			cout << "[" << player->GetName() << "] [장비: + " << Queue.front()->GetItemName() << "]" << endl;
		}
		Queue.pop();
		Rate.pop();
	}
}
// 몬스터가 드랍하는 아이템 목록설정(아이템, 드랍률)
void Monster::SetDropItem(Item* item, int rate)
{
	Queue_nDropItemList.push(item);
	Queue_nDropItem_Rate.push(rate);
}
// 드랍 아이템 목록
void Monster::DisplayDropItem()
{
	queue <Item*> Queue = Queue_nDropItemList;
	queue <int> Rate = Queue_nDropItem_Rate;
	int Count = 1;
	while (!Queue.empty())
	{
		cout << Count << ": " << Queue.front()->GetItemName() << ", 드랍%: " << Rate.front() << endl;
		Queue.pop();
		Rate.pop();
		Count++;
	}
}