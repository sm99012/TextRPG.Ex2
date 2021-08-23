#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Monster;

class Map
{
	string nMapName;
	string nMapDescription;
	int nMapCode;

public:
	vector <Monster*> nAppearingMonster;
	int nField[22][22];
	// 0: �÷��̾� �̵���������
	// 1: �÷��̾� �̵��Ұ�����
	// 2: ��ĭ
	// 3: �����ʸ� ��Ż
	// 4: ���ʸ� ��Ż
	// 5: ���ʸ� ��Ż
	// 6: �Ʒ��ʸ� ��Ż
	// 7: NPC
	// 8: ����
	// 9: �÷��̾�

	Map* nLeftMap = NULL;
	Map* nRightMap = NULL;
	Map* nUpMap = NULL;
	Map* nDownMap = NULL;

	// ������
	Map(string mapname, int mapcode);
	// ���ϸ� ����
	void LinkUpDowntMap(Map* map = NULL);
	// �¿�� ����
	void LinkRightLeftMap(Map* map = NULL);

	// �� �ҷ��ͼ� ����
	void MapDown(FILE* F);
	// �� �׽�Ʈ
	void DisplayMap();
	// �ʿ� ������� ����
	void SetMap_Monster(Monster* monster);

	// Ư����� ã��
	int Map_FindEntity(int Number, int n);

	// �� ����
	void MapInformation();

	// Get(), Set()
	string GetMapName() { return nMapName; }
	void SetMapName(string name) { this->nMapName = name; }
	string GetMapDescription() { return nMapDescription; }
	void SetMapDescription(string description) { this->nMapDescription = description; } 
};