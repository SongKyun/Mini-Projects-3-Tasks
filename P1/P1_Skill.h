#pragma once
#include <string>
#include "P1_SkillID.h"

// 스킬 클래스 : 고유 ID와 이름을 가짐
class Skill
{
public:
	// 생성자 : ID와 이름 초기화
	Skill(SkillID InID, const std::string& InName) : ID(InID), Name(InName) {}

	// 스킬 ID 반환
	SkillID GetID() const { return ID; }
	// 스킬 이름 반환
	std::string GetName() const { return Name; }

private:
	SkillID ID;			// 스킬 고유 식별자
	std::string Name;	// 스킬 이름
};