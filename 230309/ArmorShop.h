#pragma once
#include "Shop.h"

class CArmorShop : public CShop
{
public:
	CArmorShop();
	CArmorShop(const CArmorShop& rhs);
	CArmorShop(CCreature* _creature);

	virtual const void ShowItems() const override;
};