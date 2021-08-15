#pragma once
#include <iostream>
#include <queue>
#include "Entity.h"
#include "Map.h"
#include "Item.h"
#include "Item_Equip.h"

using namespace std;

class Player : public Entity
{
	int nMAXEXP = 12;
	int nCurrentEXP = 0;

	int nCanUseStatusPoint = 0;
	int nUsedStatusPoint = 0;
	int nSTR = 0; // 스탯 배분으로 올라가는 스탯포인트
	int nCRITICAL = 0; // 스탯 배분으로 올라가는 스탯포인트
	int nDEF = 0; // 스탯 배분으로 올라가는 스탯포인트
	int nAdditional_MAXSTR = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트
	int nAdditional_MINSTR = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트
	int nAdditional_CRITICAL = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트
	int nAdditional_DEF = 0; // 아이템, 스킬 로 올라가는 추가 스탯포인트

	Map* nCurrentMap = NULL;

public:
	Item_Equip* EquipmentSlot_Weapon = NULL;
	int nHaveGold = 0;
	// 생성자
	Player(string name, int lv, int hp, int mp, int sp, int dp, int speed, int str, int critical, int def);
	// 개체정보
	void EntityStatus();
	// 전투시 플레이어 정보
	void PlayerBattleStatus();
	// 플레이어 경험치획득 시스템
	void PlayerEXPSystem(int exp);
	// 플레이어 아이템, 골드 획득 시스템
	void PlayerDropSystem(Item* item = NULL, int Gold = 0);
	// 플레이어 스탯분배
	void PlayerStatusChangeSystem();
	// 플레이어 착용 무기 내구도 시스템
	void Set_Equip_Weapon_DurabilitySystem(int use);
	// 플레이어 무기 착용에 따른 스탯 변경
	void SetEquipment_Weapon(Item* weapon);

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
	int GetAdditional_STR() { return nAdditional_STR; }
	void SetAdditional_STR(int str) { this->nAdditional_STR = str; }
	int GetAdditional_CRITICAL() { return nAdditional_CRITICAL; }
	void SetAdditional_CRITICAL(int critical) { this->nAdditional_CRITICAL = critical; }
	int GetAdditional_DEF() { return nAdditional_DEF; }
	void SetAdditional_DEF(int def) { this->nAdditional_DEF = def; }
};