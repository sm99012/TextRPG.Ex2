#include <iostream>
#include <vector>
#include "Entity.h"
#include "Entity_Monster.h"

// ������
Monster::Monster(string name, int lv, int hp, int mp, int sp, int dp, int speed, int exp, int gold = 0) : Entity(name, lv, hp, mp, sp, dp, speed)
{
	this->nEXP = exp;
	this->nDropGold = gold;
	EntityStatus();
}
// ��ü����
void Monster::EntityStatus()
{
	cout << "[�̸�: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", EXP: " << nEXP << "]" << endl;
	DropItemList();
	cout << endl;
}
// ��ü����
void Monster::MonsterBattleStatus()
{
	cout << "[�̸�: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << "]" << endl;
	cout << endl;
}
// ��� ������
void Monster::DropItemList()
{

}