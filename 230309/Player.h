#pragma once
#include "Creature.h"

class CItem;
class CPet;
class CInventory;
class CPlayer : public CCreature
{
public:
	explicit CPlayer();
	explicit CPlayer(const char* _class, int _maxHp, int _dps, int _def, const int _state = STATE::Á¤»ó, bool _isDead = false);
	CPlayer(const CPlayer& rhs);

	virtual void AddObserver(CObserver* observer) override;
	//void RemoveObserver() override;
	virtual void NotifyObserver() override;
	virtual void NotifyObserver(CBaseCreature* _monster) override;

	void Fight(CCreature* _monster);
	void MiniAttack(CCreature* _monster);

	void SetState(const int& _state);
	int GetState() const;
	
	void SetPet(CCreature* _monster);
	CPet& GetPet();

	CInventory* LoadInventory();
	void CloseInventory();
	void SetItemCount(int i);
	int GetItemCount() const;
	void AddItem(CItem* _cItem);
	void SubItem(int _iIndex);
	const CItem* GetItems(int i) const;

	virtual void Render() const override;

	~CPlayer()
	{
		SAFE_DELETE(cInventory);;
		SAFE_DELETE(cPet);
		for (int i = 0; i < m_iNumOfItems; ++i)
			SAFE_DELETE(m_cItemList[i])
		//RemoveObserver();
	}

private:
	CObserver* cObserver;
	int m_iState;
	int m_iNumOfItems;
	CItem* m_cItemList[20];
	CInventory* cInventory;
	CPet* cPet;
};