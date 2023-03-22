#pragma once

class CPlayer;
class CInventory
{
public:
	explicit CInventory() : player(nullptr) {}
	explicit CInventory(CPlayer* _player) : player(_player) {}
	explicit CInventory(const CInventory& rhs);

	void ShowPlayerItems() const;
	~CInventory(){}

private:
	CPlayer* player;
};

