#pragma once
#include "P2_DropInfo.h"
#include <unordered_map>

// 드랍 관리를 담당하는 매니저 클래스
class DropManager
{
private:
	std::unordered_map<int, DropInfo> DropTableMap;

public:
	// 싱글톤 인스턴스 반환
	static DropManager& Get()
	{
		static DropManager Instance;
		return Instance;
	}

	// 드랍 테이블 추가
	void AddDropTable(const DropInfo& Info);
	
	// 클래스에 맞는 랜덤 아이템 획득 시도
	bool GetRandomItem(int DropID, ClassType Class, ItemInfo& OutItem);
};