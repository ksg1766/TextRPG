#pragma once
#include "Observer.h"

class UI : public CObserver
{// ������ �Ҹ��� ���� �� ��
	virtual void Update(CBaseCreature* baseCreature) override;
	virtual void Update(CBaseCreature* _player, CBaseCreature* _monster) override;
};