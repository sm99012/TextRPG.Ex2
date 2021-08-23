#pragma once
#include <iostream>

using namespace std;

enum E_Category { 빈칸 = 0, 장비아이템 = 10000, 소비아이템 = 20000, 기타아이템 = 30000 };
enum E_ItemGrade { 노멀 = 0, 레어 = 1, 에픽 = 2, 유니크 = 3 };

class Item
{
	string nItemName;
	int nItemCategory;
	int nItemCode;
	int nLVLimit;
	int nItemGrade;
	string nItemDescription;

public:
	// 생성자 1
	Item(string itemname, int category, int itemcode, int lvlimit, int itemgrade);
	// 생성자 2
	Item(string itemname, E_Category category, int itemcode, int lvlimit, E_ItemGrade itemgrade);
	// 아이템정보
	virtual void ItemStatus() = 0;
	// 세부 아이템정보1
	virtual void ItemInformation1() = 0;
	// 세부 아이템정보2
	virtual void ItemInformation2() = 0;

	// 가상함수
	// Item_Equip 의 가상함수
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
	void SetItemDescription(string description) { this->nItemDescription = description; } //아이템 설명
};