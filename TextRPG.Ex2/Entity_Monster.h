#pragma once
#include <iostream>
#include <queue>
#include "Entity.h"
#include "Skill.h"

using namespace std;

class Monster : public Entity
{
	int nEXP;
	int nDropGold;
	//queue <Item> nDropItemList;
	Skill* nSkill;

public:
	// ������
	Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold);
	// ��ü����
	void EntityStatus();
	// ������ ���� ����
	void MonsterBattleStatus();

	//void AddDropItem(Item dropitem)
	//{
	//	nDropItem.push_back(dropitem);
	//}
	// ��� ������
	void DropItemList();

	int GetEXP() { return nEXP; }
	void SetEXP(int exp) { this->nEXP = exp; }
	int GetDropGold() { return nDropGold; }
	void SetDropGold(int dropgold) { this->nDropGold = dropgold; }
};