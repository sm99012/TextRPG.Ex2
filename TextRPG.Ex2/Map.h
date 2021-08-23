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
	// 0: ÇÃ·¹ÀÌ¾î ÀÌµ¿°¡´ÉÁö¿ª
	// 1: ÇÃ·¹ÀÌ¾î ÀÌµ¿ºÒ°¡Áö¿ª
	// 2: ºóÄ­
	// 3: ¿À¸¥ÂÊ¸Ê Æ÷Å»
	// 4: ¿ÞÂÊ¸Ê Æ÷Å»
	// 5: À§ÂÊ¸Ê Æ÷Å»
	// 6: ¾Æ·¡ÂÊ¸Ê Æ÷Å»
	// 7: NPC
	// 8: ¸ó½ºÅÍ
	// 9: ÇÃ·¹ÀÌ¾î

	Map* nLeftMap = NULL;
	Map* nRightMap = NULL;
	Map* nUpMap = NULL;
	Map* nDownMap = NULL;

	// »ý¼ºÀÚ
	Map(string mapname, int mapcode);
	// »óÇÏ¸Ê ¿¬°á
	void LinkUpDowntMap(Map* map = NULL);
	// ÁÂ¿ì¸Ê ¿¬°á
	void LinkRightLeftMap(Map* map = NULL);

	// ¸Ê ºÒ·¯¿Í¼­ ÀúÀå
	void MapDown(FILE* F);
	// ¸Ê Å×½ºÆ®
	void DisplayMap();
	// ¸Ê¿¡ Ãâ¸ô¸ó½ºÅÍ ¼³Á¤
	void SetMap_Monster(Monster* monster);

	// Æ¯Á¤¿ä¼Ò Ã£±â
	int Map_FindEntity(int Number, int n);

	// ¸Ê Á¤º¸
	void MapInformation();

	// Get(), Set()
	string GetMapName() { return nMapName; }
	void SetMapName(string name) { this->nMapName = name; }
	string GetMapDescription() { return nMapDescription; }
	void SetMapDescription(string description) { this->nMapDescription = description; } 
};