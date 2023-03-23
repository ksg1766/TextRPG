#pragma once
#include "CreatureGO.h"

class CPet;
class CItem;
class CPlayerGO : public CCreatureGO
{
public:
	CPlayerGO() :CCreatureGO(){}
	CPlayerGO(const char* _szName);
	//virtual void Update() override;

#pragma region Set
	void SetNumOfItems(int _num) { m_iNumOfItems = _num; }

#pragma endregion Set

#pragma region Get
	int* GetNumOfItems() { return &m_iNumOfItems; }
	CItem** GetItemList() { return m_cItemList; }
#pragma endregion Get

private:
	CPet* m_cPet;
	int m_iNumOfItems;
	CItem* m_cItemList[8];
	/*
	int m_iHp;
	int m_iDps;
	int m_iDef;
	int m_iCountComponents;
	Component* m_cComponents[10];
	char m_szName[10];
	*/
};

