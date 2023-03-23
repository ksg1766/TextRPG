#include "stdafx.h"
#include "Shop.h"
#include "Item.h"
#include "PlayerGO.h"
#include "StorageComponent.h"

//CShop::CShop() : m_iCapacity(10), m_iNumOfItems(0)
//{
//	memset(m_cItemList, 0, m_iCapacity);
//	
//	AddComponent(new CStorageComponent());
//}
//
//CShop::CShop(const CShop& rhs) : m_cPlayer(rhs.m_cPlayer), m_iCapacity(rhs.m_iCapacity), m_iNumOfItems(rhs.m_iNumOfItems)
//{
//	for (int i = 0; i < rhs.m_iNumOfItems; ++i)
//		AddItem(rhs.GetItem(i)->GetItemName(), rhs.GetItem(i)->GetPrice(), rhs.GetItem(i)->GetProperty());
//}

CShop::CShop(CPlayerGO* _creature) : m_cPlayer(_creature), m_iCapacity(10), m_iNumOfItems(0)
{
	for (int i = 0; i < m_iNumOfItems; ++i)
		m_cItemList[i] = nullptr;
	
	AddComponent(new CStorageComponent());

	m_cPlayerStorage = static_cast<CStorageComponent*>(static_cast<CPlayerGO*>(_creature)->GetComponent("class CStorageComponent"));
	m_cShopStorage = static_cast<CStorageComponent*>(GetComponent("class CStorageComponent"));
}

void CShop::Update()
{
	while (true)
	{
		system("cls");
		m_cShopStorage->RenderStorage();
		m_cPlayerStorage->RenderStorage();

		cout << "1. 아이템 구매   2. 아이템 판매   3. 이전 단계\n";
		switch (int iInput = CheckInputRange(1, 3))
		{
		case 1:
			cout << "구매할 아이템의 번호를 선택하세요(이전 단계 : 9): ";
			switch (iInput = CheckInputRange(1, 9))
			{
			case 9:
				break;
			default:
				BuyItem(m_cPlayer, iInput - 1);
				break;
			}
			break;
		case 2:
			cout << "판매할 아이템의 번호를 선택하세요(이전 단계 : 9): ";
			switch (iInput = CheckInputRange(1, 9))
			{
			case 9:
				break;
			default:
				SellItem(m_cPlayer, iInput - 1);
				break;
			}
			break;
		case 3:
			return;
		}
	}
}

//void CShop::AddItem(const char* _name, int _price, int _property)
//{
//	m_cItemList[m_iNumOfItems] = new CItem(_name, _price, _property);
//	++m_iNumOfItems;
//}
//
//void CShop::SubItem(int _iIndex)
//{
//	/*for (int i = 0; i < m_iCapacity; ++i)
//		if(!strcmp(m_cItemList[i]->GetName(), _name))*/
//	delete m_cItemList[_iIndex];
//	for (int i = _iIndex; i < m_iNumOfItems - 1; ++i)
//		m_cItemList[i] = m_cItemList[i + 1];
//	--m_iNumOfItems;
//}

void CShop::BuyItem(CPlayerGO* _creature, int _iIndex)
{
	m_cPlayerStorage->AddItem(m_cItemList[_iIndex]);
	m_cShopStorage->SubItem(_iIndex);
}

void CShop::SellItem(CPlayerGO* _creature, int _iIndex)
{
	m_cPlayerStorage->SubItem(_iIndex);
}

const void CShop::ShowItems() const
{
	m_cShopStorage->RenderStorage();
}

const int CShop::GetCapacity() const
{
	return m_iCapacity;
}

int* CShop::GetNumOfItems()
{
	return &m_iNumOfItems;;
}

const CItem* CShop::GetItem(int i) const
{
	return m_cItemList[i];
}