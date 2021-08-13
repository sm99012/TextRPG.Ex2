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
	// 생성자
	Map(string mapname, int mapcode);
	// 맵 설명
	void SetMapDescription(string description);
	// 맵(필드) 생성(이차원배열)
	void SetMapField(int(*Array)[22]);
	// 왼쪽맵 연결
	void LinkeLeftMap(Map* map = NULL);
	// 오른쪽맵 연결
	void LinkeRightMap(Map* map = NULL);

	// 맵 정보
	void MapInformation();
};