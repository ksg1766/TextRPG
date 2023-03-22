#pragma once
#include "Shop.h"

class CWeaponShop : public CShop
{
public:
	CWeaponShop();
	CWeaponShop(const CWeaponShop& rhs);
	CWeaponShop(CCreature* _creature);
	virtual ~CWeaponShop() override;

	virtual const void ShowItems() const override;
};