#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Map.h"
#include "Entity_Monster.h"

using namespace std;

// 생성자
Map::Map(string mapname, int mapcode)
{
	this->nMapName = mapname;
	this->nMapCode = mapcode;
	// 맵 초기화 (2)
	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			nField[x][y] = { 2 };
		}
	}
}
// 상하맵 연결
void Map::LinkUpDowntMap(Map* map ) // map1->LinkUpDownMap(Map2): Up: map2, Down: map1
{
	this->nUpMap = map;
	map->nDownMap = this;
}
// 좌우맵 연결
void Map::LinkRightLeftMap(Map* map) // map1->LinkUpDownMap(Map2): Right: map2, LeftL map1
{
	this->nRightMap = map;
	map->nLeftMap = this;
}
// 맵 테스트
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

// 맵 불러오기
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
			nField[x][y] = { 0 }; // 이동가능지역
			x++;
		}
		else if (Number == 49)
		{
			nField[x][y] = { 1 }; // 이동불가지역
			x++;
		}
		else if (Number == 51)
		{
			nField[x][y] = { 3 }; // 오른쪽맵 이동포탈
			x++;
		}
		else if (Number == 52)
		{
			nField[x][y] = { 4 }; // 왼쪽맵 이동포탈
			x++;
		}
		else if (Number == 53)
		{
			nField[x][y] = { 5 }; // 위쪽맵 이동포탈
			x++;
		}
		else if (Number == 54)
		{
			nField[x][y] = { 6 }; // 아래쪽맵 이동포탈
			x++;
		}
		else if (Number == 56)
		{
			nField[x][y] = { 8 }; // 몬스터
			x++;
		}
		else if (Number == 57)
		{
			nField[x][y] = { 9 }; // 플레이어
			x++;
		}
		else
		{
			nField[x][y] = { 2 }; // 공허
			x++;
		}
	}
	fclose(F);
}

// 플레이어 찾기
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

// 맵에 출몰몬스터 설정
void Map::SetMap_Monster(Monster* monster)
{
	nAppearingMonster.push_back(monster);
}