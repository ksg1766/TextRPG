#pragma once
#include "Observer.h"

class UI : public CObserver
{// ������ �Ҹ��� ���� �� ��
	void Update(CBaseCreature* baseCreature) override;
	void Update(CBaseCreature* _player, CBaseCreature* _monster) override;
};