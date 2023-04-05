#pragma once
#include "stdafx.h"
#include "CreatureGO.h"

void MechFunc1(CCreatureGO* _cMonster, CCreatureGO* _cTarget)
{
	if (_cMonster->GetHp() <= 0)
		return;

	cout << _cMonster->GetName() << "의 공격!\n";
	int iDamage = _cMonster->GetDps() - _cTarget->GetDef();
	if (0 > iDamage)	iDamage = 0;

	_cTarget->SetHp(_cTarget->GetHp() - iDamage);

	if (0 > _cTarget->GetHp())
		_cTarget->SetHp(0);
	system("pause");
}

void MechFunc2(CCreatureGO* _cMonster, CCreatureGO* _cTarget)
{
	int iDamage = 0;
	cout << _cMonster->GetName() << "의 출혈 공격!\n";

	if (_cTarget->GetHp() < _cTarget->GetMaxHp() * 0.3f)
	{
		iDamage = _cMonster->GetDps();
		cout << _cTarget->GetName() << " 의 HP가 30% 미만입니다. 방어력이 무시됩니다.\n";
	}
	else
		iDamage = _cMonster->GetDps() - _cTarget->GetDef();

	if (0 > iDamage)
		iDamage = 0;

	_cTarget->SetState(STATE::BLEEDING);
	_cTarget->SetHp(_cTarget->GetHp() - iDamage);

	if (0 > _cTarget->GetHp())
		_cTarget->SetHp(0);
	system("pause");
}