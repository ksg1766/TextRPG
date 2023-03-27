#pragma once
#include "CreatureGO.h"

class CPet;
class CItem;
class CPlayerGO : public CCreatureGO
{
public:
	CPlayerGO();

	void InitPlayer(JOB _job);
	virtual void Update() override;

#pragma region Set

#pragma endregion Set

#pragma region Get
	vector<CItem*>* GetItemList() { return &m_vecItemList; }
#pragma endregion Get

private:
	CPet* m_cPet;
	vector<CItem*> m_vecItemList;
	LOCATION m_location;
	/*
	int m_iHp;
	int m_iDps;
	int m_iDef;

	vector<Component*> m_vecComponents;
	char m_szName[10];
	*/
};

