#pragma once
#include "PlayerGO.h"
#include "FieldGS.h"

class GameProcessor
{
public:
	//explicit GameProcessor() : {}
	bool InitGame();
	void Update();
	~GameProcessor()
	{
		Safe_Delete(m_cPlayer);
		Safe_Delete(m_cField);
	}

private:
	CPlayerGO* m_cPlayer;
	CFieldGS* m_cField;
};