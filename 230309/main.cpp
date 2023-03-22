//#define _CRTDBG_MAP_ALLOC
#include "stdafx.h"
//#include <crtdbg.h>

void main()
{
#pragma region
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	//_CrtSetBreakAlloc(246);
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;
#pragma endregion
	GameManager gameManager;
	while (gameManager.InitGame())
		gameManager.Update();
}