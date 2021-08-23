#pragma once
#include <iostream>

using namespace std;

class Entity // ��� ����ü
{
	string nEntityName;
	int nEntityCode;

	int nLV;
	int nM_HP;
	int nC_HP;
	int nM_MP;
	int nC_MP;

	int nMaxDamage; // �� �� ������
	int nMinDamage; // �� �� ������
	int nDefensivePower; // �� �� ����
	int nSpeed; // �� �� �̵��ӵ�

public:
	// ������
	Entity(string name, int lv, int hp, int mp, int sp, int dp, int speed);
	// ��ü����
	virtual void EntityStatus();
	// ��ü LV ����
	void ChangeEntityStatus_LV(int lv);
	// ��ü nM_HP, nM_MP ���º���, add
	void ChangeEntityStatus_MHPMMP(int mhp = 0, int mmp = 0);
	// ��ü nC_HP, nC_MP ���º���, add
	void ChangeEntityStatus_CHPCMP(int chp = 0, int cmp = 0);
	// ��ü nMaxDamage, nMinDamage ���º���, add
	void ChangeEntityStatus_Damage(int maxd, int mind);
	// ��ü nDefensivePower ���º���, add
	void ChangeEntityStatus_DefensivePower(int dp);
	// ��ü nSpeed ���º���, add
	void ChangeEntityStatus_Speed(int speed);

	//Get(), Set()
	string GetName() { return nEntityName; }
	void SetName(string name) { this->nEntityName = name; }
	int GetEntityCode() { return nEntityCode; }
	void SetEntityCode(int codenumber) { this->nEntityCode = codenumber; }
	int GetLV() { return nLV; }
	void SetLV(int lv) { this->nLV = lv; }
	int GetM_HP() { return nM_HP; }
	void SetM_HP(int hp) { this->nM_HP = hp; }
	int GetC_HP() { return nC_HP; }
	void SetC_HP(int hp) { this->nC_HP = hp; }
	int GetM_MP() { return nM_MP; }
	void SetM_MP(int mp) { this->nM_MP = mp; }
	int GetC_MP() { return nC_MP; }
	void SetC_MP(int mp) { this->nC_MP = mp; }
	int GetMaxDamage() { return nMaxDamage; }
	void SetMaxDamage(int damage) { this->nMaxDamage = damage; }
	int GetMinDamage() { return nMinDamage; }
	void SetMinDamage(int damage) { this->nMinDamage = damage; }
	int GetDefensivePower() { return nDefensivePower; }
	void SetDefensivePower(int defensivepower) { this->nDefensivePower = defensivepower; }
	int GetSpeed() { return nSpeed; }
	void SetSpeed(int speed) { this->nSpeed = speed; }
};