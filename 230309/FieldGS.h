#pragma once
#include "GameScene.h"

class CPlayerGO;
class CMonsterGO;
class CPlayerActionComponent;
class CMonsterActionComponent;
class CStorageComponent;
class CFieldGS : public GameScene
{
public:
	CFieldGS();
	CFieldGS(CPlayerGO* _cPlayer);
	bool InitField(CPlayerGO* _cPlayer);
	void CreateMonster(int _iCase);
	void Update();

	~CFieldGS()
	{
		Safe_Delete(m_cMonster);
	}

private:
	CPlayerGO* m_cPlayer;
	CMonsterGO* m_cMonster;
	//vector<CMonsterGO*> m_vecMonster;

	CPlayerActionComponent* m_cPlayerAction;
	CMonsterActionComponent* m_cMonsterAction;
	CStorageComponent* m_cPlayerStorage;
	
};