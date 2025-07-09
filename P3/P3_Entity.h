#pragma once
#include "P3_Vector3.h"

// ���� ��ü�� ���� �Ӽ��� �⺻ ���� ���� : �߻� Ŭ����
class Entity
{
protected:
	Vector3 m_Pos;
	float m_Velocity;
	bool m_IsDestroyed = false;

public:
	Entity(const Vector3& pos, float velocity);
	virtual ~Entity() = default;

	virtual void Update(float deltaTime) = 0;
	const Vector3& GetPosition() const;
	void Destroy();
	bool IsDestroyed() const;
};