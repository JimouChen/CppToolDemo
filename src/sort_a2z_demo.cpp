#include <iostream>
#include <vector>
#include <algorithm>

void sortStrings(std::vector<std::string>& array, bool reverse) {
    std::sort(array.begin(), array.end(), [reverse](const std::string& a, const std::string& b) {
        if (reverse) {
            return std::lexicographical_compare(b.begin(), b.end(), a.begin(), a.end(), [](char c1, char c2) {
                return std::tolower(c1) < std::tolower(c2);
            });
        } else {
            return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [](char c1, char c2) {
                return std::tolower(c1) < std::tolower(c2);
            });
        }
    });
}

int main() {
    std::vector<std::string> array = {"AEb", "abKl", "aCsa"};
    bool reverse = false;
    
    sortStrings(array, reverse);
    
    for (const auto& str : array) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
