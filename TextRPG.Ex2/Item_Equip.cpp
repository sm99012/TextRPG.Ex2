#include <iostream>
#include "Item.h"
#include "Item_Equip.h"

using namespace std;

// 생성자
Item_Equip::Item_Equip(string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, int attackspeed, int durability) : Item(itemname, 장비아이템, itemcode, lvlimit, itemgrade)
{
	this->nEquipCode = equipcode;
	this->nMIN_AP = min_ap;
	this->nMAX_AP = max_ap;
	this->nDP = dp;
	this->nAttackSpeed = attackspeed;
	this->nM_Durability = durability;
	this->nC_Durability = durability;
}
// 아이템정보
void Item_Equip::ItemStatus()
{
	cout << "장비아이템[무기]: [" << GetItemName() << "]" << endl;
	if (GetItemGrade() == 노멀)
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 노멀]" << endl;
	}
	else if (GetItemGrade() == 레어)
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 레어]" << endl;
	}
	else if (GetItemGrade() == 에픽)
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 에픽]" << endl;
	}
	else if (GetItemGrade() == 유니크)
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 유니크]" << endl;
	}
	if (nAttackSpeed == 매우느림)
	{
		cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 매우느림][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	else if (nAttackSpeed == 느림)
	{
		cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 느림][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	else if (nAttackSpeed == 보통)
	{
		cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 보통][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	else if (nAttackSpeed == 빠름)
	{
		cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 빠름][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	else if (nAttackSpeed == 매우빠름)
	{
		cout << "[공격력: " << nMIN_AP << " ~ " << nMAX_AP << "][방어력: " << nDP << "][공격속도: 매우빠름][내구도 : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	cout << "[" << GetItemDescription() << "]" << endl;
}