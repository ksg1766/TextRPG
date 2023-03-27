#pragma once
#include "CreatureGO.h"
class CMonsterGO : public CCreatureGO
{
public:
	CMonsterGO() :CCreatureGO() {}
	CMonsterGO(MONSTER _monster);

	void InitMonster(MONSTER _monster);
	virtual void Update() override;

#pragma region Set

#pragma endregion Set

#pragma region Get
	vector<CItem*>* GetItemList() { return &m_vecItemList; }
#pragma endregion Get

private:
	vector<CItem*> m_vecItemList;
	/*
	int m_iHp;
	int m_iDps;
	int m_iDef;
	int m_iCountComponents;
	Component* m_cComponents[10];
	char m_szName[10];
	*/
};

