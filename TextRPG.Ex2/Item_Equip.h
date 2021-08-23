#pragma once
#include "Item.h"

enum E_AttackSpeed { null = -3, �ſ���� = -2, ���� = -1, ���� = 0, ���� = 1, �ſ���� = 2 };
enum E_EquipCode { ���� = 10000, �������� = 11000, ���� = 12000, ���� = 13000, ���� = 14000, �尩 = 15000, �Ź� = 16000, ���Ʈ = 17000, ���� = 18000, ���� = 19000 };


class Item_Equip : public Item
{
	int nEquipCode; // �������� �Һз�
	int nMIN_AP = 0;
	int nMAX_AP = 0;
	int nDP = 0;
	int nHP = 0;
	int nMP = 0;
	int nCRITICAL = 0;
	E_AttackSpeed nAttackSpeed = null;
	int nM_Durability = 0;
	int nC_Durability = 0;

public:
	// ������
	Item_Equip (string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, E_AttackSpeed attackspeed, int durability);
	// ������
	Item_Equip(string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, E_AttackSpeed attackspeed, int durability, int hp, int mp, int critical);
	// ����������
	void ItemStatus();
	// ���� ����������1
	void ItemInformation1();
	// ���� ����������2
	void ItemInformation2();
	// ������ ������ ��ġ ����
	void ChangeItemDurability(int use);

	// Get(), Set()
	int GetEquipCode() { return nEquipCode; }
	void SetEquipCode(E_EquipCode equipcode) { this->nEquipCode = equipcode; }
	int GetMin_AP() { return nMIN_AP; }
	void SetMin_AP(int minap) { this->nMIN_AP = minap; }
	int GetMax_AP() { return nMAX_AP; }
	void SetMax_AP(int maxap) { this->nMAX_AP = maxap; }
	int GetDP() { return nDP; }
	void SetDP(int dp) { this->nDP = dp; }
	int GetHP() { return nHP; }
	void SetHP(int hp) { this->nHP = hp; }
	int GetMP() { return nMP; }
	void SetMP(int mp) { this->nMP = mp; }
	int GetCRITICAL() { return nCRITICAL; }
	void SetCRITICAL(int critical) { this->nCRITICAL = critical; }

	int GetAttackSpeed() { return nAttackSpeed; }
	void SetAttackSpeed(E_AttackSpeed attackspeed) { this->nAttackSpeed = attackspeed; }
	int GetM_Durability() { return nM_Durability; }
	void SetM_Durability(int durability) { this->nM_Durability = durability; }
	int GetC_Durability() { return nC_Durability; }
	void SetC_Durability(int durability) { this->nC_Durability = durability; }
};