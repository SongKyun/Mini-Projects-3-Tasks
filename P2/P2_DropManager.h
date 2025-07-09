#pragma once
#include "P2_DropInfo.h"
#include <unordered_map>

// ��� ������ ����ϴ� �Ŵ��� Ŭ����
class DropManager
{
private:
	std::unordered_map<int, DropInfo> DropTableMap;

public:
	// �̱��� �ν��Ͻ� ��ȯ
	static DropManager& Get()
	{
		static DropManager Instance;
		return Instance;
	}

	// ��� ���̺� �߰�
	void AddDropTable(const DropInfo& Info);
	
	// Ŭ������ �´� ���� ������ ȹ�� �õ�
	bool GetRandomItem(int DropID, ClassType Class, ItemInfo& OutItem);
};