//#include <iostream>
//#include <string>
//#include "P2_DropManager.h"
//
//// 드랍 테이블 개수 설정
//constexpr int DropTableCount = 5;
//
//// 문자열 -> ClassType 열거형 변환
//ClassType StringToClassType(const std::string& str)
//{
//    if (str == "Warrior") return ClassType::Warrior;
//    if (str == "Sorceress") return ClassType::Sorceress;
//    if (str == "Rogue") return ClassType::Rogue;
//    throw std::invalid_argument("Invalid ClassType");
//}
//
//// 드랍 테이블 생성 및 아이템 추가 반복 -> DropManager에 등록
//void SetupDropTables()
//{
//    for (int id = 1; id <= DropTableCount; ++id)
//    {
//        DropInfo Info(id);
//
//        Info.ClassItemTable[ClassType::Warrior].AddRandom(15, ItemInfo(ItemID::Sword, "Sword"));
//        Info.ClassItemTable[ClassType::Warrior].AddRandom(25, ItemInfo(ItemID::Axe, "Axe"));
//        Info.ClassItemTable[ClassType::Warrior].AddRandom(10, ItemInfo(ItemID::Shield, "Shield"));
//
//        Info.ClassItemTable[ClassType::Sorceress].AddRandom(15, ItemInfo(ItemID::Staff, "Staff"));
//        Info.ClassItemTable[ClassType::Sorceress].AddRandom(25, ItemInfo(ItemID::Wand, "Wand"));
//        Info.ClassItemTable[ClassType::Sorceress].AddRandom(10, ItemInfo(ItemID::Orb, "Orb"));
//
//        Info.ClassItemTable[ClassType::Rogue].AddRandom(15, ItemInfo(ItemID::Dagger, "Dagger"));
//        Info.ClassItemTable[ClassType::Rogue].AddRandom(25, ItemInfo(ItemID::Bow, "Bow"));
//        Info.ClassItemTable[ClassType::Rogue].AddRandom(10, ItemInfo(ItemID::Trap, "Trap"));
//
//        DropManager::Get().AddDropTable(Info);
//    }
//}
//
//int main()
//{
//    SetupDropTables(); // 드랍 테이블 초기화 및 등록
//
//    // 유저 입력 기반 인터랙티브 실행
//    while (true)
//    {
//        std::string dropInput;
//        std::string inputClassType;
//
//        // DropID 입력 받음, 'exit' 입력 시 종료
//        std::cout << "\nEnter DropID (1~" << DropTableCount << ") or 'exit' to quit: ";
//        std::cin >> dropInput;
//
//        if (dropInput == "exit")
//            break;
//
//        int inputDropID;
//        try
//        {
//            // DropID -> 숫자 변환, 실패 시 재입력 요청
//            inputDropID = std::stoi(dropInput);
//        }
//        catch (...)
//        {
//            std::cout << "Invalid DropID input. Please enter a number or 'exit'.\n";
//            continue;
//        }
//
//        // ClassType 입력 받음
//        std::cout << "Enter ClassType (Warrior, Sorceress, Rogue): ";
//        std::cin >> inputClassType;
//
//        try
//        {
//            // 문자열 -> ClassType 변환, 실패 시 재입력 요청
//            ClassType classType = StringToClassType(inputClassType);
//
//            ItemInfo droppedItem;
//            // 입력된 DropID와 ClassType에 맞는 아이템 랜덤 선택 시도
//            bool success = DropManager::Get().GetRandomItem(inputDropID, classType, droppedItem);
//
//            if (success)
//            {
//                std::cout << "Dropped Item: " << droppedItem.GetName()
//                    << " (ID: " << static_cast<int>(droppedItem.GetID()) << ")\n";
//            }
//            else
//            {
//                std::cout << "No item dropped for given DropID and ClassType.\n";
//            }
//        }
//        catch (const std::invalid_argument&)
//        {
//            std::cout << "Invalid ClassType entered. Try again.\n";
//        }
//    }
//
//    std::cout << "Program terminated.\n";
//    return 0;
//}