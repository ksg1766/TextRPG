#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p = nullptr;}

#define TYPE_COMP(x1, x2) if(typeid(x1) == typeid(x2))
#define TYPE_COMP_STR(x1, x2) if(!strcmp(typeid(x1).name(), x2))

template<typename T>
void Safe_Delete(T & Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

template<typename T>
void Safe_Delete_Array(T& Temp)
{
	if (Temp)
	{
		delete Temp[];
		Temp = nullptr;
	}
}

typedef enum class GameObjectType
{
	PLAYER,
	MONSTER,
	PET,
	ITEM,
	UTIL
}GOTYPE;

typedef enum class Location
{
	//LOGIN,		// 직업 선택
	LOBBY,		// 던전, 상점, 인벤토리 등 선택
	SHOP,	// 무기, 방어구, 소모품 선택
	DUNGEON,	// 공격 뭐시기뭐시기
}LOCATION;

typedef enum PlayerType
{
	전사 = 1,
	마법사,
	도적,
}JOB;

typedef enum MonsterType
{
	슬라임 = 1,
	스켈레톤,
	머쉬맘,
	김태원,
}MONSTER;

typedef enum class PlayerState
{
	NORMAL,
	BLEEDING,
	DEAD
}STATE;

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