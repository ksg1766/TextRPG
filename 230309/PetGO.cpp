#include "stdafx.h"
#include "PetGO.h"
#include "PlayerGO.h"

CPetGO::CPetGO() :CCreatureGO(), m_cTamer(nullptr) {}
CPetGO::CPetGO(const char* _szName, CPlayerGO* _cPlayer): CCreatureGO(), m_cTamer(_cPlayer) {}