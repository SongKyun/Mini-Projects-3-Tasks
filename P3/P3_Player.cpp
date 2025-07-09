#include <iostream>

#include "P3_Player.h"
#include "P3_Monster.h"

Player::Player(const Vector3& pos, float velocity)
	: Entity(pos, velocity)
{
	if (velocity <= 0.f)
	{
		m_Velocity = 1.0f;
	}
}

void Player::Update(float deltaTime)
{
	// 플레이어 고정 상태로 동작 (처리 없음)
}

std::unique_ptr<Missile> Player::FireMissile(Monster* target)
{
	if (!target || target->IsDead()) return nullptr;

	std::cout << "[LOG] Missile fired!\n";
	return std::make_unique<Missile>(m_Pos, m_Velocity, target);
}