#include "stdafx.h"
#include "StorageComponent.h"
#include "PlayerGO.h"
#include "MonsterGO.h"
#include "Item.h"
#include "Shop.h"
#include <algorithm>

CStorageComponent::CStorageComponent(GameObject* _cObject)
{
	m_cObject = _cObject;
	TYPE_COMP(*_cObject, CShop)			m_vecItemList = static_cast<CShop*>(m_cObject)->GetItemList();
	TYPE_COMP(*_cObject, CPlayerGO)		m_vecItemList = static_cast<CPlayerGO*>(m_cObject)->GetItemList();
	TYPE_COMP(*_cObject, CMonsterGO)	m_vecItemList = static_cast<CMonsterGO*>(m_cObject)->GetItemList();
	system("pause");
}

void CStorageComponent::InitStorage(GameObject* _cObject)
{
	m_cObject = _cObject;
	TYPE_COMP(*_cObject, CShop)			m_vecItemList = static_cast<CShop*>(m_cObject)->GetItemList();
	TYPE_COMP(*_cObject, CPlayerGO)		m_vecItemList = static_cast<CPlayerGO*>(m_cObject)->GetItemList();
}

void CStorageComponent::AddItem(CItem* _cItem)
{
	(*m_vecItemList).push_back(_cItem->clone());
}

void CStorageComponent::SubItem(int _iIndex)
{
	(*m_vecItemList).erase((*m_vecItemList).begin() + _iIndex);
}

void CStorageComponent::RenderStorage()
{
	cout << "======================================================================\n";
	if ((*m_vecItemList).empty())
		cout << "아이템이 없습니다.\n";
	else
	{
		for (size_t i = 0; i < (*m_vecItemList).size(); ++i)
			cout << '[' << i + 1 << ']' << " 가치 :" << ((*m_vecItemList)[i])->GetPrice() << "   아이템 이름 : " << (*m_vecItemList)[i]->GetItemName() << "   스탯 : " << (*m_vecItemList)[i]->GetProperty() << '\n';
	}
	cout << "======================================================================\n";
	system("pause");
}

void CStorageComponent::Use()
{
	while (true)
	{
		if ((*m_vecItemList).empty())	{ cout << "아이템이 없습니다.\n"; system("pause"); return; }
		else
		{
			cout << "사용할 아이템을 선택하세요(인벤토리 닫기 : 0): ";
			int iInput;
			cin >> iInput;
			if (0 == iInput)
				return;
			(*m_vecItemList)[iInput - 1]->Use(static_cast<CPlayerGO*>(m_cObject));
			SubItem(iInput - 1);
			system("pause");
		}
	}
}
