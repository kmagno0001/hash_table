#include <iostream>
#include "Hash_table.hpp"
#include "Pair.hpp"

int main() {
    Pair< int> pairA {"caio", 26};
    Pair< int> pairB {"esther", 3};
    Pair< int> pairC {"emily", 20};
    
    Hash_Map<int> map { pairA , pairB, pairC};
    std::cout<< map["emily"]->value;

    return 0;
}