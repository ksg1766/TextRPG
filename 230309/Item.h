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

	const int GetProperty() const;
	const int GetPrice() const;
	const char* GetItemName() const;
	void SetProperty(int _property);
	void SetPrice(int _price);
	void SetItemName(const char* name);

private:
	int m_iProperty;
	int m_iPrice;
	char m_szName[10];
};

