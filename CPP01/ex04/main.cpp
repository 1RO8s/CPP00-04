#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

int is_invalid_parameters(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Need 3 arguments" << std::endl;
    return 1;
  }
  std::string fileName = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  return 0;
}

std::string replaceString(const std::string& str, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t prevPos = 0;

    while ((pos = str.find(s1, prevPos)) != std::string::npos) {
        result += str.substr(prevPos, pos - prevPos);
        result += s2;
        prevPos = pos + s1.length();
    }
    result += str.substr(prevPos);
    return result;
}

int openFile(std::ifstream &file, const std::string& fileName) {
    file.open(fileName.c_str());
    if (!file) {
        std::cerr << "file could not be opened: " << fileName << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return 0;
}

int createFile(std::ofstream &file, const std::string& fileName) {
    file.open(fileName.c_str());
    if (!file) {
        std::cerr << "file could not be created: " << fileName << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return 0;
}

int main(int argc, char **argv) {
  if (is_invalid_parameters(argc, argv))
    return (EXIT_FAILURE);
  
  try {
    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::ifstream inputFile;
    openFile(inputFile, fileName);
    std::ofstream outputFile;
    createFile(outputFile, fileName + ".replace");

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string replacedLine = replaceString(line, s1, s2);
        outputFile << replacedLine << '\n';
    }
    inputFile.close();
    outputFile.close();
    // std::cout << "置換が完了しました。" << std::endl;
  } catch (const std::exception& e) {
    std::cout << "An error occurred." << std::endl;
    return (EXIT_FAILURE);
  }
}
