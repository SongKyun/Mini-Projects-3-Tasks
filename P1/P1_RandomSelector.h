#pragma once
#include <vector>
#include <random>
#include <numeric>

// 템플릿 기반 확률 선택 클래스
template <typename T>
class RandomSelector
{
public:
	// 데이터와 해당 확률(가중치)을 추가
	void AddRandom(int Prob, const T& Data)
	{
		if (Prob <= 0) return;
		m_TotalWeight += Prob;
		m_Entries.emplace_back(Prob, Data);
	}

	// 확률에 따라 하나의 데이터를 선택
	// 선택 실패 시 false 반환
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
	std::vector<std::pair<int, T>> m_Entries;	// (확률, 데이터) 쌍 저장
	int m_TotalWeight = 0;						// 총 확률 합계
};