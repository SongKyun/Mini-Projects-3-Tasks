//#include <iostream>
//#include <iomanip>
//#include <memory>
//
//#include "P1_Skill.h"
//#include "P1_RandomSelector.h"
//
//// 테스트 반복 횟수
//constexpr int TestCount = 50;
//
//// 결과 출력 함수
//void PrintResult(const std::string& SkillName, int Count)
//{
//		std::cout << std::left << std::setw(20) << SkillName << ": " << Count << "\n";
//}
//
//int main()
//{
//	using SkillPtr = std::shared_ptr<Skill>;
//
//	// 스킬 객체 생성 (스마트 포인터로 메모리 관리)
//	SkillPtr skill1 = std::make_shared<Skill>(SkillID::Fireball, "Fireball");
//	SkillPtr skill2 = std::make_shared<Skill>(SkillID::IceLance, "Ice Lance");
//	SkillPtr skill3 = std::make_shared<Skill>(SkillID::LightningStrike, "Lightning Strike");
//
//	// 랜덤 선택기 객체 생성 (Skill* 기반)
//	RandomSelector<Skill*> selector;
//
//	// 확률과 스킬 등록(총합 50)
//	selector.AddRandom(15, skill1.get());	// 30%
//	selector.AddRandom(25, skill2.get());	// 50%
//	selector.AddRandom(10, skill3.get());	// 20%
//
//	// 결과 카운트 변수
//	int fireballCount = 0, iceLanceCount = 0, lightningCount = 0;
//
//	// 확률 테스트 실행
//	for (int i = 0; i < TestCount; ++i)
//	{
//		Skill* result = nullptr;
//
//		// 스킬 하나를 확률에 따라 선택
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
//	// 결과 출력
//	PrintResult("Fireball", fireballCount);
//	PrintResult("Ice Lance", iceLanceCount);
//	PrintResult("Lightning Strike", lightningCount);
//
//	return 0;
//}