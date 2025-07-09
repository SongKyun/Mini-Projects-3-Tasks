//#pragma once
//
//#include <vector>
//#include <memory>
//
//class Player;
//class Monster;
//class Missile;

// [GameManager 설계 의도]
// - 게임 전체 흐름(초기화, 업데이트, 종료)을 제어하는 컨트롤러 역할
// - 각 객체(Player, Monster, Missile)의 생명주기 및 상태 업데이트 관리
// - main 함수 내 로직 분산 방지 및 구조화 목적

//class GameManager
//{
//public:
//    // 초기화: 게임에 필요한 객체들을 생성하고 초기 상태 설정
//    void Init();
//
//    // 매 프레임마다 호출되는 업데이트 함수
//    // - 입력 처리, 오브젝트 이동, 충돌 감지, 타격 판정 등 처리 예정
//    void Update(float deltaTime);
//
//    // 현재 상태 출력 또는 시각적 디버깅용
//    void Render();
//
//    // 리소스 정리 및 게임 종료 처리
//    void Shutdown();

//private:
//    std::unique_ptr<Player> m_Player;
//    std::vector<std::unique_ptr<Monster>> m_Monsters;
//    std::vector<std::unique_ptr<Missile>> m_Missiles;

    // 추후 확장을 위한 메서드 후보
    // void SpawnMonster();      // 몬스터 생성
    // void FireMissile();       // 미사일 발사
    // void RemoveDestroyed();   // 소멸된 객체 정리
//};