#include "P3_Entity.h"

Entity::Entity(const Vector3& pos, float velocity)
	: m_Pos(pos), m_Velocity(velocity) {}

const Vector3& Entity::GetPosition() const
{
	return m_Pos;
}

void Entity::Destroy()
{
	m_IsDestroyed = true;
}

bool Entity::IsDestroyed() const
{
	return m_IsDestroyed;
}