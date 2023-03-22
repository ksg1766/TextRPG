#include "stdafx.h"
#include "Shop.h"
#include "Item.h"
#include "Player.h"

CShop::CShop() : m_iCapacity(10), m_iNumOfItems(0)
{
	memset(m_cItemList, 0, m_iCapacity);
}

CShop::CShop(const CShop& rhs) : m_cPlayer(rhs.m_cPlayer), m_iCapacity(rhs.m_iCapacity), m_iNumOfItems(rhs.m_iNumOfItems)
{
	for (int i = 0; i < rhs.m_iNumOfItems; ++i)
		AddItem(rhs.GetItem(i)->GetItemName(), rhs.GetItem(i)->GetPrice(), rhs.GetItem(i)->GetProperty());
}

CShop::CShop(CCreature* _creature) : m_cPlayer(_creature), m_iCapacity(10), m_iNumOfItems(0)
{
	for (int i = 0; i < m_iNumOfItems; ++i)
		m_cItemList[i] = nullptr;
}

void CShop::Update()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		ShowItems();
		cout << "구매할 아이템의 번호를 선택하세요(이전 단계 : 0): ";
		//iInput = CheckInputRange(1, m_iNumOfItems);
		cin >> iInput;
		if (iInput == 0)
			break;
		BuyItem(m_cPlayer, iInput - 1);
	}
}

void CShop::AddItem(const char* _name, int _price, int _property)
{
	m_cItemList[m_iNumOfItems] = new CItem(_name, _price, _property);
	++m_iNumOfItems;
}

void CShop::SubItem(int _iIndex)
{
	/*for (int i = 0; i < m_iCapacity; ++i)
		if(!strcmp(m_cItemList[i]->GetName(), _name))*/
	delete m_cItemList[_iIndex];
	for (int i = _iIndex; i < m_iNumOfItems - 1; ++i)
		m_cItemList[i] = m_cItemList[i + 1];
	--m_iNumOfItems;
}

void CShop::BuyItem(CCreature* _creature, int _iIndex)
{
	dynamic_cast<CPlayer*>(_creature)->AddItem(m_cItemList[_iIndex]);
	for (int i = _iIndex; i < m_iNumOfItems - 1; ++i)
		m_cItemList[i] = m_cItemList[i + 1];
	--m_iNumOfItems;
}

void CShop::SellItem(CCreature* _creature, int _iIndex)
{
}

const int CShop::GetCapacity() const
{
	return m_iCapacity;
}

const int CShop::GetNumOfItems() const
{
	return m_iNumOfItems;;
}

const CItem* CShop::GetItem(int i) const
{
	return m_cItemList[i];
}