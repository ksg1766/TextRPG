#pragma once
#include "Shop.h"

class CConsumShop : public CShop
{
public:
	CConsumShop();
	CConsumShop(const CConsumShop& rhs);
	CConsumShop(CPlayerGO* _cPlayer);
	virtual ~CConsumShop() override {};
};