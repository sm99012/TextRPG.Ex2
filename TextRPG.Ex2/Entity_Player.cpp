#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <conio.h>
#include <random>
#include <algorithm>
#include "Entity.h"
#include "Entity_Monster.h"
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
	EntityStatus();
}
// 개체정보
void Player::EntityStatus()
{
	cout << "[플레이어 스테이터스 창]-------------------------------------------------------" << endl;
	cout << "[이름: " << GetName() << "]" << endl;
	cout << "[LV: " << GetLV() << " [" << nCurrentEXP << "/" << nMAXEXP << "]]" << endl;
	cout << "[C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", 총 데미지: " << GetMinDamage() << " ~ " << GetMaxDamage() << ", 크리티컬: " << nAdditional_CRITICAL << " %, 방어력: " << GetDefensivePower() << "]" << endl;
	cout << endl;
	cout << "[사용한 스탯포인트: [공격력: " << nSTR;
	switch (nAttackSpeed)
	{
	case 매우느림:
	{
		cout << ", 공격속도: 매우느림";
	} break;
	case 느림:
	{
		cout << ", 공격속도: 느림";
	} break;
	case 보통:
	{
		cout << ", 공격속도: 보통";
	} break;
	case 빠름:
	{
		cout << ", 공격속도: 빠름";
	} break;
	case 매우빠름:
	{
		cout << ", 공격속도: 매우빠름";
	} break;
	}
	cout << ", 크리티컬: " << nCRITICAL << ", 방어력: " << nDEF << "]]" << endl;
	cout << "[사용한 스탯포인트: " << nUsedStatusPoint << " / 사용하지 않은 스탯포인트: " << nCanUseStatusPoint << "]" << endl;
	cout << "[추가 스탯포인트: [공격력: " << nAdditional_MINSTR << " ~ " <<nAdditional_MAXSTR << ", 크리티컬: " << nAdditional_CRITICAL << ", 방어력: " << nAdditional_DEF << "]]" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	if (EquipmentSlot_Weapon != NULL && EquipmentSlot_Weapon->GetItemLVLimit() > 0) // 아이템 제한랩이 0인템은 존재하지않음
	{
		cout << "장비아이템_무    기: [" << EquipmentSlot_Weapon->GetItemName() << "]";
		EquipmentSlot_Weapon->ItemStatus();
	}
	else { cout << "장비아이템_무    기: " << endl; }
	if (EquipmentSlot_StepWeapon != NULL && EquipmentSlot_StepWeapon->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_보조무기: [" << EquipmentSlot_StepWeapon->GetItemName() << "]";
		EquipmentSlot_StepWeapon->ItemStatus();
	}
	else { cout << "장비아이템_보조무기: " << endl; }
	if (EquipmentSlot_Hat != NULL && EquipmentSlot_Hat->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_모    자: [" << EquipmentSlot_Hat->GetItemName() << "]";
		EquipmentSlot_Hat->ItemStatus();
	}
	else { cout << "장비아이템_모    자: " << endl; }
	if (EquipmentSlot_Top != NULL && EquipmentSlot_Top->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_상    의: [" << EquipmentSlot_Top->GetItemName() << "]";
		EquipmentSlot_Top->ItemStatus();
	}
	else { cout << "장비아이템_상    의: " << endl; }
	if (EquipmentSlot_Pants != NULL && EquipmentSlot_Pants->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_하    의: [" << EquipmentSlot_Pants->GetItemName() << "]";
		EquipmentSlot_Pants->ItemStatus();
	}
	else { cout << "장비아이템_하    의: " << endl; }
	if (EquipmentSlot_Glove != NULL && EquipmentSlot_Glove->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_장    갑: [" << EquipmentSlot_Glove->GetItemName() << "]";
		EquipmentSlot_Glove->ItemStatus();
	}
	else { cout << "장비아이템_장    갑: " << endl; }
	if (EquipmentSlot_Shose != NULL && EquipmentSlot_Shose->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_신    발: [" << EquipmentSlot_Shose->GetItemName() << "]";
		EquipmentSlot_Shose->ItemStatus();
	}
	else { cout << "장비아이템_신    발: " << endl; }
	if (EquipmentSlot_Pendant != NULL && EquipmentSlot_Pendant->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_펜 던 트: [" << EquipmentSlot_Pendant->GetItemName() << "]";
		EquipmentSlot_Pendant->ItemStatus();
	}
	else { cout << "장비아이템_펜 던 트: " << endl; }
	if (EquipmentSlot_Ring != NULL && EquipmentSlot_Ring->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_반    지: [" << EquipmentSlot_Ring->GetItemName() << "]";
		EquipmentSlot_Ring->ItemStatus();
	}
	else { cout << "장비아이템_반    지: " << endl; }
	if (EquipmentSlot_Medal != NULL && EquipmentSlot_Medal->GetItemLVLimit() > 0)
	{
		cout << "장비아이템_훈    장: [" << EquipmentSlot_Medal->GetItemName() << "]";
		EquipmentSlot_Medal->ItemStatus();
	}
	else { cout << "장비아이템_훈    장: " << endl; }
	cout << "-------------------------------------------------------------------------------" << endl;
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
		this->nMAXEXP = this->nMAXEXP * 1.1;
		ChangeEntityStatus_LV(1);
		nCanUseStatusPoint += 1;
	}
}
// 플레이어 스탯분배
void Player::PlayerStatusChangeSystem()
{
	bool isUse = true;
	while (isUse == true)
	{
		system("cls");
		EntityStatus();
		cout << "[1.공격력 증가][2.크리티컬 증가][3.방어력 증가][4.창닫기]" << endl;
		cout << "선택지 입력: ";
		int Number1 = _getch();
		//cin >> Number;
		switch (Number1)
		{
		case 49:
		{
			cout << "[1.공격력 증가]" << endl;
			cout << "[1.공격력 증가] 에 스탯포인트를 분배 하시겠습니까?[1.확인][2.취소]" << endl;
			cout << "선택지 입력: ";
			int Number2 = _getch();
			switch (Number2)
			{
			case 49:
			{
				if (nCanUseStatusPoint > 0)
				{
					nSTR++;
					nCanUseStatusPoint--;
					nUsedStatusPoint++;
					ChangeEntityStatus_Damage(1, 1);
				}
				else
				{
					cout << "사용할 수 있는 스탯포인트가 없습니다." << endl;
					Sleep(1000);
				}
			} break;
			default: break;
			}
		} break;
		case 50:
		{
			cout << "[2.크리티컬 증가]" << endl;
			cout << "[2.크리티컬 증가] 에 스탯포인트를 분배 하시겠습니까?[1.확인][2.취소]" << endl;
			cout << "선택지 입력: ";
			int Number2 = _getch();
			switch (Number2)
			{
			case 49:
			{
				if (nCanUseStatusPoint > 0)
				{
					nCRITICAL++;
					nCanUseStatusPoint--;
					nUsedStatusPoint++;
				}
				else
				{
					cout << "사용할 수 있는 스탯포인트가 없습니다." << endl;
					Sleep(1000);
				}
			} break;
			default: break;
			}
		} break;
		case 51:
		{
			cout << "[3.방어력 증가]" << endl;
			cout << "[3.방어력 증가] 에 스탯포인트를 분배 하시겠습니까?[1.확인][2.취소]" << endl;
			cout << "선택지 입력: ";
			int Number2 = _getch();
			switch (Number2)
			{
			case 49:
			{
				if (nCanUseStatusPoint > 0)
				{
					nDEF++;
					nCanUseStatusPoint--;
					nUsedStatusPoint++;
					ChangeEntityStatus_DefensivePower(1);
				}
				else
				{
					cout << "사용할 수 있는 스탯포인트가 없습니다." << endl;
					Sleep(1000);
				}
			} break;
			default: break;
			}
		} break;
		case 52:
		{
			isUse = false;
		} break;
		default: return;
		}
	}
}
// 플레이어 착용 무기 내구도 시스템
void Player::Set_Equip_Weapon_DurabilitySystem(int use)
{
	if (EquipmentSlot_Weapon)
	EquipmentSlot_Weapon->ChangeItemDurability(use);
}

// 플레이어 장비 착용에 따른 스탯 변경 // 밑의 함수들을위한 함수.
void Player::SetEquipment_Status(Item* item ,int n)
{
	if (n == 1) // 착용중인장비가 없을때
	{
		nAdditional_HP += item->GetHP();
		nAdditional_MP += item->GetMP();
		nAdditional_MAXSTR += item->GetMax_AP();
		nAdditional_MINSTR += item->GetMin_AP();
		nAdditional_DEF += item->GetDP();

		int ATSpeed = item->GetAttackSpeed();
		int nAS = nAttackSpeed;
		if (ATSpeed != null)
		{
			//cout << "ItemSpeed: " << ATSpeed << ", PlayerSpeed: " << nAS << endl; Sleep(3000);
			nAS += ATSpeed;
			switch (nAS)
			{
			case -2:
			{
				nAttackSpeed = 매우느림;
			} break;
			case -1:
			{
				nAttackSpeed = 느림;
			} break;
			case 0:
			{
				nAttackSpeed = 보통;
			} break;
			case 1:
			{
				nAttackSpeed = 빠름;
			} break;
			case 2:
			{
				nAttackSpeed = 매우빠름;
			} break;
			}
		}
	}
	if (n == -1) // 착용중인장비가 있을때
	{
		nAdditional_HP -= item->GetHP();
		nAdditional_MP -= item->GetMP();
		nAdditional_MAXSTR -= item->GetMax_AP();
		nAdditional_MINSTR -= item->GetMin_AP();
		nAdditional_DEF -= item->GetDP();
		int ATSpeed = item->GetAttackSpeed();
		int nAS = nAttackSpeed;

		if (ATSpeed != null)
		{
			nAS -= ATSpeed;
			switch (nAS)
			{
			case -2:
			{
				nAttackSpeed = 매우느림;
			} break;
			case -1:
			{
				nAttackSpeed = 느림;
			} break;
			case 0:
			{
				nAttackSpeed = 보통;
			} break;
			case 1:
			{
				nAttackSpeed = 빠름;
			} break;
			case 2:
			{
				nAttackSpeed = 매우빠름;
			} break;
			}
		}
	}
}
// 플레이어 장비 착용에 따른 스탯 변경(통합)
void Player::SetEquipment(Item* Equipment, int Number)
{
	// 착용할 장비의 분류.
	Item** EquipmentSlot = NULL;
	//cout << Equipment->GetEquipCode(); Sleep(2000);
	switch (Equipment->GetEquipCode())
	{
	case 무기:
		EquipmentSlot = &EquipmentSlot_Weapon; break;
	case 보조무기:
		EquipmentSlot = &EquipmentSlot_StepWeapon; break;
	case 모자:
		EquipmentSlot = &EquipmentSlot_Hat; break;
	case 상의:
		EquipmentSlot = &EquipmentSlot_Top; break;
	case 하의:
		EquipmentSlot = &EquipmentSlot_Pants; break;
	case 장갑:
		EquipmentSlot = &EquipmentSlot_Glove; break;
	case 신발:
		EquipmentSlot = &EquipmentSlot_Shose; break;
	case 펜던트:
		EquipmentSlot = &EquipmentSlot_Pendant; break;
	case 반지:
		EquipmentSlot = &EquipmentSlot_Ring; break;
	case 훈장:
		EquipmentSlot = &EquipmentSlot_Medal; break;
	default:
		cout << "Error: 아이템의 분류가 정확하지 않습니다." << endl;
		Sleep(5000);
		return;
	}
	// 장비와 플레이어간의 제한사항 검토
	if (GetLV() >= Equipment->GetItemLVLimit() && Equipment->GetItemLVLimit() != 0)
	{
		if (*EquipmentSlot == NULL)
		{
			*EquipmentSlot = Equipment;
			ItemSlot_A[Number] = NULL;
			SetEquipment_Status(*EquipmentSlot, 1);
			// Debug
			//cout << Equipment->GetItemName() << ": " << Equipment << endl;
			//if (EquipmentSlot_StepWeapon)
			//	cout << EquipmentSlot_StepWeapon->GetItemName() << ": " << EquipmentSlot_StepWeapon << endl;
			//else
			//	cout << "EquipmentSlot_StepWeapon: NULL" << endl;
		}
		else
		{
			ItemSlot_A[Number] = *EquipmentSlot;
			SetEquipment_Status(*EquipmentSlot, -1);
			*EquipmentSlot = Equipment;
			nAdditional_HP += Equipment->GetHP();
			nAdditional_MP += Equipment->GetMP();
			nAdditional_MAXSTR += Equipment->GetMax_AP();
			nAdditional_MINSTR += Equipment->GetMin_AP();
			nAdditional_DEF += Equipment->GetDP();
			int ATSpeed = Equipment->GetAttackSpeed();
			int nAS = nAttackSpeed;
			if (ATSpeed != null)
			{
				nAS += ATSpeed;
				switch (nAS)
				{
				case -2:
				{
					nAttackSpeed = 매우느림;
				} break;
				case -1:
				{
					nAttackSpeed = 느림;
				} break;
				case 0:
				{
					nAttackSpeed = 보통;
				} break;
				case 1:
				{
					nAttackSpeed = 빠름;
				} break;
				case 2:
				{
					nAttackSpeed = 매우빠름;
				} break;
				}
			}
		}
		PlayerTotalStatusSystem();
		cout << "[" << Equipment->GetItemName() << "] 을(를) 착용했습니다." << endl;
		Sleep(1000);
	}
	else if (GetLV() < Equipment->GetItemLVLimit()) { cout << "플레이어의 레벨이 아이템의 착용제한 레벨보다 낮습니다." << endl; }
	else { cout << "아이템이 존재하지 않습니다." << endl; }
}

// 플레이어 총 스탯 계산
void Player::PlayerTotalStatusSystem()
{
	SetMaxDamage(nSTR + nAdditional_MAXSTR);
	SetMinDamage(nSTR + nAdditional_MINSTR);
	SetDefensivePower(nDEF + nAdditional_DEF);
	SetM_HP(10 + nAdditional_HP);
	SetM_MP(0 + nAdditional_MP);
}

// 아이템, 골드 드랍
void Player::PlayerDrop(Item* item, int gold)
{
	switch (item->GetItemCategory())
	{
	case 장비아이템:
	{
		bool isExtraSpace = true;
		int i = 0;
		while (ItemSlot_A[i] != 0)
		{
			i++;
		}
		if (i == 20) { cout << "장비아이템 슬롯이 가득찼습니다." << endl; }
		else 
		{ 
			ItemSlot_A[i] = item;
			//cout << "장비아이템 [" << item->GetItemName() << "] 획득!" << endl;
		}
	} break;
	case 소비아이템:
	{
		bool isExtraSpace = true;
		int i = 0;
		while (ItemSlot_B[i] != 0)
		{
			i++;
		}
		if (i == 20) { cout << "소비아이템 슬롯이 가득찼습니다." << endl; }
		else
		{
			ItemSlot_B[i] = item;
			cout << "소비아이템 [ " << item->GetItemName() << "] 획득!" << endl;
		}
	} break;
	case 기타아이템:
	{
		bool isExtraSpace = true;
		int i = 0;
		while (ItemSlot_C[i] != 0)
		{
			i++;
		}
		if (i == 20) { cout << "기타아이템 슬롯이 가득찼습니다." << endl; }
		else
		{
			ItemSlot_C[i] = item;
			cout << "기타아이템 [ " << item->GetItemName() << "] 획득!" << endl;
		}
	} break;
	}
	nHaveGold += gold;
}
// 인벤토리(장비)
void Player::ItemSlot_ASystem()
{
	bool isItemSlot_A = true;
	while (isItemSlot_A == true)
	{
		system("cls");
		cout << "[인벤토리[장비]]---------------------------------------------------------------" << endl;
		for (int i = 0; i < sizeof(ItemSlot_A) / 8; i++)
		{
			if (ItemSlot_A[i] != 0)
			{
				cout << i + 1 << ". " << ItemSlot_A[i]->GetItemName() << endl;
			}
			else { cout << i + 1 << ". " << endl; }
		}
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "[1.장비선택][2.창닫기]" << endl;
		cout << "선택지입력: ";
		int Choice1 = _getch();
		//cin >> Choice1;
		switch (Choice1)
		{
		case 49:
		{
			cout << "[1.장비선택]" << endl;
			cout << "장비를 선택하세요. [1 ~ 20]" << endl;
			cout << "선택지입력: ";
			int Choice2;
			cin >> Choice2;
			if (Choice2 > 0 && Choice2 < 21)
			{
				if (ItemSlot_A[Choice2 - 1] != 0)
				{
					system("cls");
					ItemSlot_A[Choice2 - 1]->ItemInformation2();
					cout << "[1.장착][2.확인][3.버리기]" << endl;
					cout << "선택지입력: ";
					int Choice3 = _getch();
					switch (Choice3)
					{
					case 49:
					{
						SetEquipment(ItemSlot_A[Choice2 - 1], Choice2 - 1);
						
					} break;
					case 51:
					{
						cout << "[3.버리기]" << endl;
						cout << "정말 아이템을 버리시겠습니까? [1.확인][2.취소]" << endl;
						cout << "선택지입력: ";
						int Choice3;
						cin >> Choice3;
						if (Choice3 == 1)
						{
							cout << "[" << ItemSlot_A[Choice2 - 1]->GetItemName() << "] 을(를) 버렸습니다." << endl;
							ItemSlot_A[Choice2 - 1] = NULL;
							Sleep(2000);
						}
					} break;
					default: break;
					}
				}
				else
				{
					cout << "해당 아이템슬롯이 비어있습니다." << endl;
					Sleep(2000);
				}
			}
			else
			{
				cout << "존재하지 않는 아이템슬롯입니다." << endl;
				cout << "[1.확인]" << endl;
				cout << "선택지입력: ";
				int Choice3 = _getch();
			}
		} break;
		case 50:
		{
			isItemSlot_A = false;
		} break;
		}
	}
}
// 인벤토리(소비)
void Player::ItemSlot_BSystem()
{
	for (int i = 0; i < sizeof(ItemSlot_B) / 8; i++)
	{
		if (ItemSlot_B[i] != 0)
		{
			cout << i + 1 << ". " << ItemSlot_B[i]->GetItemName() << endl;
		}
		else { cout << i + 1 << ". " << endl; }
	}
}
// 인벤토리(기타)
void Player::ItemSlot_CSystem()
{
	for (int i = 0; i < sizeof(ItemSlot_C) / 8; i++)
	{
		if (ItemSlot_C[i] != 0)
		{
			cout << i + 1 << ". " << ItemSlot_C[i]->GetItemName() << endl;
		}
		else { cout << i + 1 << ". " << endl; }
	}
}

// 플레이어 이동
void Player::PlayerMoveMap()
{
	bool nEnd = false;
	while (nEnd == false)
	{
		cout << "[" << nCurrentMap->GetMapName() << "]" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		nCurrentMap->DisplayMap();
		cout << "-------------------------------------------------------------------------------" << endl;
		if (nCurrentMap->nUpMap != NULL) { cout << "    [▲]"; }
		else { cout << "    [△]"; }
		cout << endl;
		if (nCurrentMap->nLeftMap != NULL) { cout << "[◀]"; }
		else { cout << "[◁]"; }
		if (nCurrentMap->nDownMap != NULL) { cout << "[▼]"; }
		else { cout << "[▽]"; }
		if (nCurrentMap->nRightMap != NULL) { cout << "[▶]"; }
		else { cout << "[▷]"; }
		cout << endl;
		cout << "선택지 입력: ";
		int Choice1 = _getch();
		switch (Choice1)
		{
		case 77:
		{
			if (nCurrentMap->nRightMap != NULL) { nCurrentMap = nCurrentMap->nRightMap; }
			else { cout << "해당 맵은 존재하지 않습니다!" << endl; }
		} Sleep(1000); break;
		case 75:
		{
			if (nCurrentMap->nLeftMap != NULL) { nCurrentMap = nCurrentMap->nLeftMap; }
			else { cout << "해당 맵은 존재하지 않습니다!" << endl; }
		} Sleep(1000); break;
		case 72:
		{
			if (nCurrentMap->nUpMap != NULL) { nCurrentMap = nCurrentMap->nUpMap; }
			else { cout << "해당 맵은 존재하지 않습니다!" << endl; }
		} Sleep(1000); break;
		case 80:
		{
			if (nCurrentMap->nDownMap != NULL) { nCurrentMap = nCurrentMap->nDownMap; }
			else { cout << "해당 맵은 존재하지 않습니다!" << endl; }
		} Sleep(1000); break;
		}
		system("cls");
	}
}
// 플레이어, 몬스터 전투상호작용
int Attack(Player* player, Monster* monster, int n)
{
	srand(time(0));
	if (n == 0)
	{
		int P_Damage = rand() % (player->GetMaxDamage() - player->GetMinDamage() + 1) + player->GetMinDamage();
		int Damage = P_Damage - monster->GetDefensivePower();
		if (Damage <= 0) Damage = 1;
		monster->ChangeEntityStatus_CHPCMP(-Damage, 0);
		return Damage;
	}
	else if (n == 1)
	{
		int M_Damage = monster->GetMaxDamage() - player->GetDefensivePower();
		if (M_Damage <= 0) M_Damage = 1;
		player->ChangeEntityStatus_CHPCMP(-M_Damage, 0);
		return M_Damage;
	}
}
// 전투 출력
void Attack_Output_PlayerDamage(Player* player, Monster* monster, int Damage, int n)
{
	if (n == 0)
	{
		if (Damage <= 0) Damage = 1;

		cout << "[" << monster->GetName() << "] 에게 [" << Damage << "] 만큼의 데미지를 주었다!" << endl;
		cout << "[" << monster->GetName() << ": [" << monster->GetC_HP() << "/" << monster->GetM_HP() << "]]" << endl;
	}
	else if (n == 1)
	{
		if (Damage <= 0) Damage = 1;

		cout << "[" << monster->GetName() << "] 에게 [" << Damage << "] 만큼의 데미지를 받았다!" << endl;
		cout << "[" << player->GetName() << ": [" << player->GetC_HP() << "/" << player->GetM_HP() << "]]" << endl;
	}
}
// 전투 출력
void Defense_Output_Player(Player* player)
{
	int OutputCount = player->GetDefensivePower();
	cout << "[" << player->GetName() << "] 의 [방어력] 이 [" << OutputCount << "] 이 되었다!" << endl;
}
// 전투 출력
void BattleEnd_Output(Player* player, Monster* monster, int n)
{
	if (n == 0)
	{
		int GetEXP = monster->GetEXP();
		int GetGold = monster->GetDropGold();
		player->PlayerEXPSystem(GetEXP);

		cout << "[" << monster->GetName() << "] 은(는) 죽었다!" << endl;
		cout << "[" << player->GetName() << "] [경험치: + " << GetEXP << "]" << endl;
		cout << "[" << player->GetName() << "] [Gold: + " << GetGold << "]" << endl;
		monster->MonsterDropSystem(player);
	}
	else
	{
		cout << "[" << player->GetName() << "] 은(는) 죽었다!" << endl;
	}
}
// 전투
bool Player::Battle(Monster* monster)
{
	Monster* m = monster;
	bool isBattle = true;
	while (GetC_HP() > 0 && m->GetC_HP() > 0 && isBattle == true)
	{
		cout << "[" << nCurrentMap->GetMapName() << "][전투]" << endl;
		PlayerBattleStatus();
		m->EntityStatus();
		cout << "[1.공격][2.방어][3.도망]" << endl;
		cout << "선택지 입력: ";
		int Number = _getch();
		//cin >> Number;
		int DEF; //[2.방어] 선택시 플레이어의 방어력은 두배로 적용되고 몬스터를 직접 공격할 수 없다.
		switch (Number)
		{
		case 49:
		{
			system("cls");
			cout << "[" << nCurrentMap->GetMapName() << "][전투]" << endl;
			PlayerBattleStatus();
			m->EntityStatus();
			cout << "[플레이어 공격]" << endl;
			if (nAttackSpeed == 보통)
			{
				int P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
			}
			else if (nAttackSpeed == 빠름)
			{
				int P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
				Sleep(1000);
				P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
			}
			else if (nAttackSpeed == 매우빠름)
			{
				int P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
				Sleep(1000);
				P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
				Sleep(1000);
				P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
			}
			Set_Equip_Weapon_DurabilitySystem(-1);
			Sleep(2000);
			system("cls");
			cout << "[" << nCurrentMap->GetMapName() << "][전투]" << endl;
			this->PlayerBattleStatus();
			m->EntityStatus();
			if (m->GetC_HP() > 0)
			{
				int M_Damage = Attack(this, m, 1);
				cout << "[몬스터 공격]" << endl;
				Attack_Output_PlayerDamage(this, m, M_Damage, 1);
				Sleep(2000);
				system("cls");
			}
			break;
		}
		case 50:
		{
			system("cls");
			DEF = GetDefensivePower();
			ChangeEntityStatus_DefensivePower(DEF);
			cout << "[" << nCurrentMap->GetMapName() << "][전투]" << endl;
			PlayerBattleStatus();
			m->EntityStatus();
			cout << "플레이어 방어" << endl;
			Set_Equip_Weapon_DurabilitySystem(-1);
			Defense_Output_Player(this);
			Sleep(2000);
			system("cls");
			int M_Damage = Attack(this, m, 1);
			cout << "[" << nCurrentMap->GetMapName() << "][전투]" << endl;
			PlayerBattleStatus();
			m->EntityStatus();
			if (m->GetC_HP() > 0)
			{
				cout << "몬스터 공격" << endl;
				Attack_Output_PlayerDamage(this, m, M_Damage, 1);
				Sleep(2000);
				system("cls");
			}
			ChangeEntityStatus_DefensivePower(-DEF);
			cout << "[" << nCurrentMap->GetMapName() << "][전투]" << endl;
			PlayerBattleStatus();
			m->EntityStatus();
			cout << "플레이어 방어해제" << endl;
			Defense_Output_Player(this);
			Sleep(2000);
			system("cls");
			break;
		}
		case 51:
		{
			cout << "[3.도망]" << endl;
			cout << endl;
			cout << "플레이어는 도망쳤다!" << endl;
			isBattle = false;
			Sleep(2000);
			return false;
			break;
		}
		}
	}
	if (GetC_HP() <= 0) { isBattle = false; }
	if (isBattle == true)
	{
		system("cls");
		BattleEnd_Output(this, m, 0);
		cout << "[1.확인]" << endl;
		int Number2 = _getch();
		return true;
	}
	else
	{
		BattleEnd_Output(this, m, 1);
		return false;
	}
}
// 게임 실행
void Player::PlayerMove()
{
	bool isEnd = false;
	int x = nCurrentMap->Map_FindEntity(9, 0);
	int y = nCurrentMap->Map_FindEntity(9, 1);
	while (isEnd == false)
	{
		cout << "[" << nCurrentMap->GetMapName() << "]" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		nCurrentMap->DisplayMap();
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "[1.스테이터스][2.아이템창][3.체력회복]" << endl;
		cout << "선택지 입력: ";
		int Choice1 = _getch();
		if (Choice1 == 224) Choice1 = _getch();
		switch (Choice1)
		{
		case 49:
		{
			PlayerStatusChangeSystem();
			//Sleep(5000);
		} break;
		case 50:
		{
			cout << "[2.아이템창]" << endl;
			cout << "[1.장비][2.소비][3.기타][Gold: " << nHaveGold << "]" << endl;
			cout << "선택지 입력: " << endl;
			int Choice2 = _getch();
			{
				switch (Choice2)
				{
				case 49:
				{
					system("cls");
					//EntityStatus();
					ItemSlot_ASystem();
				} break;
				case 50:
				{
					system("cls");
					EntityStatus();
					ItemSlot_BSystem();
				} break;
				case 51:
				{
					system("cls");
					EntityStatus();
					ItemSlot_CSystem();
				} break;
				}
			}
		} break;
		case 51:
		{
			SetC_HP(GetM_HP());
		} break;
		case 77:
		{
			if (nCurrentMap->nField[x + 1][y] == 0
				|| nCurrentMap->nField[x + 1][y] == 3 || nCurrentMap->nField[x + 1][y] == 4 || nCurrentMap->nField[x + 1][y] == 5 || nCurrentMap->nField[x + 1][y] == 6
				|| nCurrentMap->nField[x + 1][y] == 7 || nCurrentMap->nField[x + 1][y] == 8)
			{
				if (nCurrentMap->nField[x + 1][y] == 0) // 플레이어 맵 내에서 이동
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap->nField[x + 1][y] = 9;
					x += 1;
				}
				else if (nCurrentMap->nField[x + 1][y] == 3) // 오른쪽맵 이동
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap = nCurrentMap->nRightMap;
					x = nCurrentMap->Map_FindEntity(4, 0) + 1;
					y = nCurrentMap->Map_FindEntity(4, 1);
					nCurrentMap->nField[x][y] = 9;
				}
				else if (nCurrentMap->nField[x + 1][y] == 8) // 몬스터와 전투
				{
					if (nCurrentMap->nAppearingMonster.front())
					{
						random_device rd;
						default_random_engine rng(rd());
						shuffle(nCurrentMap->nAppearingMonster.begin(), nCurrentMap->nAppearingMonster.end(), rng);
						Monster m = *nCurrentMap->nAppearingMonster.front();
						system("cls");
						if (Battle(&m) == true)
						{
							nCurrentMap->nField[x][y] = 0;
							nCurrentMap->nField[x + 1][y] = 9;
							x += 1;
						}
					}
				}
			}
		} break;
		case 75:
		{
			if (nCurrentMap->nField[x - 1][y] == 0
				|| nCurrentMap->nField[x - 1][y] == 3 || nCurrentMap->nField[x - 1][y] == 4 || nCurrentMap->nField[x - 1][y] == 5 || nCurrentMap->nField[x - 1][y] == 6
				|| nCurrentMap->nField[x - 1][y] == 7 || nCurrentMap->nField[x - 1][y] == 8)
			{
				if (nCurrentMap->nField[x - 1][y] == 0)
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap->nField[x - 1][y] = 9;
					x -= 1;
				}
				else if (nCurrentMap->nField[x - 1][y] == 4) // 왼쪽맵 이동
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap = nCurrentMap->nLeftMap;
					x = nCurrentMap->Map_FindEntity(3, 0) - 1;
					y = nCurrentMap->Map_FindEntity(3, 1);
					nCurrentMap->nField[x][y] = 9;
				}
				else if (nCurrentMap->nField[x - 1][y] == 8) // 몬스터와 전투
				{
					if (nCurrentMap->nAppearingMonster.front())
					{
						random_device rd;
						default_random_engine rng(rd());
						shuffle(nCurrentMap->nAppearingMonster.begin(), nCurrentMap->nAppearingMonster.end(), rng);
						Monster m = *nCurrentMap->nAppearingMonster.front();
						system("cls");
						if (Battle(&m) == true)
						{
							nCurrentMap->nField[x][y] = 0;
							nCurrentMap->nField[x - 1][y] = 9;
							x -= 1;
						}
					}
				}
			}
		} break;
		case 72:
		{
			if (nCurrentMap->nField[x][y - 1] == 0 
				|| nCurrentMap->nField[x][y - 1] == 3 || nCurrentMap->nField[x][y - 1] == 4 || nCurrentMap->nField[x][y - 1] == 5 || nCurrentMap->nField[x][y - 1] == 6
				|| nCurrentMap->nField[x][y - 1] == 7 || nCurrentMap->nField[x][y - 1] == 8)
			{
				if (nCurrentMap->nField[x][y - 1] == 0)
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap->nField[x][y - 1] = 9;
					y -= 1;
				}
				else if (nCurrentMap->nField[x][y - 1] == 5) // 위쪽맵 이동
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap = nCurrentMap->nUpMap;
					x = nCurrentMap->Map_FindEntity(6, 0);
					y = nCurrentMap->Map_FindEntity(6, 1) - 1;
					nCurrentMap->nField[x][y] = 9;
				}
				else if (nCurrentMap->nField[x][y - 1] == 8) // 몬스터와 전투
				{
					if (nCurrentMap->nAppearingMonster.front())
					{
						random_device rd;
						default_random_engine rng(rd());
						shuffle(nCurrentMap->nAppearingMonster.begin(), nCurrentMap->nAppearingMonster.end(), rng);
						Monster m = *nCurrentMap->nAppearingMonster.front();
						system("cls");
						if (Battle(&m) == true)
						{
							nCurrentMap->nField[x][y] = 0;
							nCurrentMap->nField[x][y - 1] = 9;
							y -= 1;
						}
					}
				}
			}
		}break;
		case 80:
		{
			if (nCurrentMap->nField[x][y + 1] == 0 
				|| nCurrentMap->nField[x][y + 1] == 3 || nCurrentMap->nField[x][y + 1] == 4 || nCurrentMap->nField[x][y + 1] == 5 || nCurrentMap->nField[x][y + 1] == 6
				|| nCurrentMap->nField[x][y + 1] == 7 || nCurrentMap->nField[x][y + 1] == 8)
			{
				if (nCurrentMap->nField[x][y + 1] == 0)
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap->nField[x][y + 1] = 9;
					y += 1;
				}
				else if (nCurrentMap->nField[x][y + 1] == 6) // 아래쪽맵 이동
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap = nCurrentMap->nDownMap;
					x = nCurrentMap->Map_FindEntity(5, 0);
					y = nCurrentMap->Map_FindEntity(5, 1) + 1;
					nCurrentMap->nField[x][y] = 9;
				}
				else if (nCurrentMap->nField[x][y + 1] == 8) // 몬스터와 전투
				{
					if (nCurrentMap->nAppearingMonster.front())
					{
						random_device rd;
						default_random_engine rng(rd());
						shuffle(nCurrentMap->nAppearingMonster.begin(), nCurrentMap->nAppearingMonster.end(), rng);
						Monster m = *nCurrentMap->nAppearingMonster.front();
						system("cls");
						if (Battle(&m) == true)
						{
							nCurrentMap->nField[x][y] = 0;
							nCurrentMap->nField[x][y + 1] = 9;
							y += 1;
						}
					}
				}
			}
		} break;
		default: cout << Choice1; Sleep(5000); isEnd = true; break;
		}
		system("cls");
	}
}