#include <iostream>
#include "Item.h"
#include "Item_Equip.h"

using namespace std;

// 생성자
Item_Equip::Item_Equip(string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, E_AttackSpeed attackspeed, int durability) : Item(itemname, 장비아이템, itemcode, lvlimit, itemgrade)
{
	this->nEquipCode = equipcode;
	this->nMIN_AP = min_ap;
	this->nMAX_AP = max_ap;
	this->nDP = dp;
	this->nAttackSpeed = attackspeed;
	this->nM_Durability = durability;
	this->nC_Durability = durability;
}
Item_Equip::Item_Equip(string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, E_AttackSpeed attackspeed, int durability, int hp, int mp, int critical) : Item(itemname, 장비아이템, itemcode, lvlimit, itemgrade)
{
	this->nEquipCode = equipcode;
	this->nMIN_AP = min_ap;
	this->nMAX_AP = max_ap;
	this->nDP = dp;
	this->nAttackSpeed = attackspeed;
	this->nM_Durability = durability;
	this->nC_Durability = durability;
	this->nHP = hp;
	this->nMP = mp;
	this->nCRITICAL = critical;
}
// 아이템정보
void Item_Equip::ItemStatus()
{
	if (GetItemGrade() == 노멀)
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 노멀] " << endl;
	}
	else if (GetItemGrade() == 레어)
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 레어] " << endl;
	}
	else if (GetItemGrade() == 에픽)
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 에픽] " << endl;
	}
	else if (GetItemGrade() == 유니크)
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 유니크] " << endl;
	}
}
// 세부 아이템정보1
void Item_Equip::ItemInformation1()
{
	cout << "[아이템정보]-------------------------------------------------------------------" << endl;
	cout << "[" << GetItemName() << "]";
	switch (GetItemGrade())
	{
	case 노멀:
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 노멀]" << endl;
	} break;
	case 레어:
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 레어] " << endl;
	} break;
	case 에픽:
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 에픽] " << endl;
	} break;
	case 유니크:
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 유니크] " << endl;
	} break;
	}
	cout << "[공격력: " << GetMin_AP() << " ~ " << GetMax_AP() << "]";
	if (nEquipCode == 무기)
	{
		switch (nAttackSpeed)
		{
		case 매우느림:
		{
			cout << "[공격속도: 매우느림]" << endl;
		} break;
		case 느림:
		{
			cout << "[공격속도: 느림]" << endl;
		} break;
		case 보통:
		{
			cout << "[공격속도: 보통]" << endl;
		} break;
		case 빠름:
		{
			cout << "[공격속도: 빠름]" << endl;
		} break;
		case 매우빠름:
		{
			cout << "[공격속도: 매우빠름]" << endl;
		} break;
		}
	}
	else { cout << endl; }
	cout << "[방어력: " << GetDP() << "]" << endl;
	cout << "[크리티컬: " << GetCRITICAL() << "]" << endl;
	cout << "[HP: " << GetHP() << "][MP: " << GetMP() << "]" << endl;
	cout << "[아이템 설명]------------------------------------------------------------------" << endl;
	cout << GetItemDescription() << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}
// 세부 아이템정보2
void Item_Equip::ItemInformation2()
{
	cout << "[아이템정보]-------------------------------------------------------------------" << endl;
	cout << "[" << GetItemName() << "]";
	switch (GetItemGrade())
	{
	case 노멀:
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 노멀]" << endl;
	} break;
	case 레어:
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 레어] " << endl;
	} break;
	case 에픽:
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 에픽] " << endl;
	} break;
	case 유니크:
	{
		cout << "[LV: " << GetItemLVLimit() << "][등급: 유니크] " << endl;
	} break;
	}
	cout << "[추가능력치]--" << endl;
	if (GetMin_AP() != 0 || GetMax_AP() != 0)
	{
		cout << "[공격력: " << GetMin_AP() << " ~ " << GetMax_AP() << "]" << endl;
	}
	if (nEquipCode == 무기)
	{
		switch (nAttackSpeed)
		{
		case 매우느림:
		{
			cout << "[공격속도: 매우느림]" << endl;
		} break;
		case 느림:
		{
			cout << "[공격속도: 느림]" << endl;
		} break;
		case 보통:
		{
			cout << "[공격속도: 보통]" << endl;
		} break;
		case 빠름:
		{
			cout << "[공격속도: 빠름]" << endl;
		} break;
		case 매우빠름:
		{
			cout << "[공격속도: 매우빠름]" << endl;
		} break;
		}
	}
	if (GetDP() != 0 || GetCRITICAL() != 0 || GetHP() != 0 || GetMP() != 0)
	{
		if (GetDP() != 0)
		{
			cout << "[방어력: " << GetDP() << "]" << endl;
		}
		if (GetCRITICAL() != 0)
		{
			cout << "[크리티컬: " << GetCRITICAL() << "]" << endl;
		}
		if (GetHP() != 0)
		{
			cout << "[HP: " << GetHP() << "]" << endl;
		}
		if (GetMP() != 0)
		{
			cout << "[MP: " << GetMP() << "] " << endl;
		}
	}
	cout << "[아이템 설명]--" << endl;
	cout << GetItemDescription() << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}
// 아이템 내구도 감소
void Item_Equip::ChangeItemDurability(int use)
{
	if (nC_Durability + use >= 0) this->nC_Durability += use;
	else this->nC_Durability = 0;
}