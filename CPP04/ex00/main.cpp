#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <cassert>

void info(const std::string &str) {
    std::cout << "\033[3;36m" << str << "\033[0m" << std::endl;
}

void testAnimal() {
    info("###### Test: Animal ######");
    // コンストラクタのテスト
    info("--- Test: Constructor ---");
    Animal defaultAnimal;

    info("--- Test: Default values ---");
    // std::cout << "namedClapTrap: " << namedClapTrap << std::endl;
    // assert(namedClapTrap.getHitPoints() == 10);
    // assert(namedClapTrap.getEnergyPoints() == 10);
    // assert(namedClapTrap.getAttackDamage() == 0);
    
    // setter/getterテスト
    info("--- Test: setter/getter ---");;
    // defaultAnimal.setType("defaultType");
    assert(defaultAnimal.getType() == "");

    // makeSoundのテスト
    info("--- Test: makeSound ---");
    defaultAnimal.makeSound();

    //　コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    Animal copiedAnimal(defaultAnimal);
    assert(copiedAnimal.getType() == defaultAnimal.getType());

    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    Animal assignedAnimal;
    assignedAnimal = defaultAnimal;
    assert(copiedAnimal.getType() == defaultAnimal.getType());

    info("--- Test: Destructor ---");
    // assignedAnimal.setType("assignedType");
    // copiedAnimal.setType("copiedType");
    // defaultAnimal.setType("defaultType");
}

void testWrongAnimal() {
    info("###### Test: WrongAnimal ######");
    // コンストラクタのテスト
    info("--- Test: Constructor ---");
    WrongAnimal defaultWrong;

    info("--- Test: Default values ---");
    // std::cout << "namedClapTrap: " << namedClapTrap << std::endl;
    // assert(namedClapTrap.getHitPoints() == 10);
    // assert(namedClapTrap.getEnergyPoints() == 10);
    // assert(namedClapTrap.getAttackDamage() == 0);
    
    // setter/getterテスト
    info("--- Test: setter/getter ---");;
    // defaultWrong.setType("defaultType");
    assert(defaultWrong.getType() == "defaultType");

    // makeSoundのテスト
    info("--- Test: makeSound ---");
    defaultWrong.makeSound();

    //　コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    WrongAnimal copiedWrong(defaultWrong);
    assert(copiedWrong.getType() == defaultWrong.getType());

    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    WrongAnimal assignedWrong;
    assignedWrong = defaultWrong;
    assert(copiedWrong.getType() == defaultWrong.getType());

    info("--- Test: Destructor ---");
    // assignedWrong.setType("assignedType");
    // copiedWrong.setType("copiedType");
    // defaultWrong.setType("defaultType");
}

void testCat() {
    info("###### Test: Cat ######");
    // コンストラクタのテスト
    info("--- Test: Constructor ---");
    Cat defaultCat;

    info("--- Test: Default values ---");
    // std::cout << "namedClapTrap: " << namedClapTrap << std::endl;
    // assert(namedClapTrap.getHitPoints() == 10);
    // assert(namedClapTrap.getEnergyPoints() == 10);
    // assert(namedClapTrap.getAttackDamage() == 0);
    
    // setter/getterテスト
    info("--- Test: setter/getter ---");;
    // defaultWrong.setType("defaultType");
    assert(defaultCat.getType() == "Cat");

    // makeSoundのテスト
    info("--- Test: makeSound ---");
    defaultCat.makeSound();

    //　コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    Cat copiedCat(defaultCat);
    assert(copiedCat.getType() == defaultCat.getType());

    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    Cat assignedCat;
    assignedCat = defaultCat;
    assert(assignedCat.getType() == defaultCat.getType());

    info("--- Test: Destructor ---");
    // assignedWrong.setType("assignedType");
    // copiedWrong.setType("copiedType");
    // defaultWrong.setType("defaultType");
}

void testDog() {
    info("\n###### Test: Dog ######");
    // コンストラクタのテスト
    info("--- Test: Constructor ---");
    Dog defaultWrong;

    info("--- Test: Default values ---");
    // std::cout << "namedClapTrap: " << namedClapTrap << std::endl;
    // assert(namedClapTrap.getHitPoints() == 10);
    // assert(namedClapTrap.getEnergyPoints() == 10);
    // assert(namedClapTrap.getAttackDamage() == 0);
    
    // setter/getterテスト
    info("--- Test: setter/getter ---");;
    // defaultWrong.setType("defaultType");
    assert(defaultWrong.getType() == "defaultType");

    // makeSoundのテスト
    info("--- Test: makeSound ---");
    defaultWrong.makeSound();

    //　コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    Dog copiedWrong(defaultWrong);
    assert(copiedWrong.getType() == defaultWrong.getType());

    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    Dog assignedWrong;
    assignedWrong = defaultWrong;
    assert(copiedWrong.getType() == defaultWrong.getType());

    info("--- Test: Destructor ---");
    // assignedWrong.setType("assignedType");
    // copiedWrong.setType("copiedType");
    // defaultWrong.setType("defaultType");
}

void testWrongCat() {
    info("\n###### Test: WrongCat ######");
    // コンストラクタのテスト
    info("--- Test: Constructor ---");
    WrongCat defaultWrong;

    info("--- Test: Default values ---");
    // std::cout << "namedClapTrap: " << namedClapTrap << std::endl;
    // assert(namedClapTrap.getHitPoints() == 10);
    // assert(namedClapTrap.getEnergyPoints() == 10);
    // assert(namedClapTrap.getAttackDamage() == 0);
    
    // setter/getterテスト
    info("--- Test: setter/getter ---");;
    // defaultWrong.setType("defaultType");
    assert(defaultWrong.getType() == "defaultType");

    // makeSoundのテスト
    info("--- Test: makeSound ---");
    defaultWrong.makeSound();

    //　コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    WrongCat copiedWrong(defaultWrong);
    assert(copiedWrong.getType() == defaultWrong.getType());

    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    WrongCat assignedWrong;
    assignedWrong = defaultWrong;
    assert(copiedWrong.getType() == defaultWrong.getType());

    info("--- Test: Destructor ---");
    // assignedWrong.setType("assignedType");
    // copiedWrong.setType("copiedType");
    // defaultWrong.setType("defaultType");
}

// int main() {
//     testAnimal();
//     testWrongAnimal();
//     testCat();
//     testDog();
//     testWrongCat();
//     std::cout << "\033[3;32m----- All tests passed! -----\033[0m" << std::endl;
//     return 0;
// }

// Testing code from subject.pdf
int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wrongCat1 = new WrongCat();
    const WrongCat* wrongCat2 = new WrongCat();

    wrongCat1->makeSound();
    wrongCat2->makeSound();

    return 0;
}
