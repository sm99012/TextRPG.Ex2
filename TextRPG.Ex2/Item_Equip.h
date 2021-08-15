#pragma once
#include "Item.h"

enum E_AttackSpeed { �ſ���� = -2, ���� = -1, ���� = 0, ���� = 1, �ſ���� = 2 };
enum E_EquipCode {���� = 10000, �������� = 11000, ���� = 12000, ���� = 13000, ���� = 14000, �尩 = 15000, �Ź� = 16000, ���Ʈ = 17000, ���� = 18000, ���� = 19000};

class Item_Equip : public Item
{
	int nEquipCode;
	int nMIN_AP;
	int nMAX_AP;
	int nDP;
	int nAttackSpeed;
	int nM_Durability;
	int nC_Durability;

public:
	// ������
	Item_Equip (string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, int attackspeed, int durability);
	// ����������
	void ItemStatus();
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
	int GetAttackSpeed() { return nAttackSpeed; }
	void SetAttackSpeed(E_AttackSpeed attackspeed) { this->nAttackSpeed = attackspeed; }
	int GetM_Durability() { return nM_Durability; }
	void SetM_Durability(int durability) { this->nM_Durability = durability; }
	int GetC_Durability() { return nC_Durability; }
	void SetC_Durability(int durability) { this->nC_Durability = durability; }
};