#include "stdafx.h"
#include "PlayerActionComponent.h"
#include "PlayerGO.h"
#include "StorageComponent.h"
#include "Item.h"

void CPlayerActionComponent::Init(CCreatureGO* _cPlayer)
{
	m_cPlayer = static_cast<CPlayerGO*>(_cPlayer);
}

void CPlayerActionComponent::Attack(CCreatureGO* _cTarget)
{
	cout << m_cPlayer->GetName() << "�� ����!\n";

	_cTarget->SetHp(_cTarget->GetHp() - (m_cPlayer->GetDps() - _cTarget->GetDef()));

	if (0 > _cTarget->GetHp())
		_cTarget->SetHp(0);
	system("pause");
}
void CPlayerActionComponent::Win(CCreatureGO* _cTarget)
{
	cout << m_cPlayer->GetName() << "�� �¸�!\n";

	CStorageComponent* cMonsterStorage = static_cast<CStorageComponent*>(_cTarget->GetComponent(typeid(CStorageComponent)));
	CStorageComponent* cPlayerStorage = static_cast<CStorageComponent*>(m_cPlayer->GetComponent(typeid(CStorageComponent)));

	for (vector<CItem*>::iterator it = cMonsterStorage->GetItemList()->begin(); it != cMonsterStorage->GetItemList()->end(); it++)
	{
		cPlayerStorage->AddItem(*it);
		cout << (*it)->GetItemName() << " ȹ��!\n";
	}
	system("pause");
	/*for (int i = 0; i < cMonsterStorage->GetItemList()->size(); ++i)
		cPlayerStorage->AddItem((*cMonsterStorage->GetItemList())[i]);*/
}

void CPlayerActionComponent::Lose()
{
	cout << "���\n";
	system("pause");
}
//cout << "1. ����   2. ��� ������\n";
//int iInput = CheckInputRange(1, 2);
//if (iInput == 1)
//Attack(_monster);
//else
//MiniAttack(_monster);
//
//if (_monster->GetHp() > 0)
//{
//	if (_monster->GetDps() > GetDef())
//		_monster->Attack(this);
//
//	if (!strcmp(_monster->GetName(), "���"))
//	{
//		if (GetState() == STATE::�ߵ�)
//			Hit(0.05f * static_cast<int>(GetMaxHp()));
//		else
//			SetState(STATE::�ߵ�);
//	}
//	if (GetHp() <= 0)
//	{
//		SetHp(0);
//		return;
//	}
//}
//else
//{
//	//AddItem("ȸ����", 1);
//	AddItem(new CItem("ȸ����", 50, 30));
//	cout << "ȸ������ ȹ���Ͽ����ϴ�.\n\n";
//	cout << "�¸�\n";
//	system("pause");
//	return;
//}