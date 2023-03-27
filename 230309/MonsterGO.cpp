#include "stdafx.h"
#include "MonsterGO.h"
#include "MonsterRenderComponent.h"
#include "MonsterActionComponent.h"
#include "StorageComponent.h"
#include "ObserverComponent.h"

CMonsterGO::CMonsterGO(MONSTER _monster)
{
	switch (_monster)
	{
	case JOB::����:
	{ SetName("�ʱ�"); m_iMaxHp = 30; m_iHp = m_iMaxHp; m_iDps = 3; m_iDef = 0; m_state = STATE::NORMAL; }; break;
	case JOB::������:
	{ SetName("�߱�"); m_iMaxHp = 60; m_iHp = m_iMaxHp; m_iDps = 6; m_iDef = 0; m_state = STATE::NORMAL; }; break;
	case JOB::����:
	{ SetName("���"); m_iMaxHp = 90; m_iHp = m_iMaxHp; m_iDps = 9; m_iDef = 1; m_state = STATE::NORMAL; }; break;
	}

	AddComponent(new CMonsterActionComponent);
	AddComponent(new CMonsterRenderComponent);
	AddComponent(new CStorageComponent);
}

void CMonsterGO::InitMonster(MONSTER _monster)
{
	switch (_monster)
	{
	case JOB::����:
	{ SetName("�ʱ�"); m_iMaxHp = 30; m_iHp = m_iMaxHp; m_iDps = 3; m_iDef = 0; m_state = STATE::NORMAL; }; break;
	case JOB::������:
	{ SetName("�߱�"); m_iMaxHp = 60; m_iHp = m_iMaxHp; m_iDps = 6; m_iDef = 0; m_state = STATE::NORMAL; }; break;
	case JOB::����:
	{ SetName("���"); m_iMaxHp = 90; m_iHp = m_iMaxHp; m_iDps = 9; m_iDef = 1; m_state = STATE::NORMAL; }; break;
	}

	AddComponent(new CMonsterActionComponent);
	AddComponent(new CMonsterRenderComponent);
	AddComponent(new CStorageComponent);
}
