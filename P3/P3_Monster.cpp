#include <iostream>
#include <cmath>

#include "P3_Monster.h"

// 정적 멤버 초기화
std::mt19937 Monster::s_RandomEngine{ std::random_device{}() };
std::uniform_real_distribution<float> Monster::s_DirectionDistribution(-3.0f, 3.0f);
std::uniform_real_distribution<float> Monster::s_PositionDistribution(-10.0f, 10.0f);

Monster::Monster(const Vector3& pos, float velocity)
	: Entity(Vector3(s_PositionDistribution(s_RandomEngine),
		0.0f,
		s_PositionDistribution(s_RandomEngine)), velocity)
{
	if (velocity <= 0.f)
	{
		m_Velocity = 1.0f;
	}
}

void Monster::SetPlayerPosition(const Vector3& playerPos)
{
	m_PlayerPos = playerPos;
}

void Monster::Update(float deltaTime)
{
	// 사망 시 업데이트 중단
	if (m_bIsDead) return;

	// 플레이어 반대 방향
	Vector3 toPlayer = m_PlayerPos - m_Pos;
	Vector3 awayDir = toPlayer.Normalize() * -1.0f;
	
	// 랜덤 회피 방향 벡터 생성(x, z 축)
	float randomX = s_DirectionDistribution(s_RandomEngine);
	float randomZ = s_DirectionDistribution(s_RandomEngine);
	
	Vector3 randomDir(randomX, 0.0f, randomZ);

	// 반대 방향과 랜덤 회피를 가중합산 후 정규화
	Vector3 moveDir = (awayDir * 0.2f + randomDir * 0.8f).Normalize();

	// 위치 갱신
	m_Pos += moveDir * m_Velocity * deltaTime;
	m_MoveDir = moveDir;
}

void Monster::Kill()
{
	m_bIsDead = true;
	std::cout << "[LOG] Monster was killed!\n";
}

bool Monster::IsDead() const
{
	return m_bIsDead;
}