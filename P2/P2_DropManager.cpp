#include "P2_DropManager.h"

#include <iostream>

// 드랍 테이블 추가/갱신
void DropManager::AddDropTable(const DropInfo& Info)
{
	DropTableMap[Info.DropID] = Info;
}

// 랜덤 아이템 드랍 시도
bool DropManager::GetRandomItem(int DropID, ClassType Class, ItemInfo& OutItem)
{
	auto Found = DropTableMap.find(DropID);
	if (Found == DropTableMap.end())
		return false;

	const DropInfo& Info = Found->second;

	auto ClassTableIt = Info.ClassItemTable.find(Class);
	if (ClassTableIt == Info.ClassItemTable.end())
		return false;

	return ClassTableIt->second.GetRandom(OutItem);
}