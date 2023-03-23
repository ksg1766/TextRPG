#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p = nullptr;}

#define TYPE_COMP(x1, x2) if(typeid(x1) == typeid(x2))
#define TYPE_COMP_STR(x1, x2) if(!strcmp(typeid(x1).name(), x2))

typedef enum class GameObjectType
{
	PLAYER,
	MONSTER,
	PET,
	ITEM,
	UTIL
}GOTYPE;

typedef enum class PlayerClass
{
	전사 = 1,
	마법사,
	도적,
}JOB;

typedef enum class PlayerState
{
	정상,
	출혈,
}STATE;