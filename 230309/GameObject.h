#pragma once
#include "Component.h"
#include "define.h"
#include <vector>
class GameObject
{
public:
	GameObject();
	GameObject(const char* _szName);

	virtual void Update() = 0;

	void SetName(const char* _szName) { strcpy(m_szName, _szName); }
	const char* GetName() const { return m_szName; }

	void AddComponent(Component* _cComponent);
	Component* GetComponent(const type_info& typeInfo);
	//Component* GetComponent(const type_info& typeInfo);
	//Component* GetComponent() const;

	virtual ~GameObject() = 0;

protected:
	vector<Component*> m_vecComponents;
	char m_szName[10];
};