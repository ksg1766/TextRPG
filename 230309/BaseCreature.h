#pragma once
#include "Observer.h"

class CBaseCreature
{
public:
	virtual void AddObserver(CObserver* observer) {}
	//virtual void RemoveObserver(CObserver* observer) {}
	//virtual void RemoveObserver() {}
	void RemoveObserver() {}
	virtual void NotifyObserver() {}
	virtual void NotifyObserver(CBaseCreature* _monster) {}

	virtual void Render() const {}
};