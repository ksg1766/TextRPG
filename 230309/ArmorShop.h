#pragma once
#include "Shop.h"

class CArmorShop : public CShop
{
public:
	CArmorShop();
	CArmorShop(const CArmorShop& rhs);
	CArmorShop(CPlayerGO* _cPlayer);
	virtual ~CArmorShop() override {};
};