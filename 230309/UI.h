#pragma once
#include "Observer.h"

class UI : public CObserver
{// 생성자 소멸자 선언 할 것
	virtual void Update(CBaseCreature* baseCreature) override;
	virtual void Update(CBaseCreature* _player, CBaseCreature* _monster) override;
};