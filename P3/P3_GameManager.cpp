//#include <iostream>
//
//#include "P3_GameManager.h"
//#include "P3_Player.h"
//#include "P3_Monster.h"
//#include "P3_Missile.h"

// GameManager::Init()
// - 플레이어 생성
// - 초기 몬스터 스폰
// - 미사일 벡터 초기화

// GameManager::Update(deltaTime)
// - 각 오브젝트의 Update 호출
// - 죽은 몬스터, 수명 끝난 미사일 제거 예정
// - 플레이어 상태 갱신, 필요 시 입력 기반 미사일 발사 등 처리 예정

// GameManager::Render()
// - 콘솔 기준 객체 상태를 출력하거나, 간단한 위치 로그 출력

// GameManager::Shutdown()
// - unique_ptr 기반 자동 정리
// - vector clear 등을 통해 명시적으로 자원 해제도 가능