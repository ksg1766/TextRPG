#pragma once
#include "Item.h"

class CWeapon : public CItem
{
public:
	CWeapon();
	CWeapon(const CWeapon& rhs);
	CWeapon(const char* _name, int _price, int _damage);
	virtual ~CWeapon() override {};

	virtual void Use(CCreatureGO* _cCreature) {};
	virtual CItem* clone() override { return new CWeapon(*this); };
};