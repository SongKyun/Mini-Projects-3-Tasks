#pragma once
#include "P2_ItemID.h"
#include <string>

// 아이템 정보 구조체
struct ItemInfo
{
private:
	ItemID ItemIDValue;		// 고유한 아이템 ID
	std::string ItemName;	// 아이템 이름

public:
	ItemInfo() = default;
	ItemInfo(ItemID InID, const std::string& InName) : ItemIDValue(InID), ItemName(InName) {}

	ItemID GetID() const { return ItemIDValue; }				// 아이템 ID 반환
	const std::string& GetName() const { return ItemName; }		// 아이템 이름 반환
};