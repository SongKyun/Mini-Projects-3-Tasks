#pragma once
#include "P3_Vector3.h"

// 게임 객체의 공통 속성과 기본 동작 정의 : 추상 클래스
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