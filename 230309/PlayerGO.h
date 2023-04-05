#pragma once
#include "MonsterGO.h"
using namespace std;

class CPetGO;
class CItem;
class CPlayerGO : public CCreatureGO
{
public:
	CPlayerGO(JOB _job);
	CPlayerGO* InitPlayer(JOB _job);

	~CPlayerGO() override;
	//virtual void Update() override;

#pragma region Set
	void SetPet(CMonsterGO* _cTarget);
#pragma endregion Set

#pragma region Get
	CPetGO* GetPet() { return m_cPet; }
	vector<CItem*>* GetItemList() { return &m_vecItemList; }
#pragma endregion Get

private:
	CPetGO* m_cPet;
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

