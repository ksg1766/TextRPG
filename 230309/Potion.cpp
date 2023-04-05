#include "stdafx.h"
#include "Potion.h"
#include "CreatureGO.h"

CPotion::CPotion()
{
	SetItemName("회복약");
	SetPrice(10);
	SetProperty(30);
}

CPotion::CPotion(const CPotion& rhs)
{
	SetItemName(rhs.GetItemName());
	SetProperty(rhs.GetProperty());
	SetPrice(rhs.GetPrice());
}

CPotion::CPotion(const char* _name, int _price, int _property) : CConsumable(_name, _price, _property) {}

void CPotion::Use(CCreatureGO* _cCreature)
{
	_cCreature->SetHp(_cCreature->GetHp() + GetProperty());
	cout << GetItemName() << " 을(를) 사용하여 " << _cCreature->GetName() << " 의 체력이 " << GetProperty() << " 만큼 회복되었습니다.\n";
}

CItem* CPotion::clone()
{
	return new CPotion(*this);
}
