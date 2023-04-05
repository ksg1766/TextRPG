#pragma once
#include "Item.h"

class CArmor : public CItem
{
public:
	CArmor();
	CArmor(const CArmor& rhs);
	CArmor(const char* _name, int _price, int _damage);
	virtual ~CArmor() override {};

	virtual void Use(CCreatureGO* _cCreature) {};
	virtual CItem* clone() override { return new CArmor(*this); };
};