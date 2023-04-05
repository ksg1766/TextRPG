#include "stdafx.h"
#include "PlayerActionComponent.h"
#include "PlayerGO.h"
#include "StorageComponent.h"
#include "Item.h"

CPlayerActionComponent::CPlayerActionComponent(CCreatureGO* _cPlayer)
{
	m_cPlayer = static_cast<CPlayerGO*>(_cPlayer);
}

void CPlayerActionComponent::Init(CCreatureGO* _cPlayer)
{
	m_cPlayer = static_cast<CPlayerGO*>(_cPlayer);
}

void CPlayerActionComponent::Attack(CCreatureGO* _cTarget)
{
	if (m_cPlayer->GetHp() <= 0)
		return;

	cout << m_cPlayer->GetName() << "의 공격!\n";
	int iDamage = m_cPlayer->GetDps() - _cTarget->GetDef();
	if (0 > iDamage)	iDamage = 0;

	_cTarget->SetHp(_cTarget->GetHp() - iDamage);

	if (0 >= _cTarget->GetHp())
		_cTarget->SetHp(0);
	system("pause");
}

void CPlayerActionComponent::MiniAttack(CCreatureGO* _cTarget)
{
	if (m_cPlayer->GetHp() <= 0)
		return;

	cout << m_cPlayer->GetName() << "의 살살 때리기!\n";

	_cTarget->SetHp(_cTarget->GetHp() - 1);

	if (0 >= _cTarget->GetHp())
		_cTarget->SetHp(0);
	system("pause");
}

void CPlayerActionComponent::Win(CCreatureGO* _cTarget)
{
	cout << m_cPlayer->GetName() << "의 승리!\n";

	CStorageComponent* cMonsterStorage = static_cast<CStorageComponent*>(_cTarget->GetComponent(typeid(CStorageComponent)));
	CStorageComponent* cPlayerStorage = static_cast<CStorageComponent*>(m_cPlayer->GetComponent(typeid(CStorageComponent)));

	for (vector<CItem*>::iterator it = cMonsterStorage->GetItemList()->begin(); it != cMonsterStorage->GetItemList()->end(); it++)
	{
		cPlayerStorage->AddItem(*it);
		cout << (*it)->GetItemName() << " 획득!\n";
	}
	system("pause");
	/*for (int i = 0; i < cMonsterStorage->GetItemList()->size(); ++i)
		cPlayerStorage->AddItem((*cMonsterStorage->GetItemList())[i]);*/
}

void CPlayerActionComponent::Lose()
{
	cout << "이걸 진다고...? 차라리 접으시는게...ㅎ\n";
	system("pause");
}
//cout << "1. 공격   2. 살살 때리기\n";
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
//	if (!strcmp(_monster->GetName(), "고급"))
//	{
//		if (GetState() == STATE::중독)
//			Hit(0.05f * static_cast<int>(GetMaxHp()));
//		else
//			SetState(STATE::중독);
//	}
//	if (GetHp() <= 0)
//	{
//		SetHp(0);
//		return;
//	}
//}
//else
//{
//	//AddItem("회복약", 1);
//	AddItem(new CItem("회복약", 50, 30));
//	cout << "회복약을 획득하였습니다.\n\n";
//	cout << "승리\n";
//	system("pause");
//	return;
//}