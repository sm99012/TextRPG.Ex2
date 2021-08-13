#pragma once
#include <iostream>

using namespace std;

class Map
{
	string nMapName;
	string nMapDescription;
	int nMapCode;
	int(*nField)[22];
	Map* nLeftMap = NULL;
	Map* nRightMap = NULL;

public:
	// ������
	Map(string mapname, int mapcode);
	// �� ����
	void SetMapDescription(string description);
	// ��(�ʵ�) ����(�������迭)
	void SetMapField(int(*Array)[22]);
	// ���ʸ� ����
	void LinkeLeftMap(Map* map = NULL);
	// �����ʸ� ����
	void LinkeRightMap(Map* map = NULL);

	// �� ����
	void MapInformation();
};