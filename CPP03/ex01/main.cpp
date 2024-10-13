// #include "ClapTrap.hpp"

// int main() {
//     std::cout << "---------------------" << std::endl;
//     // テスト 1: コンストラクタ, デストラクタ, attack
//     {
//         ClapTrap ct1("CT-1");
//         ct1.attack("Target-A");

//         std::cout << ct1 << std::endl;
//     }
//     std::cout << "---------------------" << std::endl;

//     // テスト 2:  コピーコンストラクタ, 代入演算子
//     {
//         ClapTrap ct2("CT-2");
//         ct2.setAttackDamage(3);
//         ClapTrap ct3(ct2);
//         ct3.attack("Target-B");

//         ClapTrap ct4("CT-4");
//         ct4 = ct3;
//         ct4.attack("Target-C");

//         std::cout << ct2 << std::endl;
//         std::cout << ct3 << std::endl;
//         std::cout << ct4 << std::endl;
//     }
//     std::cout << "---------------------" << std::endl;

//     // テスト 3: takeDamage, beRepaired
//     {
//         ClapTrap ct5("CT-5");
//         ct5.takeDamage(4);
//         ct5.beRepaired(2);
//         ct5.takeDamage(100);

//         std::cout << ct5 << std::endl;
//     }
//     std::cout << "---------------------" << std::endl;

//     return 0;
// }


#include "ClapTrap.hpp"
#include <cassert>

void msg(const std::string &str) {
    // std::cout << "\033[31m" << str << "\033[0m" << std::endl;
    // std::cout << "\033[36m" << str << "\033[0m" << std::endl; // シアン
    // std::cout << "\033[90m" << str << "\033[0m" << std::endl;  // 暗いグレー（淡い色）
    std::cout << "\033[3;37m" << str << "\033[0m" << std::endl;  // 白
}

void testClapTrap() {
    // コンストラクタのテスト
    msg("--- Test: Constructor ---");
    ClapTrap defaultClapTrap;
    ClapTrap namedClapTrap("namedClapTrap");
    
    // 名前のゲッターとセッターのテスト
    msg("--- Test: getName, setName ---");
    std::string name = "";
    assert(namedClapTrap.getName() == "namedClapTrap");
    namedClapTrap.setName("newNamedClapTrap");
    assert(namedClapTrap.getName() == "newNamedClapTrap");

    // ヒットポイントのゲッターとセッターのテスト
    msg("--- Test: getHitPoints, setHitPoints ---");
    namedClapTrap.setHitPoints(100);
    assert(namedClapTrap.getHitPoints() == 100);

    // エナジーポイントのゲッターとセッターのテスト
    msg("--- Test: getEnergyPoints, setEnergyPoints ---");
    namedClapTrap.setEnergyPoints(50);
    assert(namedClapTrap.getEnergyPoints() == 50);

    // 攻撃ダメージのゲッターとセッターのテスト
    msg("--- Test: getAttackDamage, setAttackDamage ---");
    namedClapTrap.setAttackDamage(20);
    assert(namedClapTrap.getAttackDamage() == 20);

    // 攻撃メソッドのテスト
    msg("--- Test: attack ---");
    namedClapTrap.attack("EnemyTrap");

    // ダメージを受けるメソッドのテスト
    msg("--- Test: takeDamage ---");
    namedClapTrap.takeDamage(30);
    assert(namedClapTrap.getHitPoints() == 70);
    
    // 回復メソッドのテスト
    msg("--- Test: beRepaired ---");
    namedClapTrap.beRepaired(20);
    assert(namedClapTrap.getHitPoints() == 90);

    // デストラクタの動作はテストケース外で確認すること
}

int main() {
    testClapTrap();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
