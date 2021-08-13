#pragma once
#include <iostream>

using namespace std;

enum E_Category { ��ĭ = 0, �������� = 1000, �Һ������ = 2000 };
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

	//Get(), Set()
	string GetItemName() { return nItemName; }
	void SetItemName(string name) { this->nItemName = name; }
	int GetItemLVLimit() { return nLVLimit; }
	void SetItemLbLimit(int limit) { this->nLVLimit = limit; }
	int GetItemGrade() { return nItemGrade; }
	void SetItemGrade(E_ItemGrade grade) { this->nItemGrade = grade; }
	string GetItemDescription() { return nItemDescription; }
	void SetItemDescription(string description); //������ ����
};