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
    // info("###### Test: Animal ######");
    // // コンストラクタのテスト
    // info("--- Test: Constructor ---");
    // Animal defaultAnimal;

    // info("--- Test: Default values ---");
    // // std::cout << "namedClapTrap: " << namedClapTrap << std::endl;
    // // assert(namedClapTrap.getHitPoints() == 10);
    // // assert(namedClapTrap.getEnergyPoints() == 10);
    // // assert(namedClapTrap.getAttackDamage() == 0);
    
    // // setter/getterテスト
    // info("--- Test: setter/getter ---");;
    // defaultAnimal.setType("defaultType");
    // assert(defaultAnimal.getType() == "defaultType");

    // // makeSoundのテスト
    // info("--- Test: makeSound ---");
    // defaultAnimal.makeSound();

    // //　コピーコンストラクタのテスト
    // info("--- Test: Copy Constructor ---");
    // Animal copiedAnimal(defaultAnimal);
    // assert(copiedAnimal.getType() == defaultAnimal.getType());

    // // コピー代入演算子のテスト
    // info("--- Test: Copy Assignment Operator ---");
    // Animal assignedAnimal;
    // assignedAnimal = defaultAnimal;
    // assert(copiedAnimal.getType() == defaultAnimal.getType());

    // info("--- Test: Destructor ---");
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
    defaultWrong.setType("defaultType");
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
    assignedWrong.setType("assignedType");
    copiedWrong.setType("copiedType");
    defaultWrong.setType("defaultType");
}

void testCat() {
    info("###### Test: Cat ######");
    // コンストラクタのテスト
    info("--- Test: Constructor ---");
    Cat defaultWrong;

    info("--- Test: Default values ---");
    // std::cout << "namedClapTrap: " << namedClapTrap << std::endl;
    // assert(namedClapTrap.getHitPoints() == 10);
    // assert(namedClapTrap.getEnergyPoints() == 10);
    // assert(namedClapTrap.getAttackDamage() == 0);
    
    // setter/getterテスト
    info("--- Test: setter/getter ---");;
    defaultWrong.setType("defaultType");
    assert(defaultWrong.getType() == "defaultType");

    // makeSoundのテスト
    info("--- Test: makeSound ---");
    defaultWrong.makeSound();

    //　コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    Cat copiedWrong(defaultWrong);
    assert(copiedWrong.getType() == defaultWrong.getType());

    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    Cat assignedWrong;
    assignedWrong = defaultWrong;
    assert(copiedWrong.getType() == defaultWrong.getType());

    info("--- Test: Destructor ---");
    assignedWrong.setType("assignedType");
    copiedWrong.setType("copiedType");
    defaultWrong.setType("defaultType");
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
    defaultWrong.setType("defaultType");
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
    assignedWrong.setType("assignedType");
    copiedWrong.setType("copiedType");
    defaultWrong.setType("defaultType");
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
    defaultWrong.setType("defaultType");
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
    assignedWrong.setType("assignedType");
    copiedWrong.setType("copiedType");
    defaultWrong.setType("defaultType");
}

void testBrain() {
    info("\n###### Test: Brain ######");
    Brain defaultBrain;
    
    info("--- Test: Default values ---");
    for (int i = 0; i < MAX_IDEAS; i++) {
        assert(defaultBrain.getIdea(i) == "");
    }

    info("--- Test: setter/getter ---");
    defaultBrain.setIdea(0, "defaultIdea 00");
    defaultBrain.setIdea(1, "defaultIdea 01");
    assert(defaultBrain.getIdea(0) == "defaultIdea 00");
    assert(defaultBrain.getIdea(1) == "defaultIdea 01");

    // コピーコンストラクタのテスト
    info("--- Test: Copy Constructor ---");
    Brain copiedBrain(defaultBrain);
    assert(copiedBrain.getIdea(0) == defaultBrain.getIdea(0));
    assert(copiedBrain.getIdea(1) == defaultBrain.getIdea(1));

    // コピー代入演算子のテスト
    info("--- Test: Copy Assignment Operator ---");
    Brain assignedBrain;
    assignedBrain = defaultBrain;
    assert(assignedBrain.getIdea(0) == defaultBrain.getIdea(0));
    assert(assignedBrain.getIdea(1) == defaultBrain.getIdea(1));

    info("--- Test: Destructor ---");
    assignedBrain.setIdea(0, "assignedIdea 00");
    copiedBrain.setIdea(0, "copiedIdea 00");
    defaultBrain.setIdea(0, "defaultIdea 00");
}

void testBrain2 () {
    info("###### Test: memory leak ######");
    const int ANIMAL_SIZE = 4;
    const Animal* animals[ANIMAL_SIZE];

    for (int i = 0; i < ANIMAL_SIZE; i++) {
        if (i < ANIMAL_SIZE / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // delete all animals
    for (int i = 0; i < ANIMAL_SIZE; i++) {
        delete animals[i];
    }

    // Deep copy test of Dog
    info("\n###### Test: Deep Copy of Dog ######");
    Dog defaultDog;
    Dog copiedDog;
    defaultDog.setType("defaultDog");
    defaultDog.setBrainIdea(0, "dog's idea 00");
    copiedDog = defaultDog;
    info("defaultDog.getBranIdea(0): " + defaultDog.getBrainIdea(0));
    info("copiedDog.getBranIdea(0): " + copiedDog.getBrainIdea(0));
    assert(copiedDog.getType() == defaultDog.getType());
    assert(copiedDog.getBrainIdea(0) == defaultDog.getBrainIdea(0));

    // Deep copy test of Cat
    info("\n###### Test: Deep Copy of Cat ######");
    Cat defaultCat;
    Cat copiedCat;
    defaultCat.setType("defaultCat");
    defaultCat.setBrainIdea(0, "cat's idea 00");
    copiedCat = defaultCat;
    info("defaultDog.getBranIdea(0): " + defaultDog.getBrainIdea(0));
    info("copiedDog.getBranIdea(0): " + copiedDog.getBrainIdea(0));
    assert(copiedCat.getType() == defaultCat.getType());
    assert(copiedCat.getBrainIdea(0) == defaultCat.getBrainIdea(0));
}

int main() {
    testBrain();
    testBrain2();
    // 基底クラスがインスタンス化できないこと
    // Animal animal = Animal(); 
    
    std::cout << "\033[3;32m----- All tests passed! -----\033[0m" << std::endl;
    return 0;
}

// Testing code from subject.pdf
// int main() {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;

//     return 0;
// }
