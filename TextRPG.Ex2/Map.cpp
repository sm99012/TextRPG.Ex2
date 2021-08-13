#include <iostream>
#include "Map.h"

using namespace std;

// ������
Map::Map(string mapname, int mapcode)
{
	this->nMapName = mapname;
	this->nMapCode = mapcode;
}
// �� ����
void Map::SetMapDescription(string description)
{
	this->nMapDescription = description;
}
//�� �ʱ�ȭ
void Map::SetMapField(int(*Array)[22])
{
	this->nField = Array;
}
// ���ʸ� ����
void Map::LinkeLeftMap(Map* map)
{
	this->nLeftMap = map;
}
// �����ʸ� ����
void Map::LinkeRightMap(Map* map)
{
	this->nRightMap = map;
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
// 2�����迭 �ʱ�ȭ(Field �ʱ�ȭ)
void Map_InitializeArray(int(*Array)[22])
{
	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			Array[x][y] = { 1 };
		}
	}
}