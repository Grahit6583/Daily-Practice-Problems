#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> mp;
    mp[1] = 10;

    if (mp.contains(1)) {
        std::cout << "C++23 is working!\n";
    } else {
        std::cout << "C++23 is not detected!\n";
    }

    return 0;
}
