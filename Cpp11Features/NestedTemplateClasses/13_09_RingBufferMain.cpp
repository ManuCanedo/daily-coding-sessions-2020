#include <iostream>
#include <vector>
#include "13_09_RingBuffer.h"

int main()
{
    // testing Ring<std::string> behaviour
    Ring<std::string> textRing(3);
    textRing.emplace("one");
    textRing.emplace("two");
    textRing.emplace("three");
    textRing.emplace("four");

    for (auto &tr : textRing)
        std::cout << tr << std::endl;
    std::cout << std::endl;

    // testing empty buffer
    Ring<int> intRing(3);
    for (auto &ir : intRing)
        std::cout << ir << std::endl;
    std::cout << std::endl;

    // testing more complex ring
    Ring<std::vector<std::string>> vecRing(6);

    for (auto &vr : vecRing)
        vr.push_back("this");
    vecRing[2].push_back("other");

    for (auto &vr : vecRing)
        std::cout << vr.back() << std::endl;
    std::cout << std::endl;

    return 0;
}