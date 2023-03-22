#include "stdafx.h"
#include "Consumable.h"

CConsumable::CConsumable()
{
}

CConsumable::CConsumable(const CConsumable& rhs)
{
}

CConsumable::CConsumable(const char* _name, int _price, int _property) : CItem(_name, _price, _property)
{
}