#pragma once
#include <iostream>

using namespace std;

enum E_Category { ��ĭ = 0, �������� = 10000, �Һ������ = 20000, ��Ÿ������ = 30000 };
enum E_ItemGrade { ��� = 0, ���� = 1, ���� = 2, ����ũ = 3 };

class Item
{
	string nItemName;
	int nItemCategory;
	int nItemCode;
	int nLVLimit;
	int nItemGrade;
	string nItemDescription;

public:
	// ������ 1
	Item(string itemname, int category, int itemcode, int lvlimit, int itemgrade);
	// ������ 2
	Item(string itemname, E_Category category, int itemcode, int lvlimit, E_ItemGrade itemgrade);
	// ����������
	virtual void ItemStatus() = 0;
	// ���� ����������1
	virtual void ItemInformation1() = 0;
	// ���� ����������2
	virtual void ItemInformation2() = 0;

	// �����Լ�
	// Item_Equip �� �����Լ�
	virtual int GetEquipCode() { return 0; }
	virtual int GetMin_AP() { return 0; }
	virtual int GetMax_AP() { return 0; }
	virtual int GetDP() { return 0; }
	virtual int GetHP() { return 0; }
	virtual int GetMP() { return 0; }
	virtual int GetCRITICAL() { return 0; }
	virtual void ChangeItemDurability(int use) {}
	virtual int GetAttackSpeed() { return 0; }

	//Get(), Set()
	string GetItemName() { return nItemName; }
	void SetItemName(string name) { this->nItemName = name; }
	int GetItemCategory() { return nItemCategory; }
	void SetItemCategory(E_Category ca) { this->nItemCategory = ca; }
	int GetItemCode() { return nItemCode; }
	void SetItemCode(int code) { this->nItemCode = code; }
	int GetItemLVLimit() { return nLVLimit; }
	void SetItemLbLimit(int limit) { this->nLVLimit = limit; }
	int GetItemGrade() { return nItemGrade; }
	void SetItemGrade(E_ItemGrade grade) { this->nItemGrade = grade; }
	string GetItemDescription() { return nItemDescription; }
	void SetItemDescription(string description) { this->nItemDescription = description; } //������ ����
};