#pragma once
int CheckInputRange(int iFloor, int iCeiling);

class CPlayer;
class CField;
class CPet;
class GameManager
{
public:
	explicit GameManager() : player(nullptr), field(nullptr) {}

	bool InitGame();
	void Update();
	~GameManager();

private:
	CPlayer* player;
	CField* field;
};

