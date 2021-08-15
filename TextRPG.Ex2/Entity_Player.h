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
	int nSTR = 0; // ���� ������� �ö󰡴� ��������Ʈ
	int nCRITICAL = 0; // ���� ������� �ö󰡴� ��������Ʈ
	int nDEF = 0; // ���� ������� �ö󰡴� ��������Ʈ
	int nAdditional_MAXSTR = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ
	int nAdditional_MINSTR = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ
	int nAdditional_CRITICAL = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ
	int nAdditional_DEF = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ

	Map* nCurrentMap = NULL;

public:
	Item_Equip* EquipmentSlot_Weapon = NULL;
	int nHaveGold = 0;
	// ������
	Player(string name, int lv, int hp, int mp, int sp, int dp, int speed, int str, int critical, int def);
	// ��ü����
	void EntityStatus();
	// ������ �÷��̾� ����
	void PlayerBattleStatus();
	// �÷��̾� ����ġȹ�� �ý���
	void PlayerEXPSystem(int exp);
	// �÷��̾� ������, ��� ȹ�� �ý���
	void PlayerDropSystem(Item* item = NULL, int Gold = 0);
	// �÷��̾� ���Ⱥй�
	void PlayerStatusChangeSystem();
	// �÷��̾� ���� ���� ������ �ý���
	void Set_Equip_Weapon_DurabilitySystem(int use);
	// �÷��̾� ���� ���뿡 ���� ���� ����
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