#pragma once
#include "Consumable.h"
class CPotion : public CConsumable
{
	CPotion();
	CPotion(const CPotion& rhs);
	CPotion(const char* _name, int _price, int _damage);
	virtual void Use(CCreatureGO* _cCreature) override;
};