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
	// 생성자
	Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold);
	// 개체정보
	void EntityStatus();
	// 전투시 몬스터 정보
	void MonsterBattleStatus();

	//void AddDropItem(Item dropitem)
	//{
	//	nDropItem.push_back(dropitem);
	//}
	// 드랍 아이템
	void DropItemList();

	int GetEXP() { return nEXP; }
	void SetEXP(int exp) { this->nEXP = exp; }
	int GetDropGold() { return nDropGold; }
	void SetDropGold(int dropgold) { this->nDropGold = dropgold; }
};