#include "stdafx.h"
#include "Potion.h"
#include "CreatureGO.h"

void CPotion::Use(CCreatureGO* _cCreature)
{
	_cCreature->SetHp(_cCreature->GetHp() + GetProperty());
	cout << GetItemName() << "을(를) 사용하여 " << _cCreature << "의 체력이 " << GetProperty() << "만큼 회복되었습니다.\n";
	system("pause");
}