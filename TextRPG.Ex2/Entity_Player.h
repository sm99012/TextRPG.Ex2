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
	int nSTR = 0; // ���� ������� �ö󰡴� ��������Ʈ
	int nCRITICAL = 0; // ���� ������� �ö󰡴� ��������Ʈ
	int nDEF = 0; // ���� ������� �ö󰡴� ��������Ʈ
	int nAdditional_HP = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ // ���� �߰� ����
	int nAdditional_MP = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ // ���� �߰� ����
	int nAdditional_MAXSTR = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ
	int nAdditional_MINSTR = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ
	int nAdditional_CRITICAL = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ
	int nAdditional_DEF = 0; // ������, ��ų �� �ö󰡴� �߰� ��������Ʈ

	E_AttackSpeed nAttackSpeed = ����; // �÷��̾� ����

	Map* nCurrentMap = NULL;

public:
	Item* EquipmentSlot_Weapon = NULL; // ���â_����
	Item* EquipmentSlot_StepWeapon = NULL; // ���â_��������
	Item* EquipmentSlot_Hat = NULL; // ���â_����
	Item* EquipmentSlot_Top = NULL; // ���â_����
	Item* EquipmentSlot_Pants = NULL; // ���â_����
	Item* EquipmentSlot_Glove = NULL; // ���â_�尩
	Item* EquipmentSlot_Shose = NULL; // ���â_�Ź�
	Item* EquipmentSlot_Pendant = NULL; // ���â_���Ʈ
	Item* EquipmentSlot_Ring = NULL; // ���â_����
	Item* EquipmentSlot_Medal = NULL; // ���â_����

	Item* ItemSlot_A[20] = { 0, }; // �����۽���_���
	Item* ItemSlot_B[20] = { 0, }; // �����۽���_�Һ�
	Item* ItemSlot_C[20] = { 0, }; // �����۽���_��Ÿ

	int nHaveGold = 0;

	// ������
	Player(string name, int lv, int hp, int mp, int sp, int dp, int speed, int str, int critical, int def);
	// ��ü����
	void EntityStatus();
	// ������ �÷��̾� ����
	void PlayerBattleStatus();
	// �÷��̾� ����ġȹ�� �ý���
	void PlayerEXPSystem(int exp);
	// �÷��̾� ���Ⱥй�
	void PlayerStatusChangeSystem();
	// �÷��̾� ���� ���� ������ �ý���
	void Set_Equip_Weapon_DurabilitySystem(int use);
	// �÷��̾� ��� ���뿡 ���� ���� ���� // ���� �Լ��������� �Լ�.
	void SetEquipment_Status(Item* item, int n);
	// �÷��̾� ��� ���뿡 ���� ���� ����(����)
	void SetEquipment(Item* Equipment, int Number);

	// ������, ��� ���
	void PlayerDrop(Item* item = NULL, int gold = 0);
	// �κ��丮(���)
	void ItemSlot_ASystem();
	// �κ��丮(�Һ�)
	void ItemSlot_BSystem();
	// �κ��丮(��Ÿ)
	void ItemSlot_CSystem();
	// �÷��̾� �� ���� ���
	void PlayerTotalStatusSystem();

	// �÷��̾� �̵�
	void PlayerMoveMap();
	// ����
	bool Battle(Monster* monster);
	// ���� ����
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