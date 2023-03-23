#pragma once
#include "define.h"
#include "GameObject.h"

class CItem;
class CPlayerGO;
class CStorageComponent;
class CShop : public GameObject
{
public:
	CShop();
	CShop(const CShop& rhs);
	CShop(CPlayerGO* _creature);

	void Update();
	void BuyItem(CPlayerGO* _creature, int _iIndex);
	void SellItem(CPlayerGO* _creature, int _iIndex);
	const void ShowItems() const;
	virtual ~CShop() 
	{
		for(int i = 0; i < m_iNumOfItems; ++i)
			SAFE_DELETE(m_cItemList[i])
	};

	const int GetCapacity() const;
	int* GetNumOfItems();
	const CItem* GetItem(int i) const;
	CItem** GetItemList() { return m_cItemList; }

protected:
	int m_iCapacity;
	int m_iNumOfItems;
	CItem* m_cItemList[8];
	CPlayerGO* m_cPlayer;

	CStorageComponent* m_cPlayerStorage;
	CStorageComponent* m_cShopStorage;
};