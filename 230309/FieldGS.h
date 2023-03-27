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

	// if (m_state == STATE::���)	// �ʵ忡�� if (player == ���) �κ�� ��������
	// Player�� LOCATION�� ���� �ٸ� ������Ʈ ��� ȣ���ϵ��� ����
	// �������� �����ؾ��� ��

	// CPlayerActionComponent* pComponent = GetComponent(typeid(CPlayerActionComponent*));
	// Field�� Update���� CPlayerActionComponent�� ȣ���� ��
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