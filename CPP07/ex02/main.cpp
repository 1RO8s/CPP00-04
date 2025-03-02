#include "Array.hpp"
#include <iostream>
#include <string>

template <typename T>
void displayArray(const Array<T>& arr, const std::string& name) {
  std::cout << name << " (size: " << arr.size() << "): ";
  for (unsigned int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  // デフォルトコンストラクタのテスト
  Array<int> empty;
  std::cout << "Empty array size: " << empty.size() << std::endl;

  // サイズ指定コンストラクタのテスト
  Array<int> numbers(5);
  for (unsigned int i = 0; i < numbers.size(); i++) {
    // 添字演算子のテスト
    numbers[i] = i + 1;
  }
  displayArray(numbers, "Numbers");

  // コピーコンストラクタのテスト
  Array<int> copy(numbers);
  displayArray(copy, "Copy of numbers");
  // ディープコピーになっているか
  numbers[0] = 100;
  displayArray(numbers, "Modified numbers");
  displayArray(copy, "Copy should remain unchanged");

  // 代入演算子のテスト
  Array<std::string> strings(3);
  strings[0] = "Hello";
  strings[1] = "42";
  strings[2] = "Tokyo";
  displayArray(strings, "Strings");

  Array<std::string> assigned;
  assigned = strings;
  displayArray(assigned, "Assigned strings");

  // 範囲外アクセスのテスト
  try {
    numbers[numbers.size()] = 6;  // 範囲外アクセス
  } catch (const std::exception& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }


  std::cout << "------------- 添字演算子（const版）---------------" << std::endl;
  // 添字演算子のconst版のテスト
  const Array<int> const_arr(numbers);
  
  // 読み取り可能なこと
  std::cout << "Const array element: " << const_arr[0] << std::endl;
  size_t size = const_arr.size();
  std::cout << "Last element: " << const_arr[size - 1] << std::endl;
  
  // 変更が禁止されていること（コンパイルエラーになることを確認）
  // const_arr[0] = 100;                    // 直接の代入
  // const_arr[0]++;                        // インクリメント
  // int& ref = const_arr[0];               // 非const参照の取得
  // const_arr[0] = const_arr[1];           // const同士の代入

  return 0;
}
