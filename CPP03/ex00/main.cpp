#include "ClapTrap.hpp"
#include <cassert>

void info(const std::string &str) {
    std::cout << "\033[3;37m" << str << "\033[0m" << std::endl;
}

void testClapTrap() {
    // コンストラクタのテスト
    info("--- Test: Constructor ---");
    ClapTrap defaultClapTrap;
    ClapTrap namedClapTrap("namedClapTrap");
    
    // 名前のゲッターとセッターのテスト
    info("--- Test: getName, setName ---");
    std::string name = "";
    assert(namedClapTrap.getName() == "namedClapTrap");
    namedClapTrap.setName("newNamedClapTrap");
    assert(namedClapTrap.getName() == "newNamedClapTrap");

    // ヒットポイントのゲッターとセッターのテスト
    info("--- Test: getHitPoints, setHitPoints ---");
    namedClapTrap.setHitPoints(100);
    assert(namedClapTrap.getHitPoints() == 100);

    // エナジーポイントのゲッターとセッターのテスト
    info("--- Test: getEnergyPoints, setEnergyPoints ---");
    namedClapTrap.setEnergyPoints(50);
    assert(namedClapTrap.getEnergyPoints() == 50);

    // 攻撃ダメージのゲッターとセッターのテスト
    info("--- Test: getAttackDamage, setAttackDamage ---");
    namedClapTrap.setAttackDamage(20);
    assert(namedClapTrap.getAttackDamage() == 20);

    // 攻撃メソッドのテスト
    info("--- Test: attack ---");
    namedClapTrap.attack("EnemyTrap");

    // ダメージを受けるメソッドのテスト
    info("--- Test: takeDamage ---");
    namedClapTrap.takeDamage(30);
    assert(namedClapTrap.getHitPoints() == 70);
    
    // 回復メソッドのテスト
    info("--- Test: beRepaired ---");
    namedClapTrap.beRepaired(20);
    assert(namedClapTrap.getHitPoints() == 90);
}

int main() {
    testClapTrap();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
