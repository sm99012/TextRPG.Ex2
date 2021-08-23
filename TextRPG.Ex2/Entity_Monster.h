#pragma once
#include <iostream>
#include <queue>
#include "Entity.h"
#include "Entity_Player.h" // 객체지향의 위반?
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
	// 생성자
	Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold);
	// 개체정보
	void EntityStatus();
	// 전투시 몬스터 정보
	void MonsterBattleStatus();
	// 몬스터의 아이템 드랍시스템
	void MonsterDropSystem(Player* player);
	// 몬스터가 드랍하는 아이템 목록설정(아이템, 드랍률)
	void SetDropItem(Item* item, int rate);
	// 드랍 아이템 목록
	void DisplayDropItem();

	int GetEXP() { return nEXP; }
	void SetEXP(int exp) { this->nEXP = exp; }
	int GetDropGold() { return nDropGold; }
	void SetDropGold(int dropgold) { this->nDropGold = dropgold; }
};