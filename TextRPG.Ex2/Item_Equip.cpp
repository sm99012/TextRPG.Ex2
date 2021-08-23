#include <iostream>
#include "Item.h"
#include "Item_Equip.h"

using namespace std;

// ������
Item_Equip::Item_Equip(string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, E_AttackSpeed attackspeed, int durability) : Item(itemname, ��������, itemcode, lvlimit, itemgrade)
{
	this->nEquipCode = equipcode;
	this->nMIN_AP = min_ap;
	this->nMAX_AP = max_ap;
	this->nDP = dp;
	this->nAttackSpeed = attackspeed;
	this->nM_Durability = durability;
	this->nC_Durability = durability;
}
Item_Equip::Item_Equip(string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, E_AttackSpeed attackspeed, int durability, int hp, int mp, int critical) : Item(itemname, ��������, itemcode, lvlimit, itemgrade)
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
// ����������
void Item_Equip::ItemStatus()
{
	if (GetItemGrade() == ���)
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ���] " << endl;
	}
	else if (GetItemGrade() == ����)
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����] " << endl;
	}
	else if (GetItemGrade() == ����)
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����] " << endl;
	}
	else if (GetItemGrade() == ����ũ)
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����ũ] " << endl;
	}
}
// ���� ����������1
void Item_Equip::ItemInformation1()
{
	cout << "[����������]-------------------------------------------------------------------" << endl;
	cout << "[" << GetItemName() << "]";
	switch (GetItemGrade())
	{
	case ���:
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ���]" << endl;
	} break;
	case ����:
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����] " << endl;
	} break;
	case ����:
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����] " << endl;
	} break;
	case ����ũ:
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����ũ] " << endl;
	} break;
	}
	cout << "[���ݷ�: " << GetMin_AP() << " ~ " << GetMax_AP() << "]";
	if (nEquipCode == ����)
	{
		switch (nAttackSpeed)
		{
		case �ſ����:
		{
			cout << "[���ݼӵ�: �ſ����]" << endl;
		} break;
		case ����:
		{
			cout << "[���ݼӵ�: ����]" << endl;
		} break;
		case ����:
		{
			cout << "[���ݼӵ�: ����]" << endl;
		} break;
		case ����:
		{
			cout << "[���ݼӵ�: ����]" << endl;
		} break;
		case �ſ����:
		{
			cout << "[���ݼӵ�: �ſ����]" << endl;
		} break;
		}
	}
	else { cout << endl; }
	cout << "[����: " << GetDP() << "]" << endl;
	cout << "[ũ��Ƽ��: " << GetCRITICAL() << "]" << endl;
	cout << "[HP: " << GetHP() << "][MP: " << GetMP() << "]" << endl;
	cout << "[������ ����]------------------------------------------------------------------" << endl;
	cout << GetItemDescription() << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}
// ���� ����������2
void Item_Equip::ItemInformation2()
{
	cout << "[����������]-------------------------------------------------------------------" << endl;
	cout << "[" << GetItemName() << "]";
	switch (GetItemGrade())
	{
	case ���:
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ���]" << endl;
	} break;
	case ����:
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����] " << endl;
	} break;
	case ����:
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����] " << endl;
	} break;
	case ����ũ:
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����ũ] " << endl;
	} break;
	}
	cout << "[�߰��ɷ�ġ]--" << endl;
	if (GetMin_AP() != 0 || GetMax_AP() != 0)
	{
		cout << "[���ݷ�: " << GetMin_AP() << " ~ " << GetMax_AP() << "]" << endl;
	}
	if (nEquipCode == ����)
	{
		switch (nAttackSpeed)
		{
		case �ſ����:
		{
			cout << "[���ݼӵ�: �ſ����]" << endl;
		} break;
		case ����:
		{
			cout << "[���ݼӵ�: ����]" << endl;
		} break;
		case ����:
		{
			cout << "[���ݼӵ�: ����]" << endl;
		} break;
		case ����:
		{
			cout << "[���ݼӵ�: ����]" << endl;
		} break;
		case �ſ����:
		{
			cout << "[���ݼӵ�: �ſ����]" << endl;
		} break;
		}
	}
	if (GetDP() != 0 || GetCRITICAL() != 0 || GetHP() != 0 || GetMP() != 0)
	{
		if (GetDP() != 0)
		{
			cout << "[����: " << GetDP() << "]" << endl;
		}
		if (GetCRITICAL() != 0)
		{
			cout << "[ũ��Ƽ��: " << GetCRITICAL() << "]" << endl;
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
	cout << "[������ ����]--" << endl;
	cout << GetItemDescription() << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}
// ������ ������ ����
void Item_Equip::ChangeItemDurability(int use)
{
	if (nC_Durability + use >= 0) this->nC_Durability += use;
	else this->nC_Durability = 0;
}