#include "stdafx.h"
#include "Pet.h"
#include "Player.h"

void CPet::Heal(CCreature* _object)
{
	_object->SetHp(_object->GetHp() + 10);
	cout << GetName() << "의 치유 스킬로 체력을 10 회복하였습니다.\n";
}

void CPet::Reviving()
{
	if (m_ReviveCount == 0)	// 소생 가능 횟수 확인
	{
		cout << "소생 스킬 사용 횟수 소진\n";
		return;
	}

	bool isTamerDead = cTamer->GetIsDead();	// 플레이어 상태 확인
	if (isTamerDead)
	{
		cTamer->SetIsDead(isTamerDead);
		--m_ReviveCount;
	}
	else
		cout << "플레이어가 아직 살아있습니다\n";
}

void CPet::Render() const
{
	cout << "\n==============================================================================";
	cout << "\n펫 이름 : " << GetName() << '\n' << "체력 : " << GetHp() << "\t공격력 : " << GetDps() << "\t방어력 : " << GetDef() << "\t남은 소생 스킬 횟수: " << GetRevive();

	if (GetState() == STATE::중독)
		cout << "\n!!!중독 상태입니다!!!";
	cout << "\n==============================================================================";
}

CPet::CPet(const CPet& rhs) 
	: CCreature(rhs.GetName(), rhs.GetHp(), rhs.GetDps(), rhs.GetDef(), false),
		m_iState(rhs.m_iState), m_ReviveCount(rhs.m_ReviveCount), cTamer(rhs.cTamer) {}

void CPet::AddObserver(CObserver* observer)
{
	cObserver = observer;
}

//void CPet::RemoveObserver()
//{
//	SAFE_DELETE(cObserver);
//}

void CPet::NotifyObserver()
{
	cObserver->Update(this);
}

void CPet::NotifyObserver(CBaseCreature* _monster)
{
	cObserver->Update(&GetTamer(), _monster);
}

void CPet::PetSkill(CCreature* _monster)
{
	cout << "1. 펫 공격   2. 플레이어 체력 회복   3. 펫 체력 회복\n";
	int iInput = CheckInputRange(1, 3);
	NotifyObserver(_monster);
	if (iInput == 1)
		Fight(_monster);
	else if (iInput == 2)
		Heal(cTamer);
	else
		Heal(this);
	//NotifyObserver(_monster);
}

void CPet::Fight(CCreature* _monster)
{
	Attack(_monster);

	cout << "펫 공격!\n";
	if (_monster->GetHp() > 0)							// 몬스터가 살아있다면 공격
	{
		if (_monster->GetDps() > GetDef())
			_monster->Attack(this);					// 방어력이 몬스터의 공격력보다 높다면 체력이 회복될 수 있으므로 건너뛰기

		if (!strcmp(_monster->GetName(), "고급"))		// 고급 필드라면 피격 시 중독상태 부여
		{
			if (GetState() == STATE::중독)
				Hit(5);
			else
				SetState(STATE::중독);			// 첫 턴 이후 부터 체력 턴당 5씩 감소
		}

		if (GetHp() <= 0)						// 몬스터는 살아있는데 펫이 죽었다면
		{
			SetHp(0);							// 펫 체력 0으로 고정
			return;
		}
	}
	else										// 몬스터는 죽고 펫이 살아있다면 승리 후 사냥터 선택
	{
		cTamer->AddItems("회복약", 1);
		cout << "회복약을 획득하였습니다.\n\n";
		cout << "승리\n";
		system("pause");
		return;
	}
}

void CPet::SetState(const int& _state)
{
	m_iState = _state;
}

int CPet::GetState() const
{
	return m_iState;
}

int CPet::GetRevive() const
{
	return m_ReviveCount;
}

CPlayer& CPet::GetTamer()
{
	return *cTamer;
}
