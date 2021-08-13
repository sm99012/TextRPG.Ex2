#include <iostream>
#include "Map.h"

using namespace std;

// 생성자
Map::Map(string mapname, int mapcode)
{
	this->nMapName = mapname;
	this->nMapCode = mapcode;
}
// 맵 설명
void Map::SetMapDescription(string description)
{
	this->nMapDescription = description;
}
//맵 초기화
void Map::SetMapField(int(*Array)[22])
{
	this->nField = Array;
}
// 왼쪽맵 연결
void Map::LinkeLeftMap(Map* map)
{
	this->nLeftMap = map;
}
// 오른쪽맵 연결
void Map::LinkeRightMap(Map* map)
{
	this->nRightMap = map;
}

// 맵 정보
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

// Field 관련 함수
// 0: 플레이어 이동 가능한 필드
// 1: 플레이어 이동 불가능한 필드
// 2: 플레이어
// 3: 몬스터
// 4: NPC
// 2차원배열 초기화(Field 초기화)
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