#pragma once
#include "P2_ItemID.h"
#include <string>

// ������ ���� ����ü
struct ItemInfo
{
private:
	ItemID ItemIDValue;		// ������ ������ ID
	std::string ItemName;	// ������ �̸�

public:
	ItemInfo() = default;
	ItemInfo(ItemID InID, const std::string& InName) : ItemIDValue(InID), ItemName(InName) {}

	ItemID GetID() const { return ItemIDValue; }				// ������ ID ��ȯ
	const std::string& GetName() const { return ItemName; }		// ������ �̸� ��ȯ
};