#include "stdafx.h"
#include "UI.h"
#include "Player.h"
#include "Pet.h"

void UI::Update(CBaseCreature* baseCreature)
{

}

void UI::Update(CBaseCreature* _player, CBaseCreature* _monster)
{
	system("cls");
	CPlayer* player = dynamic_cast<CPlayer*>(_player);
	player->Render();
	_monster->Render();
	if(&(player->GetPet()))
		player->GetPet().Render();
	cout << '\n';
	/*//CPlayer* player = dynamic_cast<CPlayer*>(baseCreature);
	CPlayer* player = (CPlayer*)baseCreature;
	player->Render();
	CCreature* monster = (CCreature*)baseCreature;
	monster->Render();
	CPet* pet = (CPet*)baseCreature;
	pet->Render();*/
}