//#pragma once
//
//#include <vector>
//#include <memory>
//
//class Player;
//class Monster;
//class Missile;

// [GameManager ���� �ǵ�]
// - ���� ��ü �帧(�ʱ�ȭ, ������Ʈ, ����)�� �����ϴ� ��Ʈ�ѷ� ����
// - �� ��ü(Player, Monster, Missile)�� �����ֱ� �� ���� ������Ʈ ����
// - main �Լ� �� ���� �л� ���� �� ����ȭ ����

//class GameManager
//{
//public:
//    // �ʱ�ȭ: ���ӿ� �ʿ��� ��ü���� �����ϰ� �ʱ� ���� ����
//    void Init();
//
//    // �� �����Ӹ��� ȣ��Ǵ� ������Ʈ �Լ�
//    // - �Է� ó��, ������Ʈ �̵�, �浹 ����, Ÿ�� ���� �� ó�� ����
//    void Update(float deltaTime);
//
//    // ���� ���� ��� �Ǵ� �ð��� ������
//    void Render();
//
//    // ���ҽ� ���� �� ���� ���� ó��
//    void Shutdown();

//private:
//    std::unique_ptr<Player> m_Player;
//    std::vector<std::unique_ptr<Monster>> m_Monsters;
//    std::vector<std::unique_ptr<Missile>> m_Missiles;

    // ���� Ȯ���� ���� �޼��� �ĺ�
    // void SpawnMonster();      // ���� ����
    // void FireMissile();       // �̻��� �߻�
    // void RemoveDestroyed();   // �Ҹ�� ��ü ����
//};