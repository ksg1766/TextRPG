#pragma once
#include "define.h"

class CWeapon;
class CItem;
class CCreature;
class CShop
{
public:
	CShop();
	CShop(const CShop& rhs);
	CShop(CCreature* _creature);

	void Update();
	void AddItem(const char* _name, int _price, int _property);
	void SubItem(int _iIndex);
	void BuyItem(CCreature* _creature, int _iIndex);
	void SellItem(CCreature* _creature, int _iIndex);
	virtual const void ShowItems() const = 0;
	virtual ~CShop() 
	{
		for(int i = 0; i < m_iNumOfItems; ++i)
			SAFE_DELETE(m_cItemList[i])
	};

	const int GetCapacity() const;
	const int GetNumOfItems() const;
	const CItem* GetItem(int i) const;

private:
	int m_iCapacity;
	int m_iNumOfItems;
	CItem* m_cItemList[10];
	CCreature* m_cPlayer;
};