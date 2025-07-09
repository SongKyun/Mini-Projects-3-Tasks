#include <iostream>
#include <cmath>

#include "P3_Monster.h"

// ���� ��� �ʱ�ȭ
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
	// ��� �� ������Ʈ �ߴ�
	if (m_bIsDead) return;

	// �÷��̾� �ݴ� ����
	Vector3 toPlayer = m_PlayerPos - m_Pos;
	Vector3 awayDir = toPlayer.Normalize() * -1.0f;
	
	// ���� ȸ�� ���� ���� ����(x, z ��)
	float randomX = s_DirectionDistribution(s_RandomEngine);
	float randomZ = s_DirectionDistribution(s_RandomEngine);
	
	Vector3 randomDir(randomX, 0.0f, randomZ);

	// �ݴ� ����� ���� ȸ�Ǹ� �����ջ� �� ����ȭ
	Vector3 moveDir = (awayDir * 0.2f + randomDir * 0.8f).Normalize();

	// ��ġ ����
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