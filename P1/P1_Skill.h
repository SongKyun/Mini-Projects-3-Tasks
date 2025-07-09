#pragma once
#include <string>
#include "P1_SkillID.h"

// ��ų Ŭ���� : ���� ID�� �̸��� ����
class Skill
{
public:
	// ������ : ID�� �̸� �ʱ�ȭ
	Skill(SkillID InID, const std::string& InName) : ID(InID), Name(InName) {}

	// ��ų ID ��ȯ
	SkillID GetID() const { return ID; }
	// ��ų �̸� ��ȯ
	std::string GetName() const { return Name; }

private:
	SkillID ID;			// ��ų ���� �ĺ���
	std::string Name;	// ��ų �̸�
};