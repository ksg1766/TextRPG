#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	memset(m_szName, 0, 10 * sizeof(char));
}
GameObject::GameObject(const char* _szName)
{
	strcpy_s(m_szName, _szName);
}

GameObject::~GameObject()
{
	for (Component* c : m_vecComponents)
		Safe_Delete(c);
}

void GameObject::AddComponent(Component* _cComponent)
{
	m_vecComponents.push_back(_cComponent);
}

Component* GameObject::GetComponent(const type_info& typeInfo)
{
	auto FindByType = [&](Component* _cComp) { return typeid(*_cComp) == typeInfo; };
	vector<Component*>::iterator findIt = find_if(m_vecComponents.begin(), m_vecComponents.end(), FindByType);

	if (findIt != m_vecComponents.end())
		return *findIt;
	return nullptr;
}