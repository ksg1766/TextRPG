#pragma once
#include "CreatureGO.h"
class CMonsterGO : public CCreatureGO
{
public:
	CMonsterGO() :CCreatureGO() {}
	CMonsterGO(const char* _szName);
	//virtual void Update() override;

#pragma region Set

#pragma endregion Set

#pragma region Get
#pragma endregion Get

private:
	/*
	int m_iHp;
	int m_iDps;
	int m_iDef;
	int m_iCountComponents;
	Component* m_cComponents[10];
	char m_szName[10];
	*/
};

