#include "stdafx.h"
#include "StorageComponent.h"
#include "PlayerGO.h"
#include "Item.h"
#include "Shop.h"

void CStorageComponent::InitStorage(GameObject* _cObject)
{
	// �κ��丮�� ������ ��� ������
	m_cObject = _cObject;
	TYPE_COMP(*_cObject, CShop)
	{
		CShop* pShop = dynamic_cast<CShop*>(m_cObject);
		m_vecItemList = pShop->GetItemList();
	}
	TYPE_COMP(*_cObject, CPlayerGO)
	{
		CPlayerGO* pPlayerGO = dynamic_cast<CPlayerGO*>(m_cObject);
		m_vecItemList = pPlayerGO->GetItemList();
	}
	else cerr << "err: CStorageComponent::InitStorage\n";
}

void CStorageComponent::AddItem(CItem* _cItem)
{
	auto FindByName = [&](CItem& _lamComponent) { return _lamComponent.GetItemName() == _cItem->GetItemName(); };
	auto findIt = find_if((*m_vecItemList).begin(), (*m_vecItemList).end(), FindByName);

	if (findIt != (*m_vecItemList).end())
		(*m_vecItemList).push_back(_cItem);
}

void CStorageComponent::SubItem(int _iIndex)
{
	SAFE_DELETE((*m_vecItemList)[_iIndex])
		for (int i = _iIndex; i < (*m_vecItemList).size() - 1; ++i)
			(*m_vecItemList)[i] = (*m_vecItemList)[i + 1];
}

void CStorageComponent::RenderStorage()
{
	// ������ ����(����, ��, �Ҹ�ǰ ��), ���� �ѹ��� ��µǵ��� ���� // �� �Ϸ��� �ߴ� �ɱ� �������� ����;;
	cout << "======================================================================\n";
	if ((*m_vecItemList).size())
		cout << "�������� �����ϴ�.\n";
	for (int i = 0; i < (*m_vecItemList).size(); i++)
		cout << '[' << i + 1 << ']' << " ��ġ :" << (*m_vecItemList)[i]->GetPrice() << "\t������ �̸� : "
		<< (*m_vecItemList)[i]->GetItemName() << "\t���� : " << (*m_vecItemList)[i]->GetProperty() << '\n';
	cout << "======================================================================\n";
	if (typeid(*m_cObject) == typeid(CPlayerGO))
		Use();
}

void CStorageComponent::Use()
{
	cout << "����� �������� �����ϼ���: ";
	int iInput = CheckInputRange(1, m_vecItemList->size());
	(*m_vecItemList)[iInput]->Use(static_cast<CPlayerGO*>(m_cObject));
	SubItem(iInput);
}
