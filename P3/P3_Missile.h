#pragma once
#include "P3_Entity.h"
#include "P3_Vector3.h"

class Monster;

class Missile : public Entity
{
private:
	Monster* m_Target;					// 타겟 몬스터
	float m_LifeTime = 2.0f;			// 미사일 수명
	Vector3 m_Dir = Vector3(1, 0, 0);	// 초기 방향
	float m_Angle = 0.0f;				// 현재 각도 (디버깅용 출력)

public:
	Missile(const Vector3& pos, float velocity, Monster* target);

	void Update(float deltaTime) override;

	float GetAngle() const { return m_Angle; }
};