#include <iostream>
#include <map>

int main()
{
    std::multimap<int, std::string> lookup;

    lookup.insert(std::make_pair(0, "Mike"));
    lookup.insert(std::make_pair(1, "Richard"));
    lookup.insert(std::make_pair(0, "Peter"));

    for (auto &&l : lookup)
        std::cout << l.first << ": " << l.second << std::endl;

    std::cout << std::endl;

    // std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> its = lookup.equal_range(0);
    auto its = lookup.equal_range(0);

    for (std::multimap<int, std::string>::iterator it = its.first; it != its.second; ++it)
        std::cout << it->first << ": " << it->second << std::endl;

    return 0;
}
