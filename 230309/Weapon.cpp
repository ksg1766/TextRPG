#include "stdafx.h"
#include "Weapon.h"

CWeapon::CWeapon() : CItem()
{
}

CWeapon::CWeapon(const CWeapon& rhs)
{
	SetItemName(rhs.GetItemName());
	SetProperty(rhs.GetProperty());
	SetPrice(rhs.GetPrice());
}

CWeapon::CWeapon(const char* _name, int _price, int _damage) : CItem(_name, _price, _damage)
{
}