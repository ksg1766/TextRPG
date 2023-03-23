#include "stdafx.h"
#include "StorageComponent.h"
#include "PlayerGO.h"
#include "Item.h"
#include "Shop.h"

#define TYPE_COMP(x1, x2) if(typeid(x1) == typeid(x2))
#define TYPE_COMP_STR(x1, x2) if(!strcmp(typeid(x1).name(), x2))

void CStorageComponent::InitStorage(GameObject* _cObject)
{
	// 인벤토리와 상점을 어떻게 묶을까
	m_cObject = _cObject;
	TYPE_COMP(*_cObject, CShop)
	{
		CShop* pShop = dynamic_cast<CShop*>(m_cObject);
		m_iNumOfItems = pShop->GetNumOfItems();
		m_cItemList = pShop->GetItemList();
	}
	TYPE_COMP(*_cObject, CPlayerGO)
	{
		CPlayerGO* pPlayerGO = dynamic_cast<CPlayerGO*>(m_cObject);
		m_iNumOfItems = pPlayerGO->GetNumOfItems();
		m_cItemList = pPlayerGO->GetItemList();
	}
	else cerr << "err: CStorageComponent\n";
}

void CStorageComponent::AddItem(CItem* _cItem)
{
	if (nullptr == m_cItemList[*m_iNumOfItems] && MAX_CAPACITY != *m_iNumOfItems)
	{
		m_cItemList[*m_iNumOfItems] = _cItem;
		++m_iNumOfItems;
	}
}

void CStorageComponent::SubItem(int _iIndex)
{
	SAFE_DELETE(m_cItemList[_iIndex])
		for (int i = _iIndex; i < *m_iNumOfItems - 1; ++i)
			m_cItemList[i] = m_cItemList[i + 1];
	--m_iNumOfItems;
}

void CStorageComponent::RenderStorage() const
{
	// 아이템 종류(무기, 방어구, 소모품 등), 정보 한번에 출력되도록 하자
	cout << "======================================================================\n";
	if (!m_iNumOfItems)
		cout << "아이템이 없습니다.\n";
	for (int i = 0; i < *m_iNumOfItems; i++)
		cout << '[' << i + 1 << ']' << " 가치 :" << m_cItemList[i]->GetPrice() << "\t아이템 이름 : "
		<< m_cItemList[i]->GetItemName() << "\t스탯 : " << m_cItemList[i]->GetProperty() << '\n';
	cout << "======================================================================\n";
}
