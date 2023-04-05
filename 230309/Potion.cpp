#include "stdafx.h"
#include "Potion.h"
#include "CreatureGO.h"

CPotion::CPotion()
{
	SetItemName("ȸ����");
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
	cout << GetItemName() << " ��(��) ����Ͽ� " << _cCreature->GetName() << " �� ü���� " << GetProperty() << " ��ŭ ȸ���Ǿ����ϴ�.\n";
}

CItem* CPotion::clone()
{
	return new CPotion(*this);
}
