#include <iostream>
#include "Hash_table.hpp"
#include "Pair.hpp"

int main() {
    Pair< int> pair {"caio", 26};
    std::cout<< pair.key;
    Hash_Map<int> map { pair , pair, pair};
    std::cout<< " value" << map.size() << "value ";

    return 0;
}