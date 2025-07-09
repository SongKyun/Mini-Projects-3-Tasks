#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "P3_Player.h"
#include "P3_Missile.h"
#include "P3_Monster.h"

// ���� ��� �Լ�
std::string VecToString(const Vector3& v)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return oss.str();
}

int main()
{
    constexpr float deltaTime = 0.3f;
    constexpr float monsterVelocity = 2.0f;
    constexpr float missileVelocity = 2.0f;

    Vector3 playerPos(0, 0, 0);

    // ���� �ʱ� ��ġ �������� (��: -10 ~ 10 ���� X, 0 Y, -10 ~ 10 Z)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-10.0f, 10.0f);
    Vector3 monsterPos(dist(gen), 0, dist(gen));

    Player player(playerPos, 0.0f);
    auto monster = std::make_unique<Monster>(monsterPos, monsterVelocity);
    std::unique_ptr<Missile> missile = nullptr;

    std::string userInput;
    std::cout << "Fire missile? (type 'Fire'): ";
    std::cin >> userInput;

    if (std::cin.fail() || userInput != "Fire")
    {
        std::cout << "Invalid input or input failure. Exiting.\n";
        return 0;
    }

    missile = std::make_unique<Missile>(player.GetPosition(), missileVelocity, monster.get());
    if (!missile)
    {
        std::cout << "Failed to create missile. Exiting.\n";
        return 0;
    }

    std::cout << "Missile launched!\n";

    // ó�� �̻��� ���� ��� (ó�� ����)
    std::cout << "Initial Missile Angle: " << missile->GetAngle() << " degrees\n";

    int frame = 0;
    while (!missile->IsDestroyed())
    {
        if (!monster || !missile)
        {
            std::cout << "Game entities not properly initialized. Exiting.\n";
            return 0;
        }
        
        monster->SetPlayerPosition(player.GetPosition());

        player.Update(deltaTime);
        monster->Update(deltaTime);
        missile->Update(deltaTime);

        if (missile->IsDestroyed()) break;
        if (monster->IsDead()) break;

        std::cout << "[Frame " << std::setw(3) << frame << "] "
            << "Monster Pos: " << VecToString(monster->GetPosition()) << ", "
            << "Missile Pos: " << VecToString(missile->GetPosition()) << ", "
            << "Missile Angle: " << std::fixed << std::setprecision(2) << missile->GetAngle() << " deg"
            << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ++frame;
    }

    // ���� ���� �� ���� �Ǵ�
    if (monster->IsDead())
    {
        std::cout << "\nVictory!\n";
    }
    else
    {
        std::cout << "\nGame Over!\n";
    }

    std::cout << "[Final Positions]\n";
    std::cout << "Monster Pos : " << VecToString(monster->GetPosition()) << "\n";
    std::cout << "Missile Pos : " << VecToString(missile->GetPosition()) << "\n";
    std::cout << "Missile Final Angle: " << missile->GetAngle() << " degrees\n";

    return 0;
}