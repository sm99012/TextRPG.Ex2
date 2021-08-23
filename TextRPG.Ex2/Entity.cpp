#include <iostream>
#include <vector>
#include "Entity.h"

using namespace std;

// 생성자
Entity::Entity(string name, int lv, int hp, int mp, int sp, int dp, int speed)
{
	this->nEntityName = name;
	this->nLV = lv;
	this->nM_HP = hp;
	this->nC_HP = hp;
	this->nM_MP = mp;
	this->nC_MP = mp;
	this->nMaxDamage = sp;
	this->nMinDamage = sp;
	this->nDefensivePower = dp;
	this->nSpeed = speed;
}
// 개체상태
void Entity::EntityStatus()
{
	cout << "[이름: " << nEntityName << ", LV: " << nLV << ", C_HP/M_HP: " << nC_HP << "/" << nM_HP << ", C_MP/M_MP: " << nC_MP << "/" << nM_MP << "]" << endl;
}
// 개체 LV 변경
void Entity::ChangeEntityStatus_LV(int lv)
{
	if (nLV + lv > 0) this->nLV += lv;
	this->nM_HP += 1;
	this->nC_HP = nM_HP;
	this->nM_MP += 1;
	this->nC_MP = nM_MP;
}
// 개체 nM_HP, nM_MP 상태변경
void Entity::ChangeEntityStatus_MHPMMP(int mhp, int mmp)
{
	if (nM_HP + mhp >= 0) this->nM_HP += mhp;
	else this->nM_HP = 0;
	if (nM_MP + mmp >= 0) this->nM_MP += mmp;
	else this->nM_MP = 0;
}
// 개체 nC_HP, nC_MP 상태변경
void Entity::ChangeEntityStatus_CHPCMP(int chp, int cmp)
{
	if (nC_HP + chp >= 0) this->nC_HP += chp;
	else this->nC_HP = 0;
	if (nC_MP + cmp >= 0) this->nC_MP += cmp;
	else this->nC_MP = 0;
}
// 개체 nMaxDamage, nMinDamage 상태 변경
void Entity::ChangeEntityStatus_Damage(int maxd, int mind)
{
	if (nMaxDamage + maxd >= 0) this->nMaxDamage += maxd;
	else this->nMaxDamage = 0;
	if (nMinDamage + mind >= 0) this->nMinDamage += mind;
	else this->nMinDamage = 0;
}
// 개체 nDefensivePower 상태변경
void Entity::ChangeEntityStatus_DefensivePower(int dp)
{
	if (nDefensivePower + dp >= 0) this->nDefensivePower += dp;
	else this->nDefensivePower = 0;
}
// 개체 nSpeed 상태변경
void Entity::ChangeEntityStatus_Speed(int speed)
{
	if (nSpeed + speed >= 0) this->nSpeed += speed;
	else this->nSpeed = 0;
}