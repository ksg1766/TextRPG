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
		cout << "�������� �����ϴ�.\n";
	else
	{
		for (size_t i = 0; i < (*m_vecItemList).size(); ++i)
			cout << '[' << i + 1 << ']' << " ��ġ :" << ((*m_vecItemList)[i])->GetPrice() << "   ������ �̸� : " << (*m_vecItemList)[i]->GetItemName() << "   ���� : " << (*m_vecItemList)[i]->GetProperty() << '\n';
	}
	cout << "======================================================================\n";
	system("pause");
}

void CStorageComponent::Use()
{
	while (true)
	{
		if ((*m_vecItemList).empty())	{ cout << "�������� �����ϴ�.\n"; system("pause"); return; }
		else
		{
			cout << "����� �������� �����ϼ���(�κ��丮 �ݱ� : 0): ";
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
