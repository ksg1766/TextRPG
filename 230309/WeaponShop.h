#pragma once
#include "Shop.h"

class CWeaponShop : public CShop
{
public:
	CWeaponShop();
	CWeaponShop(const CWeaponShop& rhs);
	CWeaponShop(CPlayerGO* _creature);
	virtual ~CWeaponShop() override {};
};