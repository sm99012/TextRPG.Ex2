#include <iostream>
#include <vector>
#include "Entity.h"
#include "Entity_Monster.h"

// 생성자
Monster::Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold = 0) : Entity(name, lv, hp, mp, sp, dp, speed)
{
	this->nEXP = exp;
	this->nDropGold = gold;
	EntityStatus();
}
// 개체상태
void Monster::EntityStatus()
{
	cout << "[이름: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", EXP: " << nEXP << "]" << endl;
	DropItemList();
	cout << endl;
}
// 개체정보
void Monster::MonsterBattleStatus()
{
	cout << "[이름: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << "]" << endl;
	cout << endl;
}
// 드랍 아이템
void Monster::DropItemList()
{

}