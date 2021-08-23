#pragma once
#include <iostream>
#include <queue>
#include "Entity.h"
#include "Entity_Player.h" // ��ü������ ����?
#include "Skill.h"
#include "Item.h"

using namespace std;

class Monster : public Entity
{
	int nEXP;
	int nDropGold;
	queue <Item*> Queue_nDropItemList;
	queue <int> Queue_nDropItem_Rate;
	Skill* nSkill;

public:
	// ������
	Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold);
	// ��ü����
	void EntityStatus();
	// ������ ���� ����
	void MonsterBattleStatus();
	// ������ ������ ����ý���
	void MonsterDropSystem(Player* player);
	// ���Ͱ� ����ϴ� ������ ��ϼ���(������, �����)
	void SetDropItem(Item* item, int rate);
	// ��� ������ ���
	void DisplayDropItem();

	int GetEXP() { return nEXP; }
	void SetEXP(int exp) { this->nEXP = exp; }
	int GetDropGold() { return nDropGold; }
	void SetDropGold(int dropgold) { this->nDropGold = dropgold; }
};