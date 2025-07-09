#include <iostream>
#include <cmath>

#include "P3_Missile.h"
#include "P3_Monster.h"

Missile::Missile(const Vector3& pos, float velocity, Monster* target)
	: Entity(pos, velocity), m_Target(target)
{
	if (!target)
	{
		std::cerr << "[Error] Missile target is nullptr!\n";
		Destroy();
		return;
	}
		// �ʱ� ������ ���� �������� ����
		m_Dir = (m_Target->GetPosition() - pos).Normalize();
		float dot = Vector3::Dot(Vector3(1, 0, 0), m_Dir);
		dot = Vector3::Clamp(dot, -1.0f, 1.0f);
		m_Angle = Vector3::RadiansToDegrees(std::acos(dot));
}

void Missile::Update(float deltaTime)
{
	if (m_IsDestroyed || !m_Target || m_Target->IsDestroyed())
	{
		Destroy();
		return;
	}

	Vector3 toTarget = (m_Target->GetPosition() - m_Pos).Normalize();

	// ���� ����� ��ǥ ���� ���� ���� ���
	float dot = Vector3::Dot(m_Dir, toTarget);
	dot = Vector3::Clamp(dot, -1.0f, 1.0f); // acos ������ ���� ó��
	float angleRad = std::acos(dot);
	m_Angle = Vector3::RadiansToDegrees(angleRad);

	// ȸ�� ���� (LERP)
	float rotateSpeed = 5.0f; // rad/sec
	float t = rotateSpeed * deltaTime;
	m_Dir = (m_Dir * (1 - t) + toTarget * t).Normalize();

	// �̵�
	m_Pos += m_Dir * m_Velocity * deltaTime;
	
	// ��ǥ�� ��������� ����
	if (m_Pos.DistanceTo(m_Target->GetPosition()) < 0.5f)
	{
		if (!m_Target->IsDead())
		{
			m_Target->Kill();
		}
		Destroy();
		return;
	}

	// ���� üũ
	m_LifeTime -= deltaTime;
	if (m_LifeTime <= 0.0f)
	{
		std::cout << "[LOG] Missile lifetime expired. Missed the target.\n";
		Destroy();
		return;
	}
}