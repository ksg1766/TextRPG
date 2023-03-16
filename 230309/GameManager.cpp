#include "stdafx.h"
#include "GameManager.h"
#include "Inventory.h"
#include "Creature.h"
#include "Player.h"
#include "Field.h"
#include "Pet.h"
//#include "UI.h"

bool GameManager::InitGame()
{
	while (true)
	{
		SAFE_DELETE(player);
		SAFE_DELETE(field);
		system("cls");
		int iClass;
		cout << "==========================================================";
		cout << "\n직업을 선택하세요:   1. 전사   2. 마법사   3. 도적   4. 종료\n";
		iClass = CheckInputRange(1, 4);
		if (iClass == 전사)
			//player = &CPlayer::GetInstance("전사", 120, 10, 5);
			player = new CPlayer("전사", 120, 10, 5);
		else if (iClass == 마법사)
			//player = &CPlayer::GetInstance("마법사", 90, 15, 0);
			player = new CPlayer("마법사", 90, 15, 0);
		else if (iClass == 도적)
			//player = &CPlayer::GetInstance("도적", 100, 12, 1);
			player = new CPlayer("도적", 100, 12, 1);
		else
		{
			SAFE_DELETE(player);
			return false;
		}
		field = new CField(player);

		return true;
	}
}

void GameManager::Update()
{
	while (true)
	{
		system("cls");
		if (player->GetIsDead())	// 플레이어가 사망 상태라면 다시 초기화
			break;
		//if (player->GetState() == STATE::중독)	// 모든 디버프 해제
		//	player->SetState(STATE::정상);
		player->Render();
		if (&(player->GetPet()))
			player->GetPet().Render();
		int iInput;
		cout << "\n1. 사냥터   2. 전 단계(초기화)\n";
		iInput = CheckInputRange(1, 2);
		switch(iInput)
		{
		case 1:
			field->Update();
			break;
		case 2:
			return;
		}
	}
}

GameManager::~GameManager()
{
	SAFE_DELETE(player);
	SAFE_DELETE(field);
}

int CheckInputRange(int iFloor, int iCeiling)
{
	int iInput;
	cin >> iInput;

	while (iInput < iFloor || iInput > iCeiling)
	{
		if (cin.fail())	// 버퍼 초기화
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << '\n';
		}
		cout << "\n잘못된 입력입니다. 다시 선택하세요: ";
		cin >> iInput;
	}
	return iInput;
}