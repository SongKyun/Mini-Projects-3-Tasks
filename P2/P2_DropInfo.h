#pragma once
#include "P2_ItemInfo.h"
#include "P2_ClassType.h"
#include "P1_RandomSelector.h"
#include <unordered_map>

// 드랍 테이블 구조체
struct DropInfo
{
	int DropID; // 드랍 테이블 ID

	// 직업별 아이템 드랍 테이블
	std::unordered_map<ClassType, RandomSelector<ItemInfo>> ClassItemTable;
	
	DropInfo() = default;
	DropInfo(int InDropID) : DropID(InDropID) {}
};