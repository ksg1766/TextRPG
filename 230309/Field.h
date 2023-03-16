#pragma once

class CPlayer;
class CCreature;
class CPet;
class CField
{
public:
	CField();
	CField(CPlayer* _player);

	void Initialize();
	void CreateMonster(int _iCase);
	void Update();
	void EnterField();
	//void Render(CPlayer _player, CCreature _monster);
	void Release();
	bool CheckMonsterAlive();

	~CField();
private:
	CPlayer* player;
	CCreature* monster;
};