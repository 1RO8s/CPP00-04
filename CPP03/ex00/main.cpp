#include "ClapTrap.hpp"
#include <cassert>

void info(const std::string &str) {
    std::cout << "\033[3;36m" << str << "\033[0m" << std::endl;
}

void testClapTrap() {
    info("###### Test: ClapTrap ######");
    // コンストラクタのテスト
    info("--- Test: Constructor ---");
    ClapTrap defaultClapTrap;
    ClapTrap namedClapTrap("namedClapTrap");
    
    // 名前のゲッターとセッターのテスト
    info("--- Test: getName, setName ---");
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

    //　コピー今ストラク他のテスト
    info("--- Test: Copy Constructor ---");
    ClapTrap copiedClapTrap(namedClapTrap);
    assert(copiedClapTrap.getName() == "newNamedClapTrap");
    assert(copiedClapTrap.getHitPoints() == namedClapTrap.getHitPoints());
    assert(copiedClapTrap.getEnergyPoints() == namedClapTrap.getEnergyPoints());
    assert(copiedClapTrap.getAttackDamage() == namedClapTrap.getAttackDamage());

    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    ClapTrap assignedClapTrap;
    assignedClapTrap = namedClapTrap;
    assert(assignedClapTrap.getName() == "newNamedClapTrap");
    assert(assignedClapTrap.getHitPoints() == namedClapTrap.getHitPoints());
    assert(assignedClapTrap.getEnergyPoints() == namedClapTrap.getEnergyPoints());
    assert(assignedClapTrap.getAttackDamage() == namedClapTrap.getAttackDamage());

    info("--- Test: Destructor ---");
    assignedClapTrap.setName("assignedClapTrap");
    copiedClapTrap.setName("copiedClapTrap");
    namedClapTrap.setName("namedClapTrap");
    defaultClapTrap.setName("defaultClapTrap");
}

int main() {
    testClapTrap();
    std::cout << "\033[3;32m----- All tests passed! -----\033[0m" << std::endl;
    return 0;
}
