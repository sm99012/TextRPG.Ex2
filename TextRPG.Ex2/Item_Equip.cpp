#include <iostream>
#include "Item.h"
#include "Item_Equip.h"

using namespace std;

// ������
Item_Equip::Item_Equip(string itemname, E_EquipCode equipcode, int itemcode, int lvlimit, E_ItemGrade itemgrade, int min_ap, int max_ap, int dp, int attackspeed, int durability) : Item(itemname, ��������, itemcode, lvlimit, itemgrade)
{
	this->nEquipCode = equipcode;
	this->nMIN_AP = min_ap;
	this->nMAX_AP = max_ap;
	this->nDP = dp;
	this->nAttackSpeed = attackspeed;
	this->nM_Durability = durability;
	this->nC_Durability = durability;
}
// ����������
void Item_Equip::ItemStatus()
{
	cout << "��������_����: [" << GetItemName() << "]" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	if (GetItemGrade() == ���)
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ���]" << endl;
	}
	else if (GetItemGrade() == ����)
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����]" << endl;
	}
	else if (GetItemGrade() == ����)
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����]" << endl;
	}
	else if (GetItemGrade() == ����ũ)
	{
		cout << "[LV: " << GetItemLVLimit() << "][���: ����ũ]" << endl;
	}
	if (nAttackSpeed == �ſ����)
	{
		cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: �ſ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	else if (nAttackSpeed == ����)
	{
		cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	else if (nAttackSpeed == ����)
	{
		cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	else if (nAttackSpeed == ����)
	{
		cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	else if (nAttackSpeed == �ſ����)
	{
		cout << "[���ݷ�: " << nMIN_AP << " ~ " << nMAX_AP << "][����: " << nDP << "][���ݼӵ�: �ſ����][������ : " << nC_Durability << "/" << nM_Durability << "]" << endl;
	}
	cout << "--------------------------------------------------------------------------" << endl;
	cout << GetItemDescription() << endl;
}
// ������ ������ ����
void Item_Equip::ChangeItemDurability(int use)
{
	if (nC_Durability + use >= 0) this->nC_Durability + use;
	else this->nC_Durability = 0;
}