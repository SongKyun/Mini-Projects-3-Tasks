#pragma once
#include <memory>

#include "P3_Entity.h"
#include "P3_Missile.h"

class Monster;

class Player : public Entity
{
public:
	Player(const Vector3& pos, float velocity);
	
	void Update(float deltaTime) override;

	std::unique_ptr<Missile> FireMissile(Monster* target);
};