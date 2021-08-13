#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "Entity.h"
#include "Entity_Player.h"
#include "Map.h"
#include "Item.h"

using namespace std;

// ������
Player::Player(string name, int lv, int hp, int mp, int sp, int dp, int speed, int str, int critical, int def) : Entity(name, lv, hp, mp, sp, dp, speed)
{
	this->nSTR = str;
	this->nCRITICAL = critical;
	this->nDEF = def;
}
// ��ü����
void Player::EntityStatus()
{
	cout << "[�÷��̾� �������ͽ� â]--------------------------------------------------" << endl;
	cout << "[�̸�: " << GetName() << "]" << endl;
	cout << "[LV: " << GetLV() << " [" << nCurrentEXP << "/" << nMAXEXP << "]]" << endl;
	cout << "[C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", ���ݷ�: " << GetMinDamage() << " ~ " << GetMaxDamage() << ", ũ��Ƽ��: " << nAdditional_CRITICAL << " %, ����: " << GetDefensivePower() << "]" << endl;
	cout << endl;
	cout << "[����� ��������Ʈ: [���ݷ�: " << nAdditional_STR << ", ũ��Ƽ��: " << nAdditional_CRITICAL << ", ����: " << nAdditional_DEF << "]]" << endl;
	cout << "[����� ��������Ʈ: " << nUsedStatusPoint << " / ������� ���� ��������Ʈ: " << nCanUseStatusPoint << "]" << endl;
	if (EquipmentSlot_Weapon != NULL)
	{
		EquipmentSlot_Weapon->ItemStatus();
	}
	cout << "--------------------------------------------------------------------------" << endl;
}
// ������ �÷��̾� ����
void Player::PlayerBattleStatus()
{
	cout << "[�̸�: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << "]" << endl;
	cout << endl;
}
// �÷��̾� ����ġȹ�� �ý���
void Player::PlayerEXPSystem(int exp)
{
	nCurrentEXP += exp;
	while (nCurrentEXP >= nMAXEXP)
	{
		nCurrentEXP -= nMAXEXP;
		nMAXEXP *= 1.2;
		ChangeEntityStatus_LV(1);
		nCanUseStatusPoint += 3;
	}
}
// �÷��̾� ������, ��� ȹ�� �ý���
void Player::PlayerDropSystem(Item* item, int gold)
{

	this->nHaveGold += gold;
}
// �÷��̾� ���Ⱥй�
void Player::PlayerStatusChangeSystem()
{
	cout << "[1.���ݷ� ����][2.ũ��Ƽ�� ����][3.���� ����][4.â�ݱ�]" << endl;
	cout << "������ �Է�: ";
	int Number;
	cin >> Number;
	switch (Number)
	{
	case 1:
	{
		if (nCanUseStatusPoint > 0)
		{
			//nAdditionalStatus_STR++;
			nCanUseStatusPoint--;
			nUsedStatusPoint++;
			//AddStatus(1, 0, 0);
		}
		else
		{
			cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
			//Sleep(2000);
		}
		break;
	}
	case 2:
	{
		if (nCanUseStatusPoint > 0)
		{
			//nAdditionalStatus_CRITICAL++;
			nCanUseStatusPoint--;
			nUsedStatusPoint++;
		}
		else
		{
			cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
			//Sleep(1000);
		}
		break;
	}
	case 3:
	{
		if (nCanUseStatusPoint > 0)
		{
			//nAdditionalStatus_DEF++;
			nCanUseStatusPoint--;
			nUsedStatusPoint++;
			//AddStatus(0, 1, 0);
		}
		else
		{
			cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
			//Sleep(1000);
		}
		break;
	}
	default: return;
	}
	//PlayerStatusSystem();
}
// �÷��̾� ���� ���� ������ �ý���
void Player::Set_Equip_Weapon_DurabilitySystem(int durability)
{

}
// �÷��̾� ���� ���뿡 ���� ���� ����
void Player::SetEquipment_Weapon(Item* weapon) 
{

}