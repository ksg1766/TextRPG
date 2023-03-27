#pragma once
#include "GameScene.h"

class CPlayerGO;
class CMonsterGO;
class CPlayerActionComponent;
class CMonstererActionComponent;
class CStorageComponent;
class CFieldGS : public GameScene
{
public:

	// if (m_state == STATE::사망)	// 필드에서 if (player == 사망) 로비로 나가도록
	// Player의 LOCATION에 따라 다른 컴포넌트 멤버 호출하도록 구현
	// 위에꺼는 무시해야할 듯

	// CPlayerActionComponent* pComponent = GetComponent(typeid(CPlayerActionComponent*));
	// Field의 Update에서 CPlayerActionComponent를 호출할 것
	// Field() 

	CFieldGS(CPlayerGO* _cPlayer);
	void CreateMonster(int _iCase);
	void Update();

	~CFieldGS()
	{
		Safe_Delete(m_cPlayer);
		Safe_Delete(m_cMonster);
	}

private:
	CPlayerGO* m_cPlayer;
	CMonsterGO* m_cMonster;

	CPlayerActionComponent* m_cPlayerAction;
	CMonsterActionComponent* m_cMonsterAction;
	CStorageComponent* m_cPlayerStorage;
	//vector<CMonsterGO*> m_vecMonster;
};