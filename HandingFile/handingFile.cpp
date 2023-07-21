#include <iostream>
#include <fstream>
#include <string>
#include <regex>

void findLinesWithKeyword(const std::string& filename, const std::string& keyword) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::regex pattern(keyword);

    while (std::getline(file, line)) {
        if (std::regex_search(line, pattern)) {
            std::cout << line << std::endl;
        }
    }

    file.close();
}
