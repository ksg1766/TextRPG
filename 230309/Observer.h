#pragma once

class CBaseCreature;
class CObserver
{
public:
	virtual void Update(CBaseCreature* baseCreature) {}
	virtual void Update(CBaseCreature* _player, CBaseCreature* _monster) {}
};