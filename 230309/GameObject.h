#pragma once
#include "Component.h"
#include "define.h"

class GameObject
{
public:
	GameObject();
	GameObject(const char* _szName);

	virtual void Update() = 0;

	void SetName(const char* _szName) { strcpy(m_szName, _szName); }
	const char* GetName() const { return m_szName; }

	void AddComponent(Component* _cComponent);
	Component* GetComponent(const char* _szComponent) const;
	virtual ~GameObject() = 0;

protected:
	int m_iCountComponents;
	Component* m_cComponents[10];
	char m_szName[10];
};