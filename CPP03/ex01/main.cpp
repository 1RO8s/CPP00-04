#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


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

void testScavTrap() {
    info("###### Test: ScavTrap ######");
    info("--- Test: Constructor ---");
    ScavTrap defaultScavTrap;
    ScavTrap namedScavTrap("GuardBot");

    // ClapTrapと異なる初期値が設定されているか確認
    info("--- Test: Default values ---");
    std::cout << "namedScavTrap: " << namedScavTrap << std::endl;
    assert(namedScavTrap.getHitPoints() == 100);
    assert(namedScavTrap.getEnergyPoints() == 50);
    assert(namedScavTrap.getAttackDamage() == 20);

    // ClapTrap から継承されたsetter/getterのテスト
    info("--- Test: Inherited setter/getter ---");
    namedScavTrap.setHitPoints(100);
    assert(namedScavTrap.getHitPoints() == 100);
    namedScavTrap.setEnergyPoints(50);
    assert(namedScavTrap.getEnergyPoints() == 50);
    namedScavTrap.setAttackDamage(15);
    assert(namedScavTrap.getAttackDamage() == 15);

    // ダメージを受けるメソッドのテスト
    info("--- Test: Inherited takeDamage ---");
    namedScavTrap.takeDamage(30);
    assert(namedScavTrap.getHitPoints() == 70);
    
    // 回復メソッドのテスト
    info("--- Test: Inherited beRepaired ---");
    namedScavTrap.beRepaired(20);
    assert(namedScavTrap.getHitPoints() == 90);

    // 攻撃メソッドのテスト
    info("--- Test: attack ---");
    namedScavTrap.attack("EnemyBot");

    // ガードゲートのテスト
    info("--- Test: guardGate ---");
    namedScavTrap.guardGate();

    // コピーコンストラクタのテスト
    info("--- Test: Copy constructor ---");
    ScavTrap copyScavTrap(namedScavTrap);
    assert(copyScavTrap.getName() == namedScavTrap.getName());
    assert(copyScavTrap.getHitPoints() == namedScavTrap.getHitPoints());
    assert(copyScavTrap.getEnergyPoints() == namedScavTrap.getEnergyPoints());

    // コピー代入演算子のテスト
    info("--- Test: Copy assignment operator ---");
    ScavTrap assignedScavTrap;
    assignedScavTrap = namedScavTrap;
    assert(assignedScavTrap.getName() == namedScavTrap.getName());
    assert(assignedScavTrap.getHitPoints() == namedScavTrap.getHitPoints());
    assert(assignedScavTrap.getEnergyPoints() == namedScavTrap.getEnergyPoints());

    info("--- Test: Destructor ---");
    assignedScavTrap.setName("assignedScavTrap");
    copyScavTrap.setName("copyScavTrap");
    namedScavTrap.setName("namedScavTrap");
    defaultScavTrap.setName("defaultScavTrap");
}

int main() {
    testClapTrap();
    testScavTrap();
    std::cout << "\033[3;32m----- All tests passed! -----\033[0m" << std::endl;
    return 0;
}
