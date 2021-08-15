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
	//Player* m_Player = new Player("플레이어", 1, 20, 5, 1, 1, 1, 0, 0, 0);
	//m_Player->EntityStatus();
	Item_Equip* Weapon_WoodenSword = new Item_Equip("목검", 무기, 10001, 1, 노멀, 1, 2, 1, 보통, 100);
	Weapon_WoodenSword->SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 검이다.\n살상력이 뛰어나다고 할 수는 없다.");
	Weapon_WoodenSword->ItemStatus();
}