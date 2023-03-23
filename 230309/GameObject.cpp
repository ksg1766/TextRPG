#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() : m_iCountComponents(0)
{
	for (int i = 0; i < 10; ++i)
		m_cComponents[i] = nullptr;
	memset(m_szName, 0, 10 * sizeof(char));
}
GameObject::GameObject(const char* _szName) : m_iCountComponents(0)
{
	for (int i = 0; i < 10; ++i)
		m_cComponents[i] = nullptr;
	strcpy_s(m_szName, _szName);
}

void GameObject::AddComponent(Component* _cComponent)
{
	if (!m_cComponents[m_iCountComponents])
		m_cComponents[m_iCountComponents] = _cComponent;
	++m_iCountComponents;
}

Component* GameObject::GetComponent(const char* _szComponent) const
{
	for (const Component* c : m_cComponents) {
		if (!strcmp(typeid(*c).name(), _szComponent)) {
			return c;
		}
	}
	return nullptr;
}