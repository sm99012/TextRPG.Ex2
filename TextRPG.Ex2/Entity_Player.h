#pragma once
#include <iostream>
#include "Entity.h"
#include "Map.h"
#include "Item.h"
#include "Item_Equip.h"

using namespace std;

class Monster;

class Player : public Entity
{
	int nMAXEXP = 12;
	int nCurrentEXP = 0;

	int nCanUseStatusPoint = 0;
	int nUsedStatusPoint = 0;
	int nSTR = 0; // 스탯 배분으로 올라가는 스탯포인트
	int nCRITICAL = 0; // 스탯 배분으로 올라가는 스탯포인트
	int nDEF = 0; // 스탯 배분으로 올라가는 스탯포인트
	int nAdditional_HP = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트 // 추후 추가 예정
	int nAdditional_MP = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트 // 추후 추가 예정
	int nAdditional_MAXSTR = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트
	int nAdditional_MINSTR = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트
	int nAdditional_CRITICAL = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트
	int nAdditional_DEF = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트

	E_AttackSpeed nAttackSpeed = 보통; // 플레이어 공속

	Map* nCurrentMap = NULL;

public:
	Item* EquipmentSlot_Weapon = NULL; // 장비창_무기
	Item* EquipmentSlot_StepWeapon = NULL; // 장비창_보조무기
	Item* EquipmentSlot_Hat = NULL; // 장비창_모자
	Item* EquipmentSlot_Top = NULL; // 장비창_상의
	Item* EquipmentSlot_Pants = NULL; // 장비창_하의
	Item* EquipmentSlot_Glove = NULL; // 장비창_장갑
	Item* EquipmentSlot_Shose = NULL; // 장비창_신발
	Item* EquipmentSlot_Pendant = NULL; // 장비창_펜던트
	Item* EquipmentSlot_Ring = NULL; // 장비창_반지
	Item* EquipmentSlot_Medal = NULL; // 장비창_훈장

	Item* ItemSlot_A[20] = { 0, }; // 아이템슬롯_장비
	Item* ItemSlot_B[20] = { 0, }; // 아이템슬롯_소비
	Item* ItemSlot_C[20] = { 0, }; // 아이템슬롯_기타

	int nHaveGold = 0;

	// 생성자
	Player(string name, int lv, int hp, int mp, int sp, int dp, int speed, int str, int critical, int def);
	// 개체정보
	void EntityStatus();
	// 전투시 플레이어 정보
	void PlayerBattleStatus();
	// 플레이어 경험치획득 시스템
	void PlayerEXPSystem(int exp);
	// 플레이어 스탯분배
	void PlayerStatusChangeSystem();
	// 플레이어 착용 무기 내구도 시스템
	void Set_Equip_Weapon_DurabilitySystem(int use);
	// 플레이어 장비 착용에 따른 스탯 변경 // 밑의 함수들을위한 함수.
	void SetEquipment_Status(Item* item, int n);
	// 플레이어 장비 착용에 따른 스탯 변경(통합)
	void SetEquipment(Item* Equipment, int Number);

	// 아이템, 골드 드랍
	void PlayerDrop(Item* item = NULL, int gold = 0);
	// 인벤토리(장비)
	void ItemSlot_ASystem();
	// 인벤토리(소비)
	void ItemSlot_BSystem();
	// 인벤토리(기타)
	void ItemSlot_CSystem();
	// 플레이어 총 스탯 계산
	void PlayerTotalStatusSystem();

	// 플레이어 이동
	void PlayerMoveMap();
	// 전투
	bool Battle(Monster* monster);
	// 게임 실행
	void PlayerMove();

	//Get(), Set()
	Map* GetPlayerMap() { return nCurrentMap; }
	void SetPlayerMap(Map* map) { this->nCurrentMap = map; }
	int GetCanUseStatusPoint() { return nCanUseStatusPoint; }
	void SetCanUseStatusPoint(int point) { this->nCanUseStatusPoint = point; }
	int GetUsedStatusPoint() { return nUsedStatusPoint; }
	void SetUserStatusPoint(int point) { this->nUsedStatusPoint = point; }
	int GetSTR() { return nSTR; }
	void SetSTR(int str) { this->nSTR = str; }
	int GetCRITICAL() { return nCRITICAL; }
	void SetCRITICAL(int critical) { this->nCRITICAL = critical; }
	int GetDEF() { return nDEF; }
	void SetDEF(int def) { this->nDEF = def; }
	int GetAdditional_MAXSTR() { return nAdditional_MAXSTR; }
	void SetAdditional_MAXSTR(int str) { this->nAdditional_MAXSTR = str; }
	int GetAdditional_MINSTR() { return nAdditional_MINSTR; }
	void SetAdditional_MINSTR(int str) { this->nAdditional_MINSTR = str; }
	int GetAdditional_CRITICAL() { return nAdditional_CRITICAL; }
	void SetAdditional_CRITICAL(int critical) { this->nAdditional_CRITICAL = critical; }
	int GetAdditional_DEF() { return nAdditional_DEF; }
	void SetAdditional_DEF(int def) { this->nAdditional_DEF = def; }
	E_AttackSpeed GetAttackSpeed() { return nAttackSpeed; }
	void SetAttackSpeed(E_AttackSpeed attackspeed) { this->nAttackSpeed = attackspeed; }
};