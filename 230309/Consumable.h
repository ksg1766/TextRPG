#pragma once
#include "Item.h"
class CConsumable : public CItem
{
public:
	CConsumable();
	CConsumable(const CConsumable& rhs);
	CConsumable(const char* _name, int _price, int _damage);
	//virtual void Use() override;

	~CConsumable() override {};
};
