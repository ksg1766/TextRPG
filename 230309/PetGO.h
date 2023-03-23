#pragma once
#include "CreatureGO.h"

class CPlayerGO;
class CPetGO : public CCreatureGO
{
public:
	CPetGO();
	CPetGO(const char* _szName, CPlayerGO* _cPlayer);

#pragma region Set

#pragma endregion Set

#pragma region Get

#pragma endregion Get

private:
	CPlayerGO* m_cTamer;
	/*
	int m_iHp;
	int m_iDps;
	int m_iDef;
	int m_iCountComponents;
	Component* m_cComponents[10];
	char m_szName[10];
	*/
};

