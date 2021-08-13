#pragma once
#include <iostream>

using namespace std;

enum E_Category { 빈칸 = 0, 장비아이템 = 1000, 소비아이템 = 2000 };
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

	//Get(), Set()
	string GetItemName() { return nItemName; }
	void SetItemName(string name) { this->nItemName = name; }
	int GetItemLVLimit() { return nLVLimit; }
	void SetItemLbLimit(int limit) { this->nLVLimit = limit; }
	int GetItemGrade() { return nItemGrade; }
	void SetItemGrade(E_ItemGrade grade) { this->nItemGrade = grade; }
	string GetItemDescription() { return nItemDescription; }
	void SetItemDescription(string description); //아이템 설명
};