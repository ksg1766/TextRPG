#include "stdafx.h"
#include "MonsterGO.h"
#include "MonsterRenderComponent.h"
#include "MonsterActionComponent.h"
#include "StorageComponent.h"
#include "ObserverComponent.h"
#include "Potion.h"
#include "Mech.h"

CMonsterGO::CMonsterGO(MONSTER _monster)
{
	AddComponent(new CMonsterActionComponent(this));
	AddComponent(new CMonsterRenderComponent(this));
	AddComponent(new CStorageComponent(this));

	CStorageComponent* stcomp = static_cast<CStorageComponent*>(GetComponent(typeid(CStorageComponent)));
	CMonsterActionComponent* accomp = static_cast<CMonsterActionComponent*>(GetComponent(typeid(CMonsterActionComponent)));
	
	CPotion* _cPotion = new CPotion;
	stcomp->AddItem(_cPotion);
	CPotion* _cPotion2 = new CPotion;
	stcomp->AddItem(_cPotion2);

	Safe_Delete(_cPotion);
	Safe_Delete(_cPotion2);

	switch (_monster)
	{
	case MONSTER::¹ßÅº:
	{ SetName("¹ßÅº"); m_iMaxHp = 30; m_iHp = m_iMaxHp; m_iDps = 3; m_iDef = 0; m_state = STATE::NORMAL; accomp->SetMech(MechFunc1); }; break;
	case MONSTER::ºñ¾ÆÅ°½º:
	{ SetName("ºñ¾ÆÅ°½º"); m_iMaxHp = 60; m_iHp = m_iMaxHp; m_iDps = 6; m_iDef = 0; m_state = STATE::NORMAL; accomp->SetMech(MechFunc1); }; break;
	case MONSTER::ÄíÅ©¼¼ÀÌÆ°:
	{ SetName("ÄíÅ©¼¼ÀÌÆ°"); m_iMaxHp = 90; m_iHp = m_iMaxHp; m_iDps = 9; m_iDef = 1; m_state = STATE::NORMAL; accomp->SetMech(MechFunc1); }; break;
	case MONSTER::±èÅÂ¿ø:
	{ SetName("±èÅÂ¿ø"); m_iMaxHp = 500; m_iHp = m_iMaxHp; m_iDps = 30; m_iDef = 5; m_state = STATE::NORMAL; accomp->SetMech(MechFunc2); }; break;
	}
}

void CMonsterGO::InitMonster(MONSTER _monster)
{
	AddComponent(new CMonsterActionComponent(this));
	AddComponent(new CMonsterRenderComponent(this));
	AddComponent(new CStorageComponent(this));

	CStorageComponent* stcomp = static_cast<CStorageComponent*>(GetComponent(typeid(CStorageComponent)));
	CMonsterActionComponent* accomp = static_cast<CMonsterActionComponent*>(GetComponent(typeid(CMonsterActionComponent)));

	stcomp->AddItem(new CPotion());
	stcomp->AddItem(new CPotion());

	switch (_monster)
	{
	case MONSTER::¹ßÅº:
	{ SetName("¹ßÅº"); m_iMaxHp = 30; m_iHp = m_iMaxHp; m_iDps = 3; m_iDef = 0; m_state = STATE::NORMAL; accomp->SetMech(MechFunc1); }; break;
	case MONSTER::ºñ¾ÆÅ°½º:
	{ SetName("ºñ¾ÆÅ°½º"); m_iMaxHp = 60; m_iHp = m_iMaxHp; m_iDps = 6; m_iDef = 0; m_state = STATE::NORMAL; accomp->SetMech(MechFunc1); }; break;
	case MONSTER::ÄíÅ©¼¼ÀÌÆ°:
	{ SetName("ÄíÅ©¼¼ÀÌÆ°"); m_iMaxHp = 90; m_iHp = m_iMaxHp; m_iDps = 9; m_iDef = 1; m_state = STATE::NORMAL; accomp->SetMech(MechFunc1); }; break;
	case MONSTER::±èÅÂ¿ø:
	{ SetName("±èÅÂ¿ø"); m_iMaxHp = 500; m_iHp = m_iMaxHp; m_iDps = 30; m_iDef = 5; m_state = STATE::NORMAL; accomp->SetMech(MechFunc2); }; break;
	}
}

CMonsterGO::~CMonsterGO()
{
	for (CItem* c : m_vecItemList)
		Safe_Delete(c);
}