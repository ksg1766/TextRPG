#pragma once
#include "Item.h"
class CArmor : public CItem
{
public:
	CArmor();
	CArmor(const CArmor& rhs);
	CArmor(const char* _name, int _price, int _damage);
	//virtual void Use() override;

	virtual ~CArmor() override {};
};