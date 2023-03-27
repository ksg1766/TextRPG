#pragma once
#include "Item.h"

class CWeapon : public CItem
{
public:
	CWeapon();
	CWeapon(const CWeapon& rhs);
	CWeapon(const char* _name, int _price, int _damage);
	virtual void Use(CCreatureGO* _cCreature) = 0;

	~CWeapon() override {};
};