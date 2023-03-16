#pragma once
#include "Creature.h"

class CPet;
class CInventory;
class CPlayer : public CCreature
{
public:
	//static CPlayer& GetInstance(const char* _class, int _hp, int _dps, int _def, const int _state = STATE::정상, bool _isDead = false);
	explicit CPlayer();
	explicit CPlayer(const char* _class, int _maxHp, int _dps, int _def, const int _state = STATE::정상, bool _isDead = false);
	CPlayer(const CPlayer& rhs);

	void AddObserver(CObserver* observer) override;
	//void RemoveObserver() override;
	void NotifyObserver() override;
	void NotifyObserver(CBaseCreature* _monster) override;

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
	void AddItems(const char* _szItemName, int i);
	const char* GetItems(int i) const;

	void Render() const override;

	~CPlayer()
	{
		SAFE_DELETE(cInventory);;
		SAFE_DELETE(cPet);
		//RemoveObserver();
	}

private:
	CObserver* cObserver;
	static CPlayer* cInstance;
	int m_iState;
	int m_iItemCount;
	char m_cItems[10][10];
	CInventory* cInventory;
	CPet* cPet;
};