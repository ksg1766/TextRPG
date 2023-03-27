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

	vector<CItem*>* GetItemList() { return m_vecItemList; }
	void AddItem(CItem* _cItem);
	void SubItem(int _iIndex);
	void RenderStorage();
	void Use();

private:
	vector<CItem*>* m_vecItemList;
	GameObject* m_cObject;
};