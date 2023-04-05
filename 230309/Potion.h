#pragma once
#include "Consumable.h"
class CPotion : public CConsumable
{
public:
	CPotion();
	CPotion(const CPotion& rhs);
	CPotion(const char* _name, int _price, int _damage);
	virtual ~CPotion() override {};

	virtual void Use(CCreatureGO* _cCreature) override;
	virtual CItem* clone() override;
};