#pragma once
#include "Component.h"
#include "define.h"
#include <vector>
using namespace std;

class GameObject
{
public:
	GameObject();
	GameObject(const char* _szName);
	virtual ~GameObject();

	virtual void Update() {};

	void SetName(const char* _szName) { strcpy_s(m_szName, _szName); }

	const char* GetName() const { return m_szName; }

	void AddComponent(Component* _cComponent);
	Component* GetComponent(const type_info& typeInfo);


protected:
	vector<Component*> m_vecComponents;
	char m_szName[12];
};