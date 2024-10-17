#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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

    info("--- Test: Default values ---");
    std::cout << "namedClapTrap: " << namedClapTrap << std::endl;
    assert(namedClapTrap.getHitPoints() == 10);
    assert(namedClapTrap.getEnergyPoints() == 10);
    assert(namedClapTrap.getAttackDamage() == 0);
    
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
    assert(namedScavTrap.getHitPoints() == ScavTrap::MAX_HIT_POINTS);
    assert(namedScavTrap.getEnergyPoints() == ScavTrap::MAX_ENERGY_POINTS);
    assert(namedScavTrap.getAttackDamage() == ScavTrap::ATTACK_DAMAGE);

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

void testFragTrap() {
    // コンストラクタのテスト
    info("###### Test: FragTrap ######");
    info("--- Test: Constructor ---");
    FragTrap defaultFragTrap;
    FragTrap namedFragTrap("HighFiveBot");

    // ClapTrapと異なる初期値が設定されているか確認
    info("--- Test: Default values ---");
    std::cout << "namedFragTrap: " << namedFragTrap << std::endl;
    assert(namedFragTrap.getHitPoints() == FragTrap::MAX_HIT_POINTS);
    assert(namedFragTrap.getEnergyPoints() == FragTrap::MAX_ENERGY_POINTS);
    assert(namedFragTrap.getAttackDamage() == FragTrap::ATTACK_DAMAGE);

    // FragTrap のメソッドをテスト
    info("--- Test: highFivesGuys ---");
    namedFragTrap.highFivesGuys();

    // コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    FragTrap copyFragTrap(namedFragTrap);
    assert(copyFragTrap.getName() == namedFragTrap.getName());
    assert(copyFragTrap.getHitPoints() == namedFragTrap.getHitPoints());
    assert(copyFragTrap.getEnergyPoints() == namedFragTrap.getEnergyPoints());
    assert(copyFragTrap.getAttackDamage() == namedFragTrap.getAttackDamage());
    
    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    FragTrap assignedFragTrap;
    assignedFragTrap = namedFragTrap;
    assert(assignedFragTrap.getName() == namedFragTrap.getName());
    assert(assignedFragTrap.getHitPoints() == namedFragTrap.getHitPoints());
    assert(assignedFragTrap.getEnergyPoints() == namedFragTrap.getEnergyPoints());
    assert(assignedFragTrap.getAttackDamage() == namedFragTrap.getAttackDamage());

    info("--- Test: Destructor ---");
    assignedFragTrap.setName("assignedFragTrap");
    copyFragTrap.setName("copyFragTrap");
    namedFragTrap.setName("namedFragTrap");
    defaultFragTrap.setName("defaultFragTrap");
}

void testDiamondTrap(){
    // コンストラクタのテスト
    info("###### Test: DiamondTrap ######");
    info("--- Test: Constructor ---");
    DiamondTrap defaultDiamondTrap;
    DiamondTrap namedDiamondTrap("DiamondBot");

    // ClapTrapと異なる初期値が設定されているか確認
    info("--- Test: Default values ---");
    std::cout << "namedDiamondTrap: " << namedDiamondTrap << std::endl;
    assert(namedDiamondTrap.getHitPoints() == FragTrap::MAX_HIT_POINTS);
    assert(namedDiamondTrap.getEnergyPoints() == ScavTrap::MAX_ENERGY_POINTS);
    assert(namedDiamondTrap.getAttackDamage() == FragTrap::ATTACK_DAMAGE);

    // FragTrap のメソッドをテスト
    info("--- Test: whoAmI() ---");
    namedDiamondTrap.whoAmI();

    // コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    DiamondTrap copyDiamondTrap(namedDiamondTrap);
    assert(copyDiamondTrap.getName() == namedDiamondTrap.getName());
    assert(copyDiamondTrap.getHitPoints() == namedDiamondTrap.getHitPoints());
    assert(copyDiamondTrap.getEnergyPoints() == namedDiamondTrap.getEnergyPoints());
    assert(copyDiamondTrap.getAttackDamage() == namedDiamondTrap.getAttackDamage());
    
    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    DiamondTrap assignedDiamondTrap;
    assignedDiamondTrap = namedDiamondTrap;
    assert(assignedDiamondTrap.getName() == namedDiamondTrap.getName());
    assert(assignedDiamondTrap.getHitPoints() == namedDiamondTrap.getHitPoints());
    assert(assignedDiamondTrap.getEnergyPoints() == namedDiamondTrap.getEnergyPoints());
    assert(assignedDiamondTrap.getAttackDamage() == namedDiamondTrap.getAttackDamage());

    info("--- Test: Destructor ---");
    assignedDiamondTrap.setName("assignedDiamondTrap");
    copyDiamondTrap.setName("copyDiamondTrap");
    namedDiamondTrap.setName("namedDiamondTrap");
    defaultDiamondTrap.setName("defaultDiamondTrap");
}

int main() {
    testClapTrap();
    testScavTrap();
    testFragTrap();
    testDiamondTrap();
    std::cout << "\033[3;32m----- All tests passed! -----\033[0m" << std::endl;
    return 0;
}
