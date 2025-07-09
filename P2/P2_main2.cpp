//#include <iostream>
//#include <string>
//#include "P2_DropManager.h"
//
//// ��� ���̺� ���� ����
//constexpr int DropTableCount = 5;
//
//// ���ڿ� -> ClassType ������ ��ȯ
//ClassType StringToClassType(const std::string& str)
//{
//    if (str == "Warrior") return ClassType::Warrior;
//    if (str == "Sorceress") return ClassType::Sorceress;
//    if (str == "Rogue") return ClassType::Rogue;
//    throw std::invalid_argument("Invalid ClassType");
//}
//
//// ��� ���̺� ���� �� ������ �߰� �ݺ� -> DropManager�� ���
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
//    SetupDropTables(); // ��� ���̺� �ʱ�ȭ �� ���
//
//    // ���� �Է� ��� ���ͷ�Ƽ�� ����
//    while (true)
//    {
//        std::string dropInput;
//        std::string inputClassType;
//
//        // DropID �Է� ����, 'exit' �Է� �� ����
//        std::cout << "\nEnter DropID (1~" << DropTableCount << ") or 'exit' to quit: ";
//        std::cin >> dropInput;
//
//        if (dropInput == "exit")
//            break;
//
//        int inputDropID;
//        try
//        {
//            // DropID -> ���� ��ȯ, ���� �� ���Է� ��û
//            inputDropID = std::stoi(dropInput);
//        }
//        catch (...)
//        {
//            std::cout << "Invalid DropID input. Please enter a number or 'exit'.\n";
//            continue;
//        }
//
//        // ClassType �Է� ����
//        std::cout << "Enter ClassType (Warrior, Sorceress, Rogue): ";
//        std::cin >> inputClassType;
//
//        try
//        {
//            // ���ڿ� -> ClassType ��ȯ, ���� �� ���Է� ��û
//            ClassType classType = StringToClassType(inputClassType);
//
//            ItemInfo droppedItem;
//            // �Էµ� DropID�� ClassType�� �´� ������ ���� ���� �õ�
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