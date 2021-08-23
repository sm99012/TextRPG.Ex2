#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Map.h"
#include "Entity_Monster.h"

using namespace std;

// ������
Map::Map(string mapname, int mapcode)
{
	this->nMapName = mapname;
	this->nMapCode = mapcode;
	// �� �ʱ�ȭ (2)
	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			nField[x][y] = { 2 };
		}
	}
}
// ���ϸ� ����
void Map::LinkUpDowntMap(Map* map ) // map1->LinkUpDownMap(Map2): Up: map2, Down: map1
{
	this->nUpMap = map;
	map->nDownMap = this;
}
// �¿�� ����
void Map::LinkRightLeftMap(Map* map) // map1->LinkUpDownMap(Map2): Right: map2, LeftL map1
{
	this->nRightMap = map;
	map->nLeftMap = this;
}
// �� �׽�Ʈ
void Map::DisplayMap()
{
	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			if (nField[x][y] == 0)
			{
				cout << "\u25a1";
			}
			else if (nField[x][y] == 1)
			{
				cout << "\u25a0";
			}
			else if (nField[x][y] == 2)
			{
				cout << "  ";
			}
			else if (nField[x][y] == 3 || nField[x][y] == 4 || nField[x][y] == 5 || nField[x][y] == 6)
			{
				cout << "\u25a3";
			}
			else if (nField[x][y] == 7)
			{
				cout << "\u25c7";
			}
			else if (nField[x][y] == 8)
			{
				cout << "\u25c6";
			}
			else if (nField[x][y] == 9)
			{
				cout << "\u25c8";
			}
		}
		cout << endl;
	}
}
// �� ����
void Map::MapInformation()
{
	cout << "[" << nMapName << "][" << nMapCode << "][" << nMapDescription << "]" << endl;
	if (nLeftMap != NULL)
		cout << "LeftMap: " << nLeftMap->nMapName << ", ";
	else
		cout << "LeftMap: " << "X" << ", ";
	if (nRightMap != NULL)
		cout << "RightMap: " << nRightMap->nMapName << endl;
	else
		cout << "RightMap: " << "X" << endl;
}

// Field ���� �Լ�
// 0: �÷��̾� �̵� ������ �ʵ�
// 1: �÷��̾� �̵� �Ұ����� �ʵ�
// 2: �÷��̾�
// 3: ����
// 4: NPC

// �� �ҷ�����
void Map::MapDown(FILE* F)
{
	int Number = 49;
	int x = 0;
	int y = 0;
	while (Number != 46)
	{
		Number = fgetc(F);
		if (Number == 46) { break; }
		if (Number == 10)
		{
			y++;
			x = 0;
		}
		else if (Number == 48)
		{
			nField[x][y] = { 0 }; // �̵���������
			x++;
		}
		else if (Number == 49)
		{
			nField[x][y] = { 1 }; // �̵��Ұ�����
			x++;
		}
		else if (Number == 51)
		{
			nField[x][y] = { 3 }; // �����ʸ� �̵���Ż
			x++;
		}
		else if (Number == 52)
		{
			nField[x][y] = { 4 }; // ���ʸ� �̵���Ż
			x++;
		}
		else if (Number == 53)
		{
			nField[x][y] = { 5 }; // ���ʸ� �̵���Ż
			x++;
		}
		else if (Number == 54)
		{
			nField[x][y] = { 6 }; // �Ʒ��ʸ� �̵���Ż
			x++;
		}
		else if (Number == 56)
		{
			nField[x][y] = { 8 }; // ����
			x++;
		}
		else if (Number == 57)
		{
			nField[x][y] = { 9 }; // �÷��̾�
			x++;
		}
		else
		{
			nField[x][y] = { 2 }; // ����
			x++;
		}
	}
	fclose(F);
}

// �÷��̾� ã��
int Map::Map_FindEntity(int Number, int n)
{
	bool isEnd = false;
	int nx; int ny;
	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			if (nField[x][y] == Number)
			{
				nx = x; ny = y;
				isEnd = true;
				break;
			}
		}
		if (isEnd == true) break;
	}
	if (n == 0) return nx;
	else if (n == 1) return ny;
}

// �ʿ� ������� ����
void Map::SetMap_Monster(Monster* monster)
{
	nAppearingMonster.push_back(monster);
}