#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Entity.h"
#include "Entity_Player.h"
#include "Entity_Monster.h"
#include "Map.h"
#include "Item.h"
#include "Item_Equip.h"

using namespace std;

// �� ����(����)
Map* StartingMap = new Map("������ ����", 1);
Map* TrainingForest = new Map("�Ʒ��� ��", 2);
Map* North_WayToSlimeVillage1 = new Map("�Ϻ�_�����Ӹ����� ���� ��1", 3);
Map* North_WayToSlimeVillage2 = new Map("�Ϻ�_�����Ӹ����� ���� ��2", 4);
Map* North_WayToSlimeVillage3 = new Map("�Ϻ�_�����Ӹ����� ���� ��3", 5);
Map* North_SlimeVillageCenter = new Map("�Ϻ�_�����Ӹ��� �߽���", 6);
Map* North_SlimeVillageResidence = new Map("�Ϻ�_�����Ӹ��� ������", 7);
Map* North_SlimeRevolutionAssociation = new Map("�Ϻ�_������ ���� ��ȸ", 8);
Map* North_AltSlimesHidingBaseCamp = new Map("�Ϻ�_��Ʈ �������� ����ó", 9);
Map* North_SecretSlimeRoom = new Map("�Ϻ�_����� ��", 10);
Map* North_SlimeVillageMarket = new Map("�Ϻ�_�����Ӹ��� ����", 11);
Map* North_SlimeVillageMainStreet = new Map("�Ϻ�_�����Ӹ��� ��ȭ��", 12);
Map* North_CenterOfSlimeCastle1 = new Map("�Ϻ�_�����Ӽ� �߽ɺ�1", 13);
Map* North_CenterOfSlimeCastle2 = new Map("�Ϻ�_�����Ӽ� �߽ɺ�2", 14);
Map* North_SlimeCastellansRoom = new Map("�Ϻ�_�����Ӽ� ������ ��", 15);
Map* North_GoldGrassSlimesHouse = new Map("�Ϻ�_���׷��� �������� ��ó", 16);
Map* North_SlimeBlackMarket = new Map("�Ϻ�_�����Ӹ��� �Ͻ���", 17);
Map* North_EastOfSlimeCastle = new Map("�Ϻ�_�����Ӽ� ����", 18);
Map* North_SlimeVillageRestingArea = new Map("�Ϻ�_�����Ӹ��� ����", 19);
// �� �ҷ�����
FILE* F_MapForm = fopen("c:\\������\\MapForm.txt", "r");
FILE* F_StartingMap = fopen("c:\\������\\StartingMap.txt", "r");
FILE* F_TrainingForest = fopen("c:\\������\\TrainingForest.txt", "r");
FILE* F_North_WayToSlimeVillage1 = fopen("c:\\������\\North_WayToSlimeVillage1.txt", "r");
FILE* F_North_WayToSlimeVillage2 = fopen("c:\\������\\North_WayToSlimeVillage2.txt", "r");
FILE* F_North_WayToSlimeVillage3 = fopen("c:\\������\\North_WayToSlimeVillage3.txt", "r");
FILE* F_North_SlimeVillageCenter = fopen("c:\\������\\North_SlimeVillageCenter.txt", "r");
FILE* F_North_SlimeVillageResidence = fopen("c:\\������\\North_SlimeVillageResidence.txt", "r");
FILE* F_North_SlimeRevolutionAssociation = fopen("c:\\������\\North_SlimeRevolutionAssociation.txt", "r");
FILE* F_North_AltSlimesHidingBaseCamp = fopen("c:\\������\\North_AltSlimesHidingBaseCamp.txt", "r");
FILE* F_North_SecretSlimeRoom = fopen("c:\\������\\North_SecretSlimeRoom.txt", "r");
FILE* F_North_SlimeVillageMarket = fopen("c:\\������\\North_SlimeVillageMarket.txt", "r");
FILE* F_North_SlimeVillageMainStreet = fopen("c:\\������\\North_SlimeVillageMainStreet.txt", "r");
FILE* F_North_CenterOfSlimeCastle1 = fopen("c:\\������\\North_CenterOfSlimeCastle1.txt", "r");
FILE* F_North_CenterOfSlimeCastle2 = fopen("c:\\������\\North_CenterOfSlimeCastle2.txt", "r");
FILE* F_North_SlimeCastellansRoom = fopen("c:\\������\\North_SlimeCastellansRoom.txt", "r");
FILE* F_North_GoldGrassSlimesHouse = fopen("c:\\������\\North_GoldGrassSlimesHouse.txt", "r");
FILE* F_North_SlimeBlackMarket = fopen("c:\\������\\North_SlimeBlackMarket.txt", "r");
FILE* F_North_EastOfSlimeCastle = fopen("c:\\������\\North_EastOfSlimeCastle.txt", "r");
FILE* F_North_SlimeVillageRestingArea = fopen("c:\\������\\North_SlimeVillageRestingArea.txt", "r");
// �÷��̾� ����(����)
Player* P_Player = new Player("�÷��̾�", 1, 10, 0, 0, 0, 1, 0, 0, 0);
// ���� ����(����)
Monster* M_WeakSlime = new Monster("��ȭ�� ������", 1, 5, 0, 1, 1, 1, 4, 2);
Monster* M_SoldierSlime1 = new Monster("������ ���� 1", 4, 10, 5, 5, 3, 1, 12, 4);
Monster* M_SoldierSlime2 = new Monster("������ ���� 2", 4, 20, 5, 2, 3, 1, 10, 5);
Monster* M_EliteSoldierSlime1 = new Monster("���� ������ ���� 1", 7, 15, 10, 9, 5, 1, 20, 7);
Monster* M_EliteSoldierSlime2 = new Monster("���� ������ ���� 2", 7, 30, 10, 4, 5, 1, 16, 9);
Monster* M_SlimeKnightStila = new Monster("�����ӱ�� ��ƿ��", 11, 40, 10, 12, 7, 1, 48, 12);
// ������ ����(����)

// ����
Item_Equip* Weapon_BeginnersWoodenSword = new Item_Equip("�ʺ����� ���", ����, 10001, 1, ���, 1, 2, 0, ����, 100);
Item_Equip* Weapon_CommonSword = new Item_Equip("����� ��", ����, 10002, 2, ���, 2, 3, 0, ����, 100);
Item_Equip* Weapon_Saber = new Item_Equip("��긣", ����, 10003, 5, ���, 1, 2, 0, ����, 100);
Item_Equip* Weapon_OldKnife = new Item_Equip("���� �ܰ�", ����, 10004, 3, ����, 0, 5, 0, ����, 30);
// ��������
Item_Equip* StepWeapon_BeginnersStepDagger = new Item_Equip("�ʺ����� �����ܰ�", ��������, 11001, 1, ���, 0, 0, 0, ����, 50);
Item_Equip* StepWeapon_SlimeKnightStilasStepDagger = new Item_Equip("�����ӱ�� ��ƿ���� �����ܰ�", ��������, 11010, 11, ����, 3, 4, 3, ����, 120);
// ����
Item_Equip* Hat_BeginnersHat = new Item_Equip("�ʺ����� ����", ����, 12001, 1, ���, 0, 0, 1, null, 100);
// ����
Item_Equip* Top_BeginnersTop = new Item_Equip("�ʺ����� ����", ����, 13001, 1, ���, 0, 0, 1, null, 100);
// ����
Item_Equip* Pants_BeginnersPants = new Item_Equip("�ʺ����� ����", ����, 14001, 1, ���, 0, 0, 1, null, 100);
// �尩
Item_Equip* Glove_BeginnersGlove = new Item_Equip("�ʺ����� �尩", �尩, 15001, 1, ���, 0, 0, 1, null, 100);
// �Ź�
Item_Equip* Shose_BeginnersShose = new Item_Equip("�ʺ����� �Ź�", �Ź�, 16001, 1, ���, 0, 0, 1, null, 100);
// ���Ʈ
Item_Equip* Pendant_TheBlessingOfTheStarting = new Item_Equip("������ �ູ ���Ʈ", ���Ʈ, 17001, 1, ���, 1, 1, 1, null, 100, 3, 3, 0);
// ����
Item_Equip* Ring_TheBlessingOfTheStarting = new Item_Equip("������ �ູ ����", ����, 18001, 1, ���, 1, 1, 1, null, 100, 3, 3, 0);
// ����
Item_Equip* Medal_TheBlessingOfTheStarting = new Item_Equip("������ �ູ ����", ����, 19001, 1, ���, 1, 1, 1, null, 100, 3, 3, 0);
// �� �ʱ⼳��
void CreateMap()
{
	// �� �ҷ�����
	StartingMap->MapDown(F_StartingMap);
	TrainingForest->MapDown(F_TrainingForest);
	North_WayToSlimeVillage1->MapDown(F_North_WayToSlimeVillage1);
	North_WayToSlimeVillage2->MapDown(F_North_WayToSlimeVillage2);
	North_WayToSlimeVillage3->MapDown(F_North_WayToSlimeVillage3);
	North_SlimeVillageCenter->MapDown(F_North_SlimeVillageCenter);
	North_SlimeVillageResidence->MapDown(F_North_SlimeVillageResidence);
	North_SlimeRevolutionAssociation->MapDown(F_North_SlimeRevolutionAssociation);
	North_AltSlimesHidingBaseCamp->MapDown(F_North_AltSlimesHidingBaseCamp);
	North_SecretSlimeRoom->MapDown(F_North_SecretSlimeRoom);
	North_SlimeVillageMarket->MapDown(F_North_SlimeVillageMarket);
	North_SlimeVillageMainStreet->MapDown(F_North_SlimeVillageMainStreet);
	North_CenterOfSlimeCastle1->MapDown(F_North_CenterOfSlimeCastle1);
	North_CenterOfSlimeCastle2->MapDown(F_North_CenterOfSlimeCastle2);
	North_SlimeCastellansRoom->MapDown(F_North_SlimeCastellansRoom);
	North_GoldGrassSlimesHouse->MapDown(F_North_GoldGrassSlimesHouse);
	North_SlimeBlackMarket->MapDown(F_North_SlimeBlackMarket);
	North_EastOfSlimeCastle->MapDown(F_North_EastOfSlimeCastle);
	North_SlimeVillageRestingArea->MapDown(F_North_SlimeVillageRestingArea);
	// �� ����
	StartingMap->LinkRightLeftMap(TrainingForest);
	TrainingForest->LinkRightLeftMap(North_WayToSlimeVillage1);
	North_WayToSlimeVillage1->LinkRightLeftMap(North_WayToSlimeVillage2);
	North_WayToSlimeVillage2->LinkRightLeftMap(North_WayToSlimeVillage3);
	North_WayToSlimeVillage3->LinkRightLeftMap(North_SlimeVillageCenter);
	North_AltSlimesHidingBaseCamp->LinkUpDowntMap(North_SlimeRevolutionAssociation);
	North_AltSlimesHidingBaseCamp->LinkRightLeftMap(North_SecretSlimeRoom);
	North_SlimeRevolutionAssociation->LinkUpDowntMap(North_SlimeVillageResidence);
	North_SlimeVillageResidence->LinkUpDowntMap(North_SlimeVillageCenter);
	North_SlimeVillageCenter->LinkRightLeftMap(North_SlimeVillageMarket);
	North_SlimeVillageMarket->LinkRightLeftMap(North_GoldGrassSlimesHouse);
	North_GoldGrassSlimesHouse->LinkRightLeftMap(North_EastOfSlimeCastle);
	North_EastOfSlimeCastle->LinkRightLeftMap(North_SlimeVillageRestingArea);
	North_SlimeBlackMarket->LinkUpDowntMap(North_GoldGrassSlimesHouse);
	North_SlimeVillageMarket->LinkUpDowntMap(North_CenterOfSlimeCastle1);
	North_CenterOfSlimeCastle1->LinkUpDowntMap(North_CenterOfSlimeCastle2);
	North_SlimeCastellansRoom->LinkRightLeftMap(North_CenterOfSlimeCastle2);
	// �� �׽�Ʈ
	//StartingMap->DisplayMap();
	//TrainingForest->DisplayMap();
	//North_WayToSlimeVillage1->DisplayMap();
	//North_WayToSlimeVillage2->DisplayMap();
	//North_WayToSlimeVillage3->DisplayMap();
	//North_SlimeVillageCenter->DisplayMap();
	//North_SlimeVillageResidence->DisplayMap();
	//North_SlimeRevolutionAssociation->DisplayMap();
	//North_AltSlimesHidingBaseCamp->DisplayMap();
	//North_SecretSlimeRoom->DisplayMap();
	//North_SlimeVillageMarket->DisplayMap();
	//North_SlimeVillageMainStreet->DisplayMap();
	//North_CenterOfSlimeCastle1->DisplayMap();
	//North_CenterOfSlimeCastle2->DisplayMap();
	//North_SlimeCastellansRoom->DisplayMap();
	//North_GoldGrassSlimesHouse->DisplayMap();
	//North_SlimeBlackMarket->DisplayMap();
	//North_EastOfSlimeCastle->DisplayMap();
	//North_SlimeVillageRestingArea->DisplayMap();
	// �ʿ� ������� ����
	StartingMap->SetMap_Monster(M_WeakSlime);
	North_WayToSlimeVillage1->SetMap_Monster(M_WeakSlime);
	North_WayToSlimeVillage1->SetMap_Monster(M_SoldierSlime1);
	North_WayToSlimeVillage1->SetMap_Monster(M_SoldierSlime2);
	North_WayToSlimeVillage2->SetMap_Monster(M_SoldierSlime1);
	North_WayToSlimeVillage2->SetMap_Monster(M_SoldierSlime1);
}
// �÷��̾� �ʱ⼳��
void CreatePlayer()
{
	//P_Player->PlayerDrop(Weapon_BeginnersWoodenSword);
	//P_Player->PlayerDrop(Top_BeginnersTop);
	//P_Player->PlayerDrop(Pants_BeginnersPants);
	//P_Player->ItemSlot_ASystem(); //�����۽���[���]
	//P_Player->SetEquipment(Weapon_BeginnersWoodenSword);
	//P_Player->SetEquipment(StepWeapon_BeginnersStepDagger);
	//P_Player->SetEquipment(Hat_BeginnersHat);
	//P_Player->SetEquipment(Top_BeginnersTop);
	//P_Player->SetEquipment(Pants_BeginnersPants);
	//P_Player->SetEquipment(Glove_BeginnersGlove);
	//P_Player->SetEquipment(Shose_BeginnersShose);
	//P_Player->SetEquipment(Pendant_TheBlessingOfTheStarting);
	//P_Player->SetEquipment(Ring_TheBlessingOfTheStarting);
	//P_Player->SetEquipment(Medal_TheBlessingOfTheStarting);
	//P_Player->EntityStatus();
	//P_Player->SetEquipment(Medal_NULL);
	//P_Player->EntityStatus();
	//P_Player->ItemSlot_ASystem();
	P_Player->SetPlayerMap(StartingMap);
}
// ���� �ʱ⼳��
void CreateMonster()
{
	// �������
	M_WeakSlime->SetDropItem(Weapon_BeginnersWoodenSword, 10);
	M_WeakSlime->SetDropItem(Weapon_CommonSword, 10);
	M_WeakSlime->SetDropItem(Weapon_OldKnife, 10);
	M_WeakSlime->SetDropItem(Weapon_Saber, 10);
	M_WeakSlime->SetDropItem(StepWeapon_BeginnersStepDagger, 10);
	M_WeakSlime->SetDropItem(Hat_BeginnersHat, 10);
	M_WeakSlime->SetDropItem(Top_BeginnersTop, 10);
	M_WeakSlime->SetDropItem(Pants_BeginnersPants, 10);
	M_WeakSlime->SetDropItem(Glove_BeginnersGlove, 10);
	M_WeakSlime->SetDropItem(Shose_BeginnersShose, 10);
	M_SoldierSlime1->SetDropItem(StepWeapon_BeginnersStepDagger, 20);
	M_SoldierSlime1->SetDropItem(Weapon_CommonSword, 10);
	M_SoldierSlime1->SetDropItem(Weapon_OldKnife, 10);
	M_SoldierSlime1->SetDropItem(Weapon_Saber, 10);
	M_SoldierSlime1->SetDropItem(Hat_BeginnersHat, 20);
	M_SoldierSlime1->SetDropItem(Top_BeginnersTop, 20);
	M_SoldierSlime1->SetDropItem(Pants_BeginnersPants, 20);
	M_SoldierSlime1->SetDropItem(Glove_BeginnersGlove, 20);
	M_SoldierSlime1->SetDropItem(Shose_BeginnersShose, 20);
	M_SoldierSlime2->SetDropItem(StepWeapon_BeginnersStepDagger, 20);
	M_SoldierSlime2->SetDropItem(Weapon_CommonSword, 10);
	M_SoldierSlime2->SetDropItem(Weapon_OldKnife, 10);
	M_SoldierSlime2->SetDropItem(Weapon_Saber, 10);
	M_SoldierSlime2->SetDropItem(Hat_BeginnersHat, 20);
	M_SoldierSlime2->SetDropItem(Top_BeginnersTop, 20);
	M_SoldierSlime2->SetDropItem(Pants_BeginnersPants, 20);
	M_SoldierSlime2->SetDropItem(Glove_BeginnersGlove, 20);
	M_SoldierSlime2->SetDropItem(Shose_BeginnersShose, 20);
}
// ������ �ʱ⼳��
void CreateItem()
{
	// ����
	Weapon_BeginnersWoodenSword->SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� ���̴�.\n������ �پ�ٰ� �� ���� ����.");
	Weapon_CommonSword->SetItemDescription("���~�� ��.");
	Weapon_Saber->SetItemDescription("TextRPG ���� �������濡�� �θ� ���Ǵ� ���̴�.\n���ݷ��� ������ �ſ� ������ ���ݼӵ��� ������.");
	Weapon_OldKnife->SetItemDescription("�ݹ��̶� �μ����Ѹ����� ������ �ܰ��̴�.\n������ ���Ҵٰ� ����ϸ� ū�ڴ�ģ��.");
	// ��������
	StepWeapon_BeginnersStepDagger->SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� ���������̴�.\n���� ����̾��� ���ǰ���� ���δ�.");
	StepWeapon_SlimeKnightStilasStepDagger->SetItemDescription("�����ӱ�� ��ƿ���� ���������̴�.\n�׻� ������ �߱��ϴ� ��ƿ���� ����� ������ ����ִ�.");
	// ����
	Hat_BeginnersHat->SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� �����̴�.\n������ �پ�ٰ� �� ���� ����.");
	// ����
	Top_BeginnersTop->SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� �����̴�.\n������ �پ�ٰ� �� ���� ����.");
	// ����
	Pants_BeginnersPants->SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� �����̴�.\n������ �پ�ٰ� �� ���� ����.");
	// �尩
	Glove_BeginnersGlove->SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� �尩�̴�.\n������ �پ�ٰ� �� ���� ����.");
	// �Ź�
	Shose_BeginnersShose->SetItemDescription("TextRPG ���忡�湮�� ���谡�鿡�� �־����� �⺻���� �Ź��̴�.\n������ �پ�ٰ� �� ���� ����.");
	// ���Ʈ
	Pendant_TheBlessingOfTheStarting->SetItemDescription("������ �������� ����Ʈ�� Ŭ�����ϸ� ���� �� �ִ� ���Ʈ�̴�.\n�Ҽ��� �ູ�� ����ִ�.");
	// ����
	Ring_TheBlessingOfTheStarting->SetItemDescription("������ �������� ����Ʈ�� Ŭ�����ϸ� ���� �� �ִ� �����̴�.\n�Ҽ��� �ູ�� ����ִ�.");
	//����
	Medal_TheBlessingOfTheStarting->SetItemDescription("������ �������� ����Ʈ�� Ŭ�����ϸ� ���� �� �ִ� �����̴�.\n�Ҽ��� �ູ�� ����ִ�.");
}


void main()
{
	CreateMap();
	CreateItem();
	CreateMonster();
	CreatePlayer();
	system("cls");
	//P_Player->PlayerMoveMap();
	P_Player->PlayerMove();
	//P_Player->ItemSlot_ASystem();
	
	//P_Player->SetCanUseStatusPoint(5);
	//P_Player->PlayerStatusChangeSystem();
}