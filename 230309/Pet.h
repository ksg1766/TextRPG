#pragma once
#include "Creature.h"

class CPlayer;
class CPet : public CCreature
{
public:
	CPet() {}
	CPet(CCreature* _monster, CPlayer* _player)
		: CCreature(_monster->GetName(), _monster->GetMaxHp(), _monster->GetDps(), _monster->GetDef()), m_iState(STATE::Á¤»ó), cTamer(_player), m_ReviveCount(1) {}
	CPet(const CPet& rhs);

	void AddObserver(CObserver* observer) override;
	//void RemoveObserver() override;
	void NotifyObserver() override;
	void NotifyObserver(CBaseCreature* _monster) override;

	//void InitPet();
	void PetSkill(CCreature* _monster);
	void Fight(CCreature* _monster);
	void Heal(CCreature* _object);
	void Reviving();
	void Render() const override;

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

