#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Entity.h"
#include "Entity_Player.h"
#include "Entity_Monster.h"
#include "Map.h"
#include "Item.h"
#include "Item_Equip.h"

using namespace std;

void main()
{
	//Player* m_Player = new Player("�÷��̾�", 1, 20, 5, 1, 1, 1, 0, 0, 0);
	//m_Player->EntityStatus();
	Item_Equip* Weapon_WoodenSword = new Item_Equip("���", ����, 10001, 1, ���, 1, 2, 1, ����, 100);
	Weapon_WoodenSword->SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� ���̴�.\n������ �پ�ٰ� �� ���� ����.");
	Weapon_WoodenSword->ItemStatus();
}