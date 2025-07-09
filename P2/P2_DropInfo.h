#pragma once
#include "P2_ItemInfo.h"
#include "P2_ClassType.h"
#include "P1_RandomSelector.h"
#include <unordered_map>

// ��� ���̺� ����ü
struct DropInfo
{
	int DropID; // ��� ���̺� ID

	// ������ ������ ��� ���̺�
	std::unordered_map<ClassType, RandomSelector<ItemInfo>> ClassItemTable;
	
	DropInfo() = default;
	DropInfo(int InDropID) : DropID(InDropID) {}
};