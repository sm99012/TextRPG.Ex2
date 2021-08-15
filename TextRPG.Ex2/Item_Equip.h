#pragma once
#include "Item.h"

enum E_AttackSpeed { 매우느림 = -2, 느림 = -1, 보통 = 0, 빠름 = 1, 매우빠름 = 2 };
enum E_EquipCode {무기 = 10000, 보조무기 = 11000, 모자 = 12000, 상의 = 13000, 하의 = 14000, 장갑 = 15000, 신발 = 16000, 펜던트 = 17000, 반지 = 18000, 훈장 = 19000};

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
	// 생성자
	Item_Equip (string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, int attackspeed, int durability);
	// 아이템정보
	void ItemStatus();
	// 아이템 내구도 수치 변경
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