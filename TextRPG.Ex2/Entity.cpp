#include <iostream>
#include <vector>
#include "Entity.h"

using namespace std;

// ������
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
// ��ü����
void Entity::EntityStatus()
{
	cout << "[�̸�: " << nEntityName << ", LV: " << nLV << ", C_HP/M_HP: " << nC_HP << "/" << nM_HP << ", C_MP/M_MP: " << nC_MP << "/" << nM_MP << "]" << endl;
}
// ��ü LV ����
void Entity::ChangeEntityStatus_LV(int lv)
{
	if (nLV + lv > 0) this->nLV += lv;
	this->nM_HP += 1;
	this->nC_HP = nM_HP;
	this->nM_MP += 1;
	this->nC_MP = nM_MP;
}
// ��ü nM_HP, nM_MP ���º���
void Entity::ChangeEntityStatus_MHPMMP(int mhp, int mmp)
{
	if (nM_HP + mhp >= 0) this->nM_HP += mhp;
	else this->nM_HP = 0;
	if (nM_MP + mmp >= 0) this->nM_MP += mmp;
	else this->nM_MP = 0;
}
// ��ü nC_HP, nC_MP ���º���
void Entity::ChangeEntityStatus_CHPCMP(int chp, int cmp)
{
	if (nC_HP + chp >= 0) this->nC_HP += chp;
	else this->nC_HP = 0;
	if (nC_MP + cmp >= 0) this->nC_MP += cmp;
	else this->nC_MP = 0;
}
// ��ü nMaxDamage, nMinDamage ���� ����
void Entity::ChangeEntityStatus_Damage(int maxd, int mind)
{
	if (nMaxDamage + maxd >= 0) this->nMaxDamage += maxd;
	else this->nMaxDamage = 0;
	if (nMinDamage + mind >= 0) this->nMinDamage += mind;
	else this->nMinDamage = 0;
}
// ��ü nDefensivePower ���º���
void Entity::ChangeEntityStatus_DefensivePower(int dp)
{
	if (nDefensivePower + dp >= 0) this->nDefensivePower += dp;
	else this->nDefensivePower = 0;
}
// ��ü nSpeed ���º���
void Entity::ChangeEntityStatus_Speed(int speed)
{
	if (nSpeed + speed >= 0) this->nSpeed += speed;
	else this->nSpeed = 0;
}