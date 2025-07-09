#pragma once
#include "P3_Entity.h"
#include "P3_Vector3.h"

class Monster;

class Missile : public Entity
{
private:
	Monster* m_Target;					// Ÿ�� ����
	float m_LifeTime = 2.0f;			// �̻��� ����
	Vector3 m_Dir = Vector3(1, 0, 0);	// �ʱ� ����
	float m_Angle = 0.0f;				// ���� ���� (������ ���)

public:
	Missile(const Vector3& pos, float velocity, Monster* target);

	void Update(float deltaTime) override;

	float GetAngle() const { return m_Angle; }
};