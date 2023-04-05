#include "stdafx.h"
#include "Armor.h"

CArmor::CArmor() : CItem()
{
}

CArmor::CArmor(const CArmor& rhs)
{
	SetItemName(rhs.GetItemName());
	SetProperty(rhs.GetProperty());
	SetPrice(rhs.GetPrice());
}

CArmor::CArmor(const char* _name, int _price, int _defense) : CItem(_name, _price, _defense)
{
}