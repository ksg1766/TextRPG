#include "stdafx.h"
#include "Item.h"

CItem::CItem() : m_iPrice(0), m_iProperty(0)
{
	::memset(m_szName, 0, 10);
}

CItem::CItem(const CItem& rhs):m_iProperty(rhs.m_iProperty), m_iPrice(rhs.m_iPrice)
{
	strcpy_s(m_szName, rhs.m_szName);
}

CItem::CItem(const char* _name, int _price, int _property) : m_iPrice(_price), m_iProperty(_property)
{
	strcpy_s(m_szName, _name);
}

const int CItem::GetProperty() const
{
	return m_iProperty;
}

const int CItem::GetPrice() const
{
	return m_iPrice;
}

const char* CItem::GetItemName() const
{
	return m_szName;
}

void CItem::SetProperty(int _property)
{
	m_iProperty = _property;
}

void CItem::SetPrice(int _price)
{
	m_iPrice = _price;
}

void CItem::SetItemName(const char* name)
{
	strcpy_s(m_szName, name);
}
