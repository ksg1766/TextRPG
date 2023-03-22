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
		monster = new CCreature("초급", 30 * _iCase, 3 * _iCase, 0, false);
	else if (_iCase == 2)
		monster = new CCreature("중급", 30 * _iCase, 3 * _iCase, 0, false);
	else
		monster = new CCreature("고급", 30 * _iCase, 3 * _iCase, 0, false);
}

void CField::Update()
{
	while (true)
	{
		SAFE_DELETE(monster);

		if (player->GetIsDead())	// 플레이어가 사망 상태라면 다시 초기화
			break;
		if (!player)
			break;
		if (player->GetState() == STATE::중독)	// 모든 디버프 해제
			player->SetState(STATE::정상);
		if (&(player->GetPet()))
			player->GetPet().SetState(STATE::정상);

		int iInput;
		system("cls");
		player->Render();
		if (&(player->GetPet()))
			player->GetPet().Render();
		cout << "\n1. 초급   2. 중급   3. 고급   4. 전 단계\n";
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
	// 예정 : 플레이어가 죽어도 펫이 살아있다면 소생할 것인지 묻는 부분 추가 // NotifyObserver 싹 Set 함수로 옮기기
	int iInput;
	bool bHasPet = &(player->GetPet());
	CPet& pet_player = player->GetPet();
	bool bPlayerTurn = true;
	bool bPetTurn = bHasPet;

	while (true)
	{
		player->NotifyObserver(monster);

		if (player->GetIsDead())							// 몬스터는 살아있는데 플레이어가 죽었다면
		{
			cout << "\n플레이어 사망\n";
			//SAFE_DELETE(player)
			system("pause");
			break;
		}

		if (monster->GetIsDead())							// 몬스터는 죽고 플레이어는 살아있다면 승리 후 사냥터 선택
			break;

		if (!bPlayerTurn && !bPetTurn)
		{
			bPlayerTurn = true;
			bPetTurn = bHasPet;
		}

		cout << "1. 전투   2. 인벤토리   3. 도망   4. 길들이기: \n";

		iInput = CheckInputRange(1, 4);
		if (iInput == 1)
		{
			player->NotifyObserver(monster);	//
			if (bPlayerTurn)
				cout << bPlayerTurn << ". 플레이어 공격   ";
			if (bPetTurn)
				cout << bPlayerTurn + bPetTurn << ". 펫 기능   ";
			cout << bPlayerTurn + bPetTurn + 1 << ". 이전\n";

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

			cout << "\n1. 회복약 사용   2. 전투로 돌아가기\n";
			iInput = CheckInputRange(1, 2);
			if (iInput == 1)
			{
				if (!player->GetItemCount())
				{
					cout << "아이템이 없습니다\n";
					system("pause");
					player->CloseInventory();
					continue;
				}

				player->SubItem(0);
				player->SetHp(player->GetHp() + 30);
				cout << "체력이 30 회복되었습니다.";

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

		else if(iInput == 3)												// 도망
			break;															// 도망가기로 했다면 사냥터 선택으로 이동

		else																// 길들이기
		{
			if (monster->GetHp() <= 0.1f * monster->GetMaxHp())
			{
				CPet* cNewPet();
				player->SetPet(monster);
				cout << "길들이기 성공!\n";
				player->GetPet().AddObserver(&UI);
				system("pause");
				break;
			}
			else
			{
				cout << "아직 길들일 수 없습니다.\n";
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
	if (!monster->GetIsDead())												// 몬스터는 죽고 플레이어는 살아있다면 승리 후 사냥터 선택
		return true;
	cout << "\n승리\n";
	system("pause");
	return false;
}

CField::~CField()
{
	Release();
}
