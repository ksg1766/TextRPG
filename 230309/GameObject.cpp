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

void GameObject::AddComponent(Component* _cComponent)
{
	auto FindByType = [&](Component& _lamComponent) { return typeid(_lamComponent) == typeid(_cComponent); };
	auto findIt = find_if(m_vecComponents.begin(), m_vecComponents.end(), FindByType);

	if (findIt != m_vecComponents.end())
		m_vecComponents.push_back(_cComponent);
}

Component* GameObject::GetComponent(const type_info& typeInfo)
{
	auto FindByType = [&](Component& _lamComponent) { return typeid(_lamComponent) == typeInfo; };
	vector<Component*>::iterator findIt = find_if(m_vecComponents.begin(), m_vecComponents.end(), FindByType);

	if (findIt != m_vecComponents.end())
		return *findIt;
	return nullptr;
}
/*
Component* GameObject::GetComponent(const type_info& typeInfo)
{
	for (int i = 0; i < m_vecComponents.size(); ++i)
		if (typeid(m_vecComponents[i]) == typeInfo)
			return m_vecComponents[i];
	return nullptr;
}
*/