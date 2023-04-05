#include "stdafx.h"
#include "GameProcessor.h"
#include "FieldGS.h"
#include "StorageComponent.h"
#include "WeaponShop.h"
#include "ArmorShop.h"
#include "ConsumShop.h"
#include "PlayerRenderComponent.h"
#include "PetRenderComponent.h"
#include "PetGo.h"

bool GameProcessor::InitGame()
{
	cout << "직업을 선택하세요(1. 워로드   2. 소서리스   3. 스카우터   4. 종료) : ";
	int iInput;
	cin >> iInput;
	if (4 == iInput) { m_cPlayer = nullptr; return false; }
	m_cPlayer = new CPlayerGO(static_cast<JOB>(iInput));
	return true;
	// FieldScene 선택 나중에 추가
}

void GameProcessor::Update()
{
	CPlayerRenderComponent* cPlayerRenderComponent = static_cast<CPlayerRenderComponent*>(m_cPlayer->GetComponent(typeid(CPlayerRenderComponent)));
	CPetRenderComponent* cPetRenderComponent = nullptr;
	// 여기 안됨. 여기부터 다시 할 것.

	int iInput;
	CStorageComponent* cPlayerStorage = nullptr;
	CShop* cShop = nullptr;

	while (true)
	{
		system("cls");
		if (!m_cPlayer) exit(1);
		if (m_cPlayer->GetState() == STATE::DEAD) { cout << "좀 더 잘해보지 그랬어요. 모든 데이터가 초기화 됩니다ㅋ.\n"; system("pause"); break; }

		cPlayerRenderComponent->Render();
		if (m_cPlayer->GetPet() != nullptr)
		{
			if (nullptr == cPetRenderComponent)
				cPetRenderComponent = static_cast<CPetRenderComponent*>(m_cPlayer->GetPet()->GetComponent(typeid(CPetRenderComponent)));
			cPetRenderComponent->Render();
		}

		cout << "1. 필드로 이동   2. 인벤토리   3. 상점   4. 전 단계\n";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_cField = new CFieldGS();
			if (!(m_cField->InitField(m_cPlayer)))
				break;
			m_cField->Update();

			Safe_Delete(m_cField);
			break;
		case 2:
			cPlayerStorage = static_cast<CStorageComponent*>(m_cPlayer->GetComponent(typeid(CStorageComponent)));
			cPlayerStorage->RenderStorage();
			cPlayerStorage->Use();
			break;
		case 3:
			cout << "1. 무기 상점(미완성)   2. 방어구 상점(미완성)   3. 소모품 상점(회복약 원툴)   4. 전 단계\n";
			cin >> iInput;
			if (iInput == 4)
				break;
			else if (iInput == 1)
				cShop = new CWeaponShop(m_cPlayer);
			else if (iInput == 2)
				cShop = new CArmorShop(m_cPlayer);
			else if (iInput == 3)
				cShop = new CConsumShop(m_cPlayer);

			cShop->Update();
			break;
		case 4:
			cout << "일부러 알려주지 않았는데, 돌이킬 수 없는 선택이군요. 모든 데이터가 초기화 됩니다ㅋ.\n";
			Safe_Delete(m_cPlayer);
			return;
		}
	}
}