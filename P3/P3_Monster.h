#pragma once
#include <random>

#include "P3_Entity.h"

class Monster : public Entity
{
private:
	bool m_bIsDead = false;
	Vector3 m_PlayerPos;
	Vector3 m_MoveDir;

	// 정적 난수 엔진 및 분포
	static std::mt19937 s_RandomEngine;
	static std::uniform_real_distribution<float> s_DirectionDistribution;
	static std::uniform_real_distribution<float> s_PositionDistribution;

public:
	Monster(const Vector3& pos, float velocity);
	void Update(float deltaTime) override;

	void SetPlayerPosition(const Vector3& playerPos);
	void Kill();
	bool IsDead() const;
};