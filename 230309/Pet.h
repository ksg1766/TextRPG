#pragma once
#include "Creature.h"

class CPlayer;
class CPet : public CCreature
{
public:
	CPet() : CCreature(), m_iState(STATE::정상), cTamer(nullptr), m_ReviveCount(0), cObserver(nullptr) {}
	CPet(CCreature* _monster, CPlayer* _player)
		: CCreature(_monster->GetName(), _monster->GetMaxHp(), _monster->GetDps(), _monster->GetDef()), m_iState(STATE::정상), cTamer(_player), m_ReviveCount(1), cObserver(nullptr){}
	CPet(const CPet& rhs);

	virtual void AddObserver(CObserver* observer) override;
	//void RemoveObserver() override;
	virtual void NotifyObserver() override;
	virtual void NotifyObserver(CBaseCreature* _monster) override;

	//void InitPet();
	void PetSkill(CCreature* _monster);
	void Fight(CCreature* _monster);
	void Heal(CCreature* _object);
	void Reviving();
	virtual void Render() const override;

	void SetState(const int& _state);
	int GetState() const;
	int GetRevive() const;

	CPlayer& GetTamer();

	~CPet() { SAFE_DELETE(cTamer); }

private:
	CObserver* cObserver;
	int m_iState;
	int m_ReviveCount;
	CPlayer* cTamer;
};

