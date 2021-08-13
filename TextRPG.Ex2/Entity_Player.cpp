#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "Entity.h"
#include "Entity_Player.h"
#include "Map.h"
#include "Item.h"

using namespace std;

// 생성자
Player::Player(string name, int lv, int hp, int mp, int sp, int dp, int speed, int str, int critical, int def) : Entity(name, lv, hp, mp, sp, dp, speed)
{
	this->nSTR = str;
	this->nCRITICAL = critical;
	this->nDEF = def;
}
// 개체정보
void Player::EntityStatus()
{
	cout << "[플레이어 스테이터스 창]--------------------------------------------------" << endl;
	cout << "[이름: " << GetName() << "]" << endl;
	cout << "[LV: " << GetLV() << " [" << nCurrentEXP << "/" << nMAXEXP << "]]" << endl;
	cout << "[C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", 공격력: " << GetMinDamage() << " ~ " << GetMaxDamage() << ", 크리티컬: " << nAdditional_CRITICAL << " %, 방어력: " << GetDefensivePower() << "]" << endl;
	cout << endl;
	cout << "[사용한 스탯포인트: [공격력: " << nAdditional_STR << ", 크리티컬: " << nAdditional_CRITICAL << ", 방어력: " << nAdditional_DEF << "]]" << endl;
	cout << "[사용한 스탯포인트: " << nUsedStatusPoint << " / 사용하지 않은 스탯포인트: " << nCanUseStatusPoint << "]" << endl;
	if (EquipmentSlot_Weapon != NULL)
	{
		EquipmentSlot_Weapon->ItemStatus();
	}
	cout << "--------------------------------------------------------------------------" << endl;
}
// 전투시 플레이어 정보
void Player::PlayerBattleStatus()
{
	cout << "[이름: " << GetName() << ", LV: " << GetLV() << ", C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << "]" << endl;
	cout << endl;
}
// 플레이어 경험치획득 시스템
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
// 플레이어 아이템, 골드 획득 시스템
void Player::PlayerDropSystem(Item* item, int gold)
{

	this->nHaveGold += gold;
}
// 플레이어 스탯분배
void Player::PlayerStatusChangeSystem()
{
	cout << "[1.공격력 증가][2.크리티컬 증가][3.방어력 증가][4.창닫기]" << endl;
	cout << "선택지 입력: ";
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
			cout << "사용할 수 있는 스탯포인트가 없습니다." << endl;
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
			cout << "사용할 수 있는 스탯포인트가 없습니다." << endl;
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
			cout << "사용할 수 있는 스탯포인트가 없습니다." << endl;
			//Sleep(1000);
		}
		break;
	}
	default: return;
	}
	//PlayerStatusSystem();
}
// 플레이어 착용 무기 내구도 시스템
void Player::Set_Equip_Weapon_DurabilitySystem(int durability)
{

}
// 플레이어 무기 착용에 따른 스탯 변경
void Player::SetEquipment_Weapon(Item* weapon) 
{

}