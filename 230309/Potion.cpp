#include "stdafx.h"
#include "Potion.h"
#include "CreatureGO.h"

void CPotion::Use(CCreatureGO* _cCreature)
{
	_cCreature->SetHp(_cCreature->GetHp() + GetProperty());
	cout << GetItemName() << "��(��) ����Ͽ� " << _cCreature << "�� ü���� " << GetProperty() << "��ŭ ȸ���Ǿ����ϴ�.\n";
	system("pause");
}