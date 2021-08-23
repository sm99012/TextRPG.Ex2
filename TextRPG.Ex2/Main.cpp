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

// 맵 생성(선언)
Map* StartingMap = new Map("시작의 마을", 1);
Map* TrainingForest = new Map("훈련의 숲", 2);
Map* North_WayToSlimeVillage1 = new Map("북부_슬라임마을로 가는 길1", 3);
Map* North_WayToSlimeVillage2 = new Map("북부_슬라임마을로 가는 길2", 4);
Map* North_WayToSlimeVillage3 = new Map("북부_슬라임마을로 가는 길3", 5);
Map* North_SlimeVillageCenter = new Map("북부_슬라임마을 중심지", 6);
Map* North_SlimeVillageResidence = new Map("북부_슬라임마을 거주지", 7);
Map* North_SlimeRevolutionAssociation = new Map("북부_슬라임 혁명 협회", 8);
Map* North_AltSlimesHidingBaseCamp = new Map("북부_알트 슬라임의 은신처", 9);
Map* North_SecretSlimeRoom = new Map("북부_비밀의 방", 10);
Map* North_SlimeVillageMarket = new Map("북부_슬라임마을 시장", 11);
Map* North_SlimeVillageMainStreet = new Map("북부_슬라임마을 번화가", 12);
Map* North_CenterOfSlimeCastle1 = new Map("북부_슬라임성 중심부1", 13);
Map* North_CenterOfSlimeCastle2 = new Map("북부_슬라임성 중심부2", 14);
Map* North_SlimeCastellansRoom = new Map("북부_슬라임성 성주의 방", 15);
Map* North_GoldGrassSlimesHouse = new Map("북부_골드그래스 슬라임의 거처", 16);
Map* North_SlimeBlackMarket = new Map("북부_슬라임마을 암시장", 17);
Map* North_EastOfSlimeCastle = new Map("북부_슬라임성 동쪽", 18);
Map* North_SlimeVillageRestingArea = new Map("북부_슬라임마을 쉼터", 19);
// 맵 불러오기
FILE* F_MapForm = fopen("c:\\맵폴더\\MapForm.txt", "r");
FILE* F_StartingMap = fopen("c:\\맵폴더\\StartingMap.txt", "r");
FILE* F_TrainingForest = fopen("c:\\맵폴더\\TrainingForest.txt", "r");
FILE* F_North_WayToSlimeVillage1 = fopen("c:\\맵폴더\\North_WayToSlimeVillage1.txt", "r");
FILE* F_North_WayToSlimeVillage2 = fopen("c:\\맵폴더\\North_WayToSlimeVillage2.txt", "r");
FILE* F_North_WayToSlimeVillage3 = fopen("c:\\맵폴더\\North_WayToSlimeVillage3.txt", "r");
FILE* F_North_SlimeVillageCenter = fopen("c:\\맵폴더\\North_SlimeVillageCenter.txt", "r");
FILE* F_North_SlimeVillageResidence = fopen("c:\\맵폴더\\North_SlimeVillageResidence.txt", "r");
FILE* F_North_SlimeRevolutionAssociation = fopen("c:\\맵폴더\\North_SlimeRevolutionAssociation.txt", "r");
FILE* F_North_AltSlimesHidingBaseCamp = fopen("c:\\맵폴더\\North_AltSlimesHidingBaseCamp.txt", "r");
FILE* F_North_SecretSlimeRoom = fopen("c:\\맵폴더\\North_SecretSlimeRoom.txt", "r");
FILE* F_North_SlimeVillageMarket = fopen("c:\\맵폴더\\North_SlimeVillageMarket.txt", "r");
FILE* F_North_SlimeVillageMainStreet = fopen("c:\\맵폴더\\North_SlimeVillageMainStreet.txt", "r");
FILE* F_North_CenterOfSlimeCastle1 = fopen("c:\\맵폴더\\North_CenterOfSlimeCastle1.txt", "r");
FILE* F_North_CenterOfSlimeCastle2 = fopen("c:\\맵폴더\\North_CenterOfSlimeCastle2.txt", "r");
FILE* F_North_SlimeCastellansRoom = fopen("c:\\맵폴더\\North_SlimeCastellansRoom.txt", "r");
FILE* F_North_GoldGrassSlimesHouse = fopen("c:\\맵폴더\\North_GoldGrassSlimesHouse.txt", "r");
FILE* F_North_SlimeBlackMarket = fopen("c:\\맵폴더\\North_SlimeBlackMarket.txt", "r");
FILE* F_North_EastOfSlimeCastle = fopen("c:\\맵폴더\\North_EastOfSlimeCastle.txt", "r");
FILE* F_North_SlimeVillageRestingArea = fopen("c:\\맵폴더\\North_SlimeVillageRestingArea.txt", "r");
// 플레이어 생성(선언)
Player* P_Player = new Player("플레이어", 1, 10, 0, 0, 0, 1, 0, 0, 0);
// 몬스터 생성(선언)
Monster* M_WeakSlime = new Monster("약화된 슬라임", 1, 5, 0, 1, 1, 1, 4, 2);
Monster* M_SoldierSlime1 = new Monster("슬라임 병사 1", 4, 10, 5, 5, 3, 1, 12, 4);
Monster* M_SoldierSlime2 = new Monster("슬라임 병사 2", 4, 20, 5, 2, 3, 1, 10, 5);
Monster* M_EliteSoldierSlime1 = new Monster("정예 슬라임 병사 1", 7, 15, 10, 9, 5, 1, 20, 7);
Monster* M_EliteSoldierSlime2 = new Monster("정예 슬라임 병사 2", 7, 30, 10, 4, 5, 1, 16, 9);
Monster* M_SlimeKnightStila = new Monster("슬라임기사 스틸라", 11, 40, 10, 12, 7, 1, 48, 12);
// 아이템 생성(선언)

// 무기
Item_Equip* Weapon_BeginnersWoodenSword = new Item_Equip("초보자의 목검", 무기, 10001, 1, 노멀, 1, 2, 0, 보통, 100);
Item_Equip* Weapon_CommonSword = new Item_Equip("평범한 검", 무기, 10002, 2, 노멀, 2, 3, 0, 보통, 100);
Item_Equip* Weapon_Saber = new Item_Equip("사브르", 무기, 10003, 5, 노멀, 1, 2, 0, 빠름, 100);
Item_Equip* Weapon_OldKnife = new Item_Equip("낡은 단검", 무기, 10004, 3, 레어, 0, 5, 0, 빠름, 30);
// 보조무기
Item_Equip* StepWeapon_BeginnersStepDagger = new Item_Equip("초보자의 보조단검", 보조무기, 11001, 1, 노멀, 0, 0, 0, 빠름, 50);
Item_Equip* StepWeapon_SlimeKnightStilasStepDagger = new Item_Equip("슬라임기사 스틸라의 보조단검", 보조무기, 11010, 11, 레어, 3, 4, 3, 빠름, 120);
// 모자
Item_Equip* Hat_BeginnersHat = new Item_Equip("초보자의 모자", 모자, 12001, 1, 노멀, 0, 0, 1, null, 100);
// 상의
Item_Equip* Top_BeginnersTop = new Item_Equip("초보자의 상의", 상의, 13001, 1, 노멀, 0, 0, 1, null, 100);
// 하의
Item_Equip* Pants_BeginnersPants = new Item_Equip("초보자의 하의", 하의, 14001, 1, 노멀, 0, 0, 1, null, 100);
// 장갑
Item_Equip* Glove_BeginnersGlove = new Item_Equip("초보자의 장갑", 장갑, 15001, 1, 노멀, 0, 0, 1, null, 100);
// 신발
Item_Equip* Shose_BeginnersShose = new Item_Equip("초보자의 신발", 신발, 16001, 1, 노멀, 0, 0, 1, null, 100);
// 펜던트
Item_Equip* Pendant_TheBlessingOfTheStarting = new Item_Equip("시작의 축복 펜던트", 펜던트, 17001, 1, 노멀, 1, 1, 1, null, 100, 3, 3, 0);
// 반지
Item_Equip* Ring_TheBlessingOfTheStarting = new Item_Equip("시작의 축복 반지", 반지, 18001, 1, 노멀, 1, 1, 1, null, 100, 3, 3, 0);
// 훈장
Item_Equip* Medal_TheBlessingOfTheStarting = new Item_Equip("시작의 축복 훈장", 훈장, 19001, 1, 노멀, 1, 1, 1, null, 100, 3, 3, 0);
// 맵 초기설정
void CreateMap()
{
	// 맵 불러오기
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
	// 맵 연결
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
	// 맵 테스트
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
	// 맵에 출몰몬스터 설정
	StartingMap->SetMap_Monster(M_WeakSlime);
	North_WayToSlimeVillage1->SetMap_Monster(M_WeakSlime);
	North_WayToSlimeVillage1->SetMap_Monster(M_SoldierSlime1);
	North_WayToSlimeVillage1->SetMap_Monster(M_SoldierSlime2);
	North_WayToSlimeVillage2->SetMap_Monster(M_SoldierSlime1);
	North_WayToSlimeVillage2->SetMap_Monster(M_SoldierSlime1);
}
// 플레이어 초기설정
void CreatePlayer()
{
	//P_Player->PlayerDrop(Weapon_BeginnersWoodenSword);
	//P_Player->PlayerDrop(Top_BeginnersTop);
	//P_Player->PlayerDrop(Pants_BeginnersPants);
	//P_Player->ItemSlot_ASystem(); //아이템슬롯[장비]
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
// 몬스터 초기설정
void CreateMonster()
{
	// 드랍설정
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
// 아이템 초기설정
void CreateItem()
{
	// 무기
	Weapon_BeginnersWoodenSword->SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 검이다.\n살상력이 뛰어나다고 할 수는 없다.");
	Weapon_CommonSword->SetItemDescription("평범~한 검.");
	Weapon_Saber->SetItemDescription("TextRPG 월드 서쪽지방에서 널리 사용되는 검이다.\n공격력은 낮지만 매우 가벼워 공격속도가 빠르다.");
	Weapon_OldKnife->SetItemDescription("금방이라도 부서질겉만같은 오래된 단검이다.\n하지만 낡았다고 방심하면 큰코다친다.");
	// 보조무기
	StepWeapon_BeginnersStepDagger->SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 보조무기이다.\n내부 기능이없는 장식품으로 보인다.");
	StepWeapon_SlimeKnightStilasStepDagger->SetItemDescription("슬라임기사 스틸라의 보조무기이다.\n항상 강함을 추구하는 스틸라의 노력이 고스란히 담겨있다.");
	// 모자
	Hat_BeginnersHat->SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 모자이다.\n방어력이 뛰어나다고 할 수는 없다.");
	// 상의
	Top_BeginnersTop->SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 상의이다.\n방어력이 뛰어나다고 할 수는 없다.");
	// 하의
	Pants_BeginnersPants->SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 하의이다.\n방어력이 뛰어나다고 할 수는 없다.");
	// 장갑
	Glove_BeginnersGlove->SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 장갑이다.\n방어력이 뛰어나다고 할 수는 없다.");
	// 신발
	Shose_BeginnersShose->SetItemDescription("TextRPG 월드에방문한 모험가들에게 주어지는 기본적인 신발이다.\n방어력이 뛰어나다고 할 수는 없다.");
	// 펜던트
	Pendant_TheBlessingOfTheStarting->SetItemDescription("시작의 마을에서 퀘스트를 클리어하면 받을 수 있는 펜던트이다.\n소소한 축복이 담겨있다.");
	// 반지
	Ring_TheBlessingOfTheStarting->SetItemDescription("시작의 마을에서 퀘스트를 클리어하면 받을 수 있는 반지이다.\n소소한 축복이 담겨있다.");
	//훈장
	Medal_TheBlessingOfTheStarting->SetItemDescription("시작의 마을에서 퀘스트를 클리어하면 받을 수 있는 훈장이다.\n소소한 축복이 담겨있다.");
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