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

// ������
Player::Player(string name, int lv, int hp, int mp, int sp, int dp, int speed, int str, int critical, int def) : Entity(name, lv, hp, mp, sp, dp, speed)
{
	this->nSTR = str;
	this->nCRITICAL = critical;
	this->nDEF = def;
	EntityStatus();
}
// ��ü����
void Player::EntityStatus()
{
	cout << "[�÷��̾� �������ͽ� â]-------------------------------------------------------" << endl;
	cout << "[�̸�: " << GetName() << "]" << endl;
	cout << "[LV: " << GetLV() << " [" << nCurrentEXP << "/" << nMAXEXP << "]]" << endl;
	cout << "[C_HP/M_HP: " << GetC_HP() << "/" << GetM_HP() << ", C_MP/M_MP: " << GetC_MP() << "/" << GetM_MP() << ", �� ������: " << GetMinDamage() << " ~ " << GetMaxDamage() << ", ũ��Ƽ��: " << nAdditional_CRITICAL << " %, ����: " << GetDefensivePower() << "]" << endl;
	cout << endl;
	cout << "[����� ��������Ʈ: [���ݷ�: " << nSTR;
	switch (nAttackSpeed)
	{
	case �ſ����:
	{
		cout << ", ���ݼӵ�: �ſ����";
	} break;
	case ����:
	{
		cout << ", ���ݼӵ�: ����";
	} break;
	case ����:
	{
		cout << ", ���ݼӵ�: ����";
	} break;
	case ����:
	{
		cout << ", ���ݼӵ�: ����";
	} break;
	case �ſ����:
	{
		cout << ", ���ݼӵ�: �ſ����";
	} break;
	}
	cout << ", ũ��Ƽ��: " << nCRITICAL << ", ����: " << nDEF << "]]" << endl;
	cout << "[����� ��������Ʈ: " << nUsedStatusPoint << " / ������� ���� ��������Ʈ: " << nCanUseStatusPoint << "]" << endl;
	cout << "[�߰� ��������Ʈ: [���ݷ�: " << nAdditional_MINSTR << " ~ " <<nAdditional_MAXSTR << ", ũ��Ƽ��: " << nAdditional_CRITICAL << ", ����: " << nAdditional_DEF << "]]" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	if (EquipmentSlot_Weapon != NULL && EquipmentSlot_Weapon->GetItemLVLimit() > 0) // ������ ���ѷ��� 0������ ������������
	{
		cout << "��������_��    ��: [" << EquipmentSlot_Weapon->GetItemName() << "]";
		EquipmentSlot_Weapon->ItemStatus();
	}
	else { cout << "��������_��    ��: " << endl; }
	if (EquipmentSlot_StepWeapon != NULL && EquipmentSlot_StepWeapon->GetItemLVLimit() > 0)
	{
		cout << "��������_��������: [" << EquipmentSlot_StepWeapon->GetItemName() << "]";
		EquipmentSlot_StepWeapon->ItemStatus();
	}
	else { cout << "��������_��������: " << endl; }
	if (EquipmentSlot_Hat != NULL && EquipmentSlot_Hat->GetItemLVLimit() > 0)
	{
		cout << "��������_��    ��: [" << EquipmentSlot_Hat->GetItemName() << "]";
		EquipmentSlot_Hat->ItemStatus();
	}
	else { cout << "��������_��    ��: " << endl; }
	if (EquipmentSlot_Top != NULL && EquipmentSlot_Top->GetItemLVLimit() > 0)
	{
		cout << "��������_��    ��: [" << EquipmentSlot_Top->GetItemName() << "]";
		EquipmentSlot_Top->ItemStatus();
	}
	else { cout << "��������_��    ��: " << endl; }
	if (EquipmentSlot_Pants != NULL && EquipmentSlot_Pants->GetItemLVLimit() > 0)
	{
		cout << "��������_��    ��: [" << EquipmentSlot_Pants->GetItemName() << "]";
		EquipmentSlot_Pants->ItemStatus();
	}
	else { cout << "��������_��    ��: " << endl; }
	if (EquipmentSlot_Glove != NULL && EquipmentSlot_Glove->GetItemLVLimit() > 0)
	{
		cout << "��������_��    ��: [" << EquipmentSlot_Glove->GetItemName() << "]";
		EquipmentSlot_Glove->ItemStatus();
	}
	else { cout << "��������_��    ��: " << endl; }
	if (EquipmentSlot_Shose != NULL && EquipmentSlot_Shose->GetItemLVLimit() > 0)
	{
		cout << "��������_��    ��: [" << EquipmentSlot_Shose->GetItemName() << "]";
		EquipmentSlot_Shose->ItemStatus();
	}
	else { cout << "��������_��    ��: " << endl; }
	if (EquipmentSlot_Pendant != NULL && EquipmentSlot_Pendant->GetItemLVLimit() > 0)
	{
		cout << "��������_�� �� Ʈ: [" << EquipmentSlot_Pendant->GetItemName() << "]";
		EquipmentSlot_Pendant->ItemStatus();
	}
	else { cout << "��������_�� �� Ʈ: " << endl; }
	if (EquipmentSlot_Ring != NULL && EquipmentSlot_Ring->GetItemLVLimit() > 0)
	{
		cout << "��������_��    ��: [" << EquipmentSlot_Ring->GetItemName() << "]";
		EquipmentSlot_Ring->ItemStatus();
	}
	else { cout << "��������_��    ��: " << endl; }
	if (EquipmentSlot_Medal != NULL && EquipmentSlot_Medal->GetItemLVLimit() > 0)
	{
		cout << "��������_��    ��: [" << EquipmentSlot_Medal->GetItemName() << "]";
		EquipmentSlot_Medal->ItemStatus();
	}
	else { cout << "��������_��    ��: " << endl; }
	cout << "-------------------------------------------------------------------------------" << endl;
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
		this->nMAXEXP = this->nMAXEXP * 1.1;
		ChangeEntityStatus_LV(1);
		nCanUseStatusPoint += 1;
	}
}
// �÷��̾� ���Ⱥй�
void Player::PlayerStatusChangeSystem()
{
	bool isUse = true;
	while (isUse == true)
	{
		system("cls");
		EntityStatus();
		cout << "[1.���ݷ� ����][2.ũ��Ƽ�� ����][3.���� ����][4.â�ݱ�]" << endl;
		cout << "������ �Է�: ";
		int Number1 = _getch();
		//cin >> Number;
		switch (Number1)
		{
		case 49:
		{
			cout << "[1.���ݷ� ����]" << endl;
			cout << "[1.���ݷ� ����] �� ��������Ʈ�� �й� �Ͻðڽ��ϱ�?[1.Ȯ��][2.���]" << endl;
			cout << "������ �Է�: ";
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
					cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
					Sleep(1000);
				}
			} break;
			default: break;
			}
		} break;
		case 50:
		{
			cout << "[2.ũ��Ƽ�� ����]" << endl;
			cout << "[2.ũ��Ƽ�� ����] �� ��������Ʈ�� �й� �Ͻðڽ��ϱ�?[1.Ȯ��][2.���]" << endl;
			cout << "������ �Է�: ";
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
					cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
					Sleep(1000);
				}
			} break;
			default: break;
			}
		} break;
		case 51:
		{
			cout << "[3.���� ����]" << endl;
			cout << "[3.���� ����] �� ��������Ʈ�� �й� �Ͻðڽ��ϱ�?[1.Ȯ��][2.���]" << endl;
			cout << "������ �Է�: ";
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
					cout << "����� �� �ִ� ��������Ʈ�� �����ϴ�." << endl;
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
// �÷��̾� ���� ���� ������ �ý���
void Player::Set_Equip_Weapon_DurabilitySystem(int use)
{
	if (EquipmentSlot_Weapon)
	EquipmentSlot_Weapon->ChangeItemDurability(use);
}

// �÷��̾� ��� ���뿡 ���� ���� ���� // ���� �Լ��������� �Լ�.
void Player::SetEquipment_Status(Item* item ,int n)
{
	if (n == 1) // ����������� ������
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
				nAttackSpeed = �ſ����;
			} break;
			case -1:
			{
				nAttackSpeed = ����;
			} break;
			case 0:
			{
				nAttackSpeed = ����;
			} break;
			case 1:
			{
				nAttackSpeed = ����;
			} break;
			case 2:
			{
				nAttackSpeed = �ſ����;
			} break;
			}
		}
	}
	if (n == -1) // ����������� ������
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
				nAttackSpeed = �ſ����;
			} break;
			case -1:
			{
				nAttackSpeed = ����;
			} break;
			case 0:
			{
				nAttackSpeed = ����;
			} break;
			case 1:
			{
				nAttackSpeed = ����;
			} break;
			case 2:
			{
				nAttackSpeed = �ſ����;
			} break;
			}
		}
	}
}
// �÷��̾� ��� ���뿡 ���� ���� ����(����)
void Player::SetEquipment(Item* Equipment, int Number)
{
	// ������ ����� �з�.
	Item** EquipmentSlot = NULL;
	//cout << Equipment->GetEquipCode(); Sleep(2000);
	switch (Equipment->GetEquipCode())
	{
	case ����:
		EquipmentSlot = &EquipmentSlot_Weapon; break;
	case ��������:
		EquipmentSlot = &EquipmentSlot_StepWeapon; break;
	case ����:
		EquipmentSlot = &EquipmentSlot_Hat; break;
	case ����:
		EquipmentSlot = &EquipmentSlot_Top; break;
	case ����:
		EquipmentSlot = &EquipmentSlot_Pants; break;
	case �尩:
		EquipmentSlot = &EquipmentSlot_Glove; break;
	case �Ź�:
		EquipmentSlot = &EquipmentSlot_Shose; break;
	case ���Ʈ:
		EquipmentSlot = &EquipmentSlot_Pendant; break;
	case ����:
		EquipmentSlot = &EquipmentSlot_Ring; break;
	case ����:
		EquipmentSlot = &EquipmentSlot_Medal; break;
	default:
		cout << "Error: �������� �з��� ��Ȯ���� �ʽ��ϴ�." << endl;
		Sleep(5000);
		return;
	}
	// ���� �÷��̾�� ���ѻ��� ����
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
					nAttackSpeed = �ſ����;
				} break;
				case -1:
				{
					nAttackSpeed = ����;
				} break;
				case 0:
				{
					nAttackSpeed = ����;
				} break;
				case 1:
				{
					nAttackSpeed = ����;
				} break;
				case 2:
				{
					nAttackSpeed = �ſ����;
				} break;
				}
			}
		}
		PlayerTotalStatusSystem();
		cout << "[" << Equipment->GetItemName() << "] ��(��) �����߽��ϴ�." << endl;
		Sleep(1000);
	}
	else if (GetLV() < Equipment->GetItemLVLimit()) { cout << "�÷��̾��� ������ �������� �������� �������� �����ϴ�." << endl; }
	else { cout << "�������� �������� �ʽ��ϴ�." << endl; }
}

// �÷��̾� �� ���� ���
void Player::PlayerTotalStatusSystem()
{
	SetMaxDamage(nSTR + nAdditional_MAXSTR);
	SetMinDamage(nSTR + nAdditional_MINSTR);
	SetDefensivePower(nDEF + nAdditional_DEF);
	SetM_HP(10 + nAdditional_HP);
	SetM_MP(0 + nAdditional_MP);
}

// ������, ��� ���
void Player::PlayerDrop(Item* item, int gold)
{
	switch (item->GetItemCategory())
	{
	case ��������:
	{
		bool isExtraSpace = true;
		int i = 0;
		while (ItemSlot_A[i] != 0)
		{
			i++;
		}
		if (i == 20) { cout << "�������� ������ ����á���ϴ�." << endl; }
		else 
		{ 
			ItemSlot_A[i] = item;
			//cout << "�������� [" << item->GetItemName() << "] ȹ��!" << endl;
		}
	} break;
	case �Һ������:
	{
		bool isExtraSpace = true;
		int i = 0;
		while (ItemSlot_B[i] != 0)
		{
			i++;
		}
		if (i == 20) { cout << "�Һ������ ������ ����á���ϴ�." << endl; }
		else
		{
			ItemSlot_B[i] = item;
			cout << "�Һ������ [ " << item->GetItemName() << "] ȹ��!" << endl;
		}
	} break;
	case ��Ÿ������:
	{
		bool isExtraSpace = true;
		int i = 0;
		while (ItemSlot_C[i] != 0)
		{
			i++;
		}
		if (i == 20) { cout << "��Ÿ������ ������ ����á���ϴ�." << endl; }
		else
		{
			ItemSlot_C[i] = item;
			cout << "��Ÿ������ [ " << item->GetItemName() << "] ȹ��!" << endl;
		}
	} break;
	}
	nHaveGold += gold;
}
// �κ��丮(���)
void Player::ItemSlot_ASystem()
{
	bool isItemSlot_A = true;
	while (isItemSlot_A == true)
	{
		system("cls");
		cout << "[�κ��丮[���]]---------------------------------------------------------------" << endl;
		for (int i = 0; i < sizeof(ItemSlot_A) / 8; i++)
		{
			if (ItemSlot_A[i] != 0)
			{
				cout << i + 1 << ". " << ItemSlot_A[i]->GetItemName() << endl;
			}
			else { cout << i + 1 << ". " << endl; }
		}
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "[1.�����][2.â�ݱ�]" << endl;
		cout << "�������Է�: ";
		int Choice1 = _getch();
		//cin >> Choice1;
		switch (Choice1)
		{
		case 49:
		{
			cout << "[1.�����]" << endl;
			cout << "��� �����ϼ���. [1 ~ 20]" << endl;
			cout << "�������Է�: ";
			int Choice2;
			cin >> Choice2;
			if (Choice2 > 0 && Choice2 < 21)
			{
				if (ItemSlot_A[Choice2 - 1] != 0)
				{
					system("cls");
					ItemSlot_A[Choice2 - 1]->ItemInformation2();
					cout << "[1.����][2.Ȯ��][3.������]" << endl;
					cout << "�������Է�: ";
					int Choice3 = _getch();
					switch (Choice3)
					{
					case 49:
					{
						SetEquipment(ItemSlot_A[Choice2 - 1], Choice2 - 1);
						
					} break;
					case 51:
					{
						cout << "[3.������]" << endl;
						cout << "���� �������� �����ðڽ��ϱ�? [1.Ȯ��][2.���]" << endl;
						cout << "�������Է�: ";
						int Choice3;
						cin >> Choice3;
						if (Choice3 == 1)
						{
							cout << "[" << ItemSlot_A[Choice2 - 1]->GetItemName() << "] ��(��) ���Ƚ��ϴ�." << endl;
							ItemSlot_A[Choice2 - 1] = NULL;
							Sleep(2000);
						}
					} break;
					default: break;
					}
				}
				else
				{
					cout << "�ش� �����۽����� ����ֽ��ϴ�." << endl;
					Sleep(2000);
				}
			}
			else
			{
				cout << "�������� �ʴ� �����۽����Դϴ�." << endl;
				cout << "[1.Ȯ��]" << endl;
				cout << "�������Է�: ";
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
// �κ��丮(�Һ�)
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
// �κ��丮(��Ÿ)
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

// �÷��̾� �̵�
void Player::PlayerMoveMap()
{
	bool nEnd = false;
	while (nEnd == false)
	{
		cout << "[" << nCurrentMap->GetMapName() << "]" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		nCurrentMap->DisplayMap();
		cout << "-------------------------------------------------------------------------------" << endl;
		if (nCurrentMap->nUpMap != NULL) { cout << "    [��]"; }
		else { cout << "    [��]"; }
		cout << endl;
		if (nCurrentMap->nLeftMap != NULL) { cout << "[��]"; }
		else { cout << "[��]"; }
		if (nCurrentMap->nDownMap != NULL) { cout << "[��]"; }
		else { cout << "[��]"; }
		if (nCurrentMap->nRightMap != NULL) { cout << "[��]"; }
		else { cout << "[��]"; }
		cout << endl;
		cout << "������ �Է�: ";
		int Choice1 = _getch();
		switch (Choice1)
		{
		case 77:
		{
			if (nCurrentMap->nRightMap != NULL) { nCurrentMap = nCurrentMap->nRightMap; }
			else { cout << "�ش� ���� �������� �ʽ��ϴ�!" << endl; }
		} Sleep(1000); break;
		case 75:
		{
			if (nCurrentMap->nLeftMap != NULL) { nCurrentMap = nCurrentMap->nLeftMap; }
			else { cout << "�ش� ���� �������� �ʽ��ϴ�!" << endl; }
		} Sleep(1000); break;
		case 72:
		{
			if (nCurrentMap->nUpMap != NULL) { nCurrentMap = nCurrentMap->nUpMap; }
			else { cout << "�ش� ���� �������� �ʽ��ϴ�!" << endl; }
		} Sleep(1000); break;
		case 80:
		{
			if (nCurrentMap->nDownMap != NULL) { nCurrentMap = nCurrentMap->nDownMap; }
			else { cout << "�ش� ���� �������� �ʽ��ϴ�!" << endl; }
		} Sleep(1000); break;
		}
		system("cls");
	}
}
// �÷��̾�, ���� ������ȣ�ۿ�
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
// ���� ���
void Attack_Output_PlayerDamage(Player* player, Monster* monster, int Damage, int n)
{
	if (n == 0)
	{
		if (Damage <= 0) Damage = 1;

		cout << "[" << monster->GetName() << "] ���� [" << Damage << "] ��ŭ�� �������� �־���!" << endl;
		cout << "[" << monster->GetName() << ": [" << monster->GetC_HP() << "/" << monster->GetM_HP() << "]]" << endl;
	}
	else if (n == 1)
	{
		if (Damage <= 0) Damage = 1;

		cout << "[" << monster->GetName() << "] ���� [" << Damage << "] ��ŭ�� �������� �޾Ҵ�!" << endl;
		cout << "[" << player->GetName() << ": [" << player->GetC_HP() << "/" << player->GetM_HP() << "]]" << endl;
	}
}
// ���� ���
void Defense_Output_Player(Player* player)
{
	int OutputCount = player->GetDefensivePower();
	cout << "[" << player->GetName() << "] �� [����] �� [" << OutputCount << "] �� �Ǿ���!" << endl;
}
// ���� ���
void BattleEnd_Output(Player* player, Monster* monster, int n)
{
	if (n == 0)
	{
		int GetEXP = monster->GetEXP();
		int GetGold = monster->GetDropGold();
		player->PlayerEXPSystem(GetEXP);

		cout << "[" << monster->GetName() << "] ��(��) �׾���!" << endl;
		cout << "[" << player->GetName() << "] [����ġ: + " << GetEXP << "]" << endl;
		cout << "[" << player->GetName() << "] [Gold: + " << GetGold << "]" << endl;
		monster->MonsterDropSystem(player);
	}
	else
	{
		cout << "[" << player->GetName() << "] ��(��) �׾���!" << endl;
	}
}
// ����
bool Player::Battle(Monster* monster)
{
	Monster* m = monster;
	bool isBattle = true;
	while (GetC_HP() > 0 && m->GetC_HP() > 0 && isBattle == true)
	{
		cout << "[" << nCurrentMap->GetMapName() << "][����]" << endl;
		PlayerBattleStatus();
		m->EntityStatus();
		cout << "[1.����][2.���][3.����]" << endl;
		cout << "������ �Է�: ";
		int Number = _getch();
		//cin >> Number;
		int DEF; //[2.���] ���ý� �÷��̾��� ������ �ι�� ����ǰ� ���͸� ���� ������ �� ����.
		switch (Number)
		{
		case 49:
		{
			system("cls");
			cout << "[" << nCurrentMap->GetMapName() << "][����]" << endl;
			PlayerBattleStatus();
			m->EntityStatus();
			cout << "[�÷��̾� ����]" << endl;
			if (nAttackSpeed == ����)
			{
				int P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
			}
			else if (nAttackSpeed == ����)
			{
				int P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
				Sleep(1000);
				P_Damage = Attack(this, m, 0);
				Attack_Output_PlayerDamage(this, m, P_Damage, 0);
			}
			else if (nAttackSpeed == �ſ����)
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
			cout << "[" << nCurrentMap->GetMapName() << "][����]" << endl;
			this->PlayerBattleStatus();
			m->EntityStatus();
			if (m->GetC_HP() > 0)
			{
				int M_Damage = Attack(this, m, 1);
				cout << "[���� ����]" << endl;
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
			cout << "[" << nCurrentMap->GetMapName() << "][����]" << endl;
			PlayerBattleStatus();
			m->EntityStatus();
			cout << "�÷��̾� ���" << endl;
			Set_Equip_Weapon_DurabilitySystem(-1);
			Defense_Output_Player(this);
			Sleep(2000);
			system("cls");
			int M_Damage = Attack(this, m, 1);
			cout << "[" << nCurrentMap->GetMapName() << "][����]" << endl;
			PlayerBattleStatus();
			m->EntityStatus();
			if (m->GetC_HP() > 0)
			{
				cout << "���� ����" << endl;
				Attack_Output_PlayerDamage(this, m, M_Damage, 1);
				Sleep(2000);
				system("cls");
			}
			ChangeEntityStatus_DefensivePower(-DEF);
			cout << "[" << nCurrentMap->GetMapName() << "][����]" << endl;
			PlayerBattleStatus();
			m->EntityStatus();
			cout << "�÷��̾� �������" << endl;
			Defense_Output_Player(this);
			Sleep(2000);
			system("cls");
			break;
		}
		case 51:
		{
			cout << "[3.����]" << endl;
			cout << endl;
			cout << "�÷��̾�� �����ƴ�!" << endl;
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
		cout << "[1.Ȯ��]" << endl;
		int Number2 = _getch();
		return true;
	}
	else
	{
		BattleEnd_Output(this, m, 1);
		return false;
	}
}
// ���� ����
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
		cout << "[1.�������ͽ�][2.������â][3.ü��ȸ��]" << endl;
		cout << "������ �Է�: ";
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
			cout << "[2.������â]" << endl;
			cout << "[1.���][2.�Һ�][3.��Ÿ][Gold: " << nHaveGold << "]" << endl;
			cout << "������ �Է�: " << endl;
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
				if (nCurrentMap->nField[x + 1][y] == 0) // �÷��̾� �� ������ �̵�
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap->nField[x + 1][y] = 9;
					x += 1;
				}
				else if (nCurrentMap->nField[x + 1][y] == 3) // �����ʸ� �̵�
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap = nCurrentMap->nRightMap;
					x = nCurrentMap->Map_FindEntity(4, 0) + 1;
					y = nCurrentMap->Map_FindEntity(4, 1);
					nCurrentMap->nField[x][y] = 9;
				}
				else if (nCurrentMap->nField[x + 1][y] == 8) // ���Ϳ� ����
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
				else if (nCurrentMap->nField[x - 1][y] == 4) // ���ʸ� �̵�
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap = nCurrentMap->nLeftMap;
					x = nCurrentMap->Map_FindEntity(3, 0) - 1;
					y = nCurrentMap->Map_FindEntity(3, 1);
					nCurrentMap->nField[x][y] = 9;
				}
				else if (nCurrentMap->nField[x - 1][y] == 8) // ���Ϳ� ����
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
				else if (nCurrentMap->nField[x][y - 1] == 5) // ���ʸ� �̵�
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap = nCurrentMap->nUpMap;
					x = nCurrentMap->Map_FindEntity(6, 0);
					y = nCurrentMap->Map_FindEntity(6, 1) - 1;
					nCurrentMap->nField[x][y] = 9;
				}
				else if (nCurrentMap->nField[x][y - 1] == 8) // ���Ϳ� ����
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
				else if (nCurrentMap->nField[x][y + 1] == 6) // �Ʒ��ʸ� �̵�
				{
					nCurrentMap->nField[x][y] = 0;
					nCurrentMap = nCurrentMap->nDownMap;
					x = nCurrentMap->Map_FindEntity(5, 0);
					y = nCurrentMap->Map_FindEntity(5, 1) + 1;
					nCurrentMap->nField[x][y] = 9;
				}
				else if (nCurrentMap->nField[x][y + 1] == 8) // ���Ϳ� ����
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