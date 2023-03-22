#include "stdafx.h"
#include "Field.h"
#include "Creature.h"
#include "Player.h"
#include "Inventory.h"
#include "Pet.h"
#include "UI.h"

#define IF_MONSTER_ALIVE	if (monster->GetIsDead()) break;

void CField::Initialize() {}

void CField::CreateMonster(int _iCase)
{
	if (_iCase == 1)
		monster = new CCreature("�ʱ�", 30 * _iCase, 3 * _iCase, 0, false);
	else if (_iCase == 2)
		monster = new CCreature("�߱�", 30 * _iCase, 3 * _iCase, 0, false);
	else
		monster = new CCreature("���", 30 * _iCase, 3 * _iCase, 0, false);
}

void CField::Update()
{
	while (true)
	{
		SAFE_DELETE(monster);

		if (player->GetIsDead())	// �÷��̾ ��� ���¶�� �ٽ� �ʱ�ȭ
			break;
		if (!player)
			break;
		if (player->GetState() == STATE::�ߵ�)	// ��� ����� ����
			player->SetState(STATE::����);
		if (&(player->GetPet()))
			player->GetPet().SetState(STATE::����);

		int iInput;
		system("cls");
		player->Render();
		if (&(player->GetPet()))
			player->GetPet().Render();
		cout << "\n1. �ʱ�   2. �߱�   3. ���   4. �� �ܰ�\n";
		iInput = CheckInputRange(1, 4);
		if (iInput != 4)
			CreateMonster(iInput);
		else
			break;
		EnterField();
	}
}

void CField::EnterField()
{
	UI UI;
	player->AddObserver(&UI);
	// ���� : �÷��̾ �׾ ���� ����ִٸ� �һ��� ������ ���� �κ� �߰� // NotifyObserver �� Set �Լ��� �ű��
	int iInput;
	bool bHasPet = &(player->GetPet());
	CPet& pet_player = player->GetPet();
	bool bPlayerTurn = true;
	bool bPetTurn = bHasPet;

	while (true)
	{
		player->NotifyObserver(monster);

		if (player->GetIsDead())							// ���ʹ� ����ִµ� �÷��̾ �׾��ٸ�
		{
			cout << "\n�÷��̾� ���\n";
			//SAFE_DELETE(player)
			system("pause");
			break;
		}

		if (monster->GetIsDead())							// ���ʹ� �װ� �÷��̾�� ����ִٸ� �¸� �� ����� ����
			break;

		if (!bPlayerTurn && !bPetTurn)
		{
			bPlayerTurn = true;
			bPetTurn = bHasPet;
		}

		cout << "1. ����   2. �κ��丮   3. ����   4. ����̱�: \n";

		iInput = CheckInputRange(1, 4);
		if (iInput == 1)
		{
			player->NotifyObserver(monster);	//
			if (bPlayerTurn)
				cout << bPlayerTurn << ". �÷��̾� ����   ";
			if (bPetTurn)
				cout << bPlayerTurn + bPetTurn << ". �� ���   ";
			cout << bPlayerTurn + bPetTurn + 1 << ". ����\n";

			if (bPlayerTurn || bPetTurn)
			{
				iInput = CheckInputRange(1, bPlayerTurn + bPetTurn + 1);
				if (iInput == 1)
				{
					if (bPlayerTurn)
					{
						player->NotifyObserver(monster);
						player->Fight(monster);
						IF_MONSTER_ALIVE
						bPlayerTurn = !bPlayerTurn;
					}

					if (bPetTurn)
					{
						player->NotifyObserver(monster);
						pet_player.PetSkill(monster);
						IF_MONSTER_ALIVE
						bPetTurn = !bPetTurn;
					}
				}
				else if (iInput == 2)
				{
					if (bPetTurn)
					{
						pet_player.PetSkill(monster);
						IF_MONSTER_ALIVE
						bPetTurn = !bPetTurn;
					}
				}
				else
					continue;
			}
		}

		else if (iInput == 2)
		{
			player->LoadInventory()->ShowPlayerItems();

			cout << "\n1. ȸ���� ���   2. ������ ���ư���\n";
			iInput = CheckInputRange(1, 2);
			if (iInput == 1)
			{
				if (!player->GetItemCount())
				{
					cout << "�������� �����ϴ�\n";
					system("pause");
					player->CloseInventory();
					continue;
				}

				player->SubItem(0);
				player->SetHp(player->GetHp() + 30);
				cout << "ü���� 30 ȸ���Ǿ����ϴ�.";

				player->CloseInventory();
				system("pause");
				continue;
			}
			else
			{
				player->CloseInventory();
				continue;
			}
		}

		else if(iInput == 3)												// ����
			break;															// ��������� �ߴٸ� ����� �������� �̵�

		else																// ����̱�
		{
			if (monster->GetHp() <= 0.1f * monster->GetMaxHp())
			{
				CPet* cNewPet();
				player->SetPet(monster);
				cout << "����̱� ����!\n";
				player->GetPet().AddObserver(&UI);
				system("pause");
				break;
			}
			else
			{
				cout << "���� ����� �� �����ϴ�.\n";
				system("pause");
			}
		}
	}
	/*player->RemoveObserver();
	player->GetPet().RemoveObserver();*/
}
//void CField::Render(CPlayer _player, CCreature _monster)
//{
//	_player.Render();
//	_monster.Render();
//}

void CField::Release()
{
	SAFE_DELETE(monster);
}

bool CField::CheckMonsterAlive()
{
	if (!monster->GetIsDead())												// ���ʹ� �װ� �÷��̾�� ����ִٸ� �¸� �� ����� ����
		return true;
	cout << "\n�¸�\n";
	system("pause");
	return false;
}

CField::~CField()
{
	Release();
}
