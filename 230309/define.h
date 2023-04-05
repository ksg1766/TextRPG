#pragma once

#include "stdafx.h"

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

//int CheckInputRange(int iFloor, int iCeiling)
//{
//	int iInput;
//	cin >> iInput;
//
//	while (iInput < iFloor || iInput > iCeiling)
//	{
//		if (cin.fail())	// ���� �ʱ�ȭ
//		{
//			cin.clear();
//			cin.ignore(INT_MAX, '\n');
//			cout << '\n';
//		}
//		cout << "\n�߸��� �Է��Դϴ�. �ٽ� �����ϼ���: ";
//		cin >> iInput;
//	}
//	return iInput;
//}

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
	//LOGIN,		// ���� ����
	LOBBY,		// ����, ����, �κ��丮 �� ����
	SHOP,	// ����, ��, �Ҹ�ǰ ����
	DUNGEON,	// ���� ���ñ⹹�ñ�
}LOCATION;

typedef enum PlayerType
{
	���ε� = 1,
	�Ҽ�����,
	��ī����,
}JOB;

typedef enum MonsterType
{
	��ź = 1,
	���Ű��,
	��ũ����ư,
	���¿�,
}MONSTER;

typedef enum class PlayerState
{
	NORMAL,
	BLEEDING,
	DEAD
}STATE;