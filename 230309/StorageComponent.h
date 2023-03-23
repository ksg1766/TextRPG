#pragma once
#include "Component.h"
#define MAX_CAPACITY 20

class CPlayerGO;
class CItem;
class CStorageComponent : public Component
{
public:
	void InitStorage(GameObject* _cObject);

	//virtual void Update() = 0;

	void AddItem(CItem* _cItem);
	void SubItem(int _iIndex);
	void RenderStorage() const;

private:
	GameObject* m_cObject;
	int* m_iNumOfItems;
	CItem** m_cItemList;
};