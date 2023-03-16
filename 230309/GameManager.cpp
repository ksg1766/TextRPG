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
		cout << "\n������ �����ϼ���:   1. ����   2. ������   3. ����   4. ����\n";
		iClass = CheckInputRange(1, 4);
		if (iClass == ����)
			//player = &CPlayer::GetInstance("����", 120, 10, 5);
			player = new CPlayer("����", 120, 10, 5);
		else if (iClass == ������)
			//player = &CPlayer::GetInstance("������", 90, 15, 0);
			player = new CPlayer("������", 90, 15, 0);
		else if (iClass == ����)
			//player = &CPlayer::GetInstance("����", 100, 12, 1);
			player = new CPlayer("����", 100, 12, 1);
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
		if (player->GetIsDead())	// �÷��̾ ��� ���¶�� �ٽ� �ʱ�ȭ
			break;
		//if (player->GetState() == STATE::�ߵ�)	// ��� ����� ����
		//	player->SetState(STATE::����);
		player->Render();
		if (&(player->GetPet()))
			player->GetPet().Render();
		int iInput;
		cout << "\n1. �����   2. �� �ܰ�(�ʱ�ȭ)\n";
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
		if (cin.fail())	// ���� �ʱ�ȭ
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << '\n';
		}
		cout << "\n�߸��� �Է��Դϴ�. �ٽ� �����ϼ���: ";
		cin >> iInput;
	}
	return iInput;
}