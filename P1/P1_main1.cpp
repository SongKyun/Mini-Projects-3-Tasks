//#include <iostream>
//#include <iomanip>
//#include <memory>
//
//#include "P1_Skill.h"
//#include "P1_RandomSelector.h"
//
//// �׽�Ʈ �ݺ� Ƚ��
//constexpr int TestCount = 50;
//
//// ��� ��� �Լ�
//void PrintResult(const std::string& SkillName, int Count)
//{
//		std::cout << std::left << std::setw(20) << SkillName << ": " << Count << "\n";
//}
//
//int main()
//{
//	using SkillPtr = std::shared_ptr<Skill>;
//
//	// ��ų ��ü ���� (����Ʈ �����ͷ� �޸� ����)
//	SkillPtr skill1 = std::make_shared<Skill>(SkillID::Fireball, "Fireball");
//	SkillPtr skill2 = std::make_shared<Skill>(SkillID::IceLance, "Ice Lance");
//	SkillPtr skill3 = std::make_shared<Skill>(SkillID::LightningStrike, "Lightning Strike");
//
//	// ���� ���ñ� ��ü ���� (Skill* ���)
//	RandomSelector<Skill*> selector;
//
//	// Ȯ���� ��ų ���(���� 50)
//	selector.AddRandom(15, skill1.get());	// 30%
//	selector.AddRandom(25, skill2.get());	// 50%
//	selector.AddRandom(10, skill3.get());	// 20%
//
//	// ��� ī��Ʈ ����
//	int fireballCount = 0, iceLanceCount = 0, lightningCount = 0;
//
//	// Ȯ�� �׽�Ʈ ����
//	for (int i = 0; i < TestCount; ++i)
//	{
//		Skill* result = nullptr;
//
//		// ��ų �ϳ��� Ȯ���� ���� ����
//		if (selector.GetRandom(result) && result)
//		{
//			switch (result->GetID())
//			{
//				case SkillID::Fireball:			++fireballCount; break;
//				case SkillID::IceLance:			++iceLanceCount; break;
//				case SkillID::LightningStrike:	++lightningCount; break;
//			}
//		}
//	}
//
//	// ��� ���
//	PrintResult("Fireball", fireballCount);
//	PrintResult("Ice Lance", iceLanceCount);
//	PrintResult("Lightning Strike", lightningCount);
//
//	return 0;
//}