#include "stdafx.h"
#include "Item.h"

CItem::CItem() : m_iPrice(0), m_iProperty(0)
{
	::memset(m_szName, 0, 10);
}

CItem::CItem(const CItem& rhs) :m_iProperty(rhs.m_iProperty), m_iPrice(rhs.m_iPrice)
{
	strcpy_s(m_szName, rhs.m_szName);
}

CItem::CItem(const char* _name, int _price, int _property) : m_iPrice(_price), m_iProperty(_property)
{
	strcpy_s(m_szName, _name);
}