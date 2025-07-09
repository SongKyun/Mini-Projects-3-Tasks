#pragma once
#include <vector>
#include <random>
#include <numeric>

// ���ø� ��� Ȯ�� ���� Ŭ����
template <typename T>
class RandomSelector
{
public:
	// �����Ϳ� �ش� Ȯ��(����ġ)�� �߰�
	void AddRandom(int Prob, const T& Data)
	{
		if (Prob <= 0) return;
		m_TotalWeight += Prob;
		m_Entries.emplace_back(Prob, Data);
	}

	// Ȯ���� ���� �ϳ��� �����͸� ����
	// ���� ���� �� false ��ȯ
	bool GetRandom(T& Data) const
	{
		if (m_Entries.empty() || m_TotalWeight <= 0)
			return false;

		static thread_local std::mt19937 rng{ std::random_device{}() };
		std::uniform_int_distribution<int> dist(1, m_TotalWeight);
		int roll = dist(rng);

		int cumulative = 0;
		for (const auto& entry : m_Entries)
		{
			cumulative += entry.first;
			if (roll <= cumulative)
			{
				Data = entry.second;
				return true;
			}
		}
		
		return false;
	}

private:
	std::vector<std::pair<int, T>> m_Entries;	// (Ȯ��, ������) �� ����
	int m_TotalWeight = 0;						// �� Ȯ�� �հ�
};