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

CShop::CShop(CPlayerGO* _creature) : m_cPlayer(_creature)
{
	AddComponent(new CStorageComponent(this));

	m_cPlayerStorage = static_cast<CStorageComponent*>(m_cPlayer->GetComponent(typeid(CStorageComponent)));
	m_cShopStorage = static_cast<CStorageComponent*>(this->GetComponent(typeid(CStorageComponent)));
}

void CShop::Update()
{
	int iInput;
	while (true)
	{
		system("cls");
		m_cShopStorage->RenderStorage();
		m_cPlayerStorage->RenderStorage();

		cout << "1. 아이템 구매   2. 아이템 판매   3. 이전 단계\n";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			while (true)
			{
				cout << "구매할 아이템의 번호를 선택하세요(이전 단계 : 0): ";
				cin >> iInput;
				if(0 == iInput)	break;
				else			BuyItem(m_cPlayer, iInput - 1);
			}
			break;
		case 2:
			cout << "판매할 아이템의 번호를 선택하세요(이전 단계 : 0): ";
			cin >> iInput;
			switch (iInput)
			{
			case 0:
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

void CShop::BuyItem(CPlayerGO* _creature, int _iIndex)
{
	m_cPlayerStorage->AddItem(m_vecItemList[_iIndex]);
	m_cShopStorage->SubItem(_iIndex);
}

void CShop::SellItem(CPlayerGO* _creature, int _iIndex)
{
	m_cPlayerStorage->SubItem(_iIndex);
}

const void CShop::ShowItems() const
{
	m_cShopStorage->RenderStorage();
	cout << "구매할 아이템의 번호를 선택하세요: ";
}

CShop::~CShop()
{
	Safe_Delete(m_cPlayerStorage);
	Safe_Delete(m_cShopStorage);
	for (CItem* c : m_vecItemList)
		Safe_Delete(c);
}

const CItem* CShop::GetItem(int i) const
{
	return m_vecItemList[i];
}