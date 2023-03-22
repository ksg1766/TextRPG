#pragma once
#include "Shop.h"

class CConsumShop : public CShop
{
public:
	CConsumShop();
	CConsumShop(const CConsumShop& rhs);
	CConsumShop(CCreature* _creature);

	virtual const void ShowItems() const override;
};