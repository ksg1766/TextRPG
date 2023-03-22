#include "stdafx.h"
#include "Armor.h"

CArmor::CArmor() : CItem()
{
}

CArmor::CArmor(const CArmor& rhs)
{
}

CArmor::CArmor(const char* _name, int _price, int _defense) : CItem(_name, _price, _defense)
{
}