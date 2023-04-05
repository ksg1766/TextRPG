#pragma once
#include "GameObject.h"

class CItem;
class CPlayerGO;
class CStorageComponent;
class CShop : public GameObject
{
public:
	//CShop();
	CShop(const CShop& rhs);
	CShop(CPlayerGO* _creature);

	void Update();
	void BuyItem(CPlayerGO* _creature, int _iIndex);
	void SellItem(CPlayerGO* _creature, int _iIndex);
	const void ShowItems() const;
	virtual ~CShop() override;


	const CItem* GetItem(int i) const;
	vector<CItem*>* GetItemList() { return &m_vecItemList; }

protected:
	vector<CItem*> m_vecItemList;
	CPlayerGO* m_cPlayer;

	CStorageComponent* m_cPlayerStorage;
	CStorageComponent* m_cShopStorage;
};