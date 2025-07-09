#include "P2_DropManager.h"

#include <iostream>

// ��� ���̺� �߰�/����
void DropManager::AddDropTable(const DropInfo& Info)
{
	DropTableMap[Info.DropID] = Info;
}

// ���� ������ ��� �õ�
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