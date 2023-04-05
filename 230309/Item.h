#pragma once
class CCreatureGO;
class CItem
{
public:
	CItem();
	CItem(const CItem& rhs);
	CItem(const char* _name, int _price, int _property);
	virtual ~CItem() {}
	virtual void Use(CCreatureGO* _cCreature) = 0;

	const int GetProperty() const {	return m_iProperty; }
	const int GetPrice() const { return m_iPrice; }
	const char* GetItemName() const { return m_szName; }
	void SetProperty(int _property) { m_iProperty = _property; }
	void SetPrice(int _price) {	m_iPrice = _price; }
	void SetItemName(const char* name) { strcpy_s(m_szName, name); }
	virtual CItem* clone() = 0;
private:
	int m_iProperty;
	int m_iPrice;
	char m_szName[10];
};

