#pragma once
#include "CreatureGO.h"

class CMonsterGO;
class CPlayerGO;
class CPetGO : public CCreatureGO
{
public:
	CPetGO();
	CPetGO(const char* _szName, CPlayerGO* _cPlayer);
	CPetGO(CMonsterGO* _cTarget, CPlayerGO* _cPlayer);

	~CPetGO() override;

#pragma region Set

#pragma endregion Set

#pragma region Get

#pragma endregion Get

private:
	CPlayerGO* m_cTamer;
	// vector<CItem*> m_vecItemList;
	/*
	int m_iHp;
	int m_iDps;
	int m_iDef;
	int m_iCountComponents;
	Component* m_cComponents[10];
	char m_szName[10];
	*/
};

