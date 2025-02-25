#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data* data = new Data(42, "Hello, World!");  
    std::cout << "Original: " << data << std::endl;
    std::cout << "data: value = " << data->getValue() << ", str = " << data->getStr() << std::endl;

    // Serialize
    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized value: " << serialized << std::endl;

    // Deserialize
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized: " << deserialized << std::endl;
    std::cout << "data: value = " << deserialized->getValue() << ", str = " << deserialized->getStr() << std::endl;

    // 比較
    std::cout << "data equal deserialized: " << (data == deserialized ? "equal" : "different") << std::endl;

    delete data;
    return 0;
}
