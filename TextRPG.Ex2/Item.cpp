#include <iostream>
#include "Item.h"

using namespace std;

// 持失切 1
Item::Item (string itemname, int category, int itemcode, int lvlimit, int itemgrade)
{
	this->nItemName = itemname;
	this->nItemCategory = category;
	this->nItemCode = itemcode;
	this->nLVLimit = lvlimit;
	this->nItemGrade = itemgrade;
}
// 持失切 2
Item::Item(string itemname, E_Category category, int itemcode, int lvlimit, E_ItemGrade itemgrade)
{
	this->nItemName = itemname;
	this->nItemCategory = category;
	this->nItemCode = itemcode;
	this->nLVLimit = lvlimit;
	this->nItemGrade = itemgrade;
}