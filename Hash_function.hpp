#include <vector>
#include "include_files/Range.hpp"
#include "Pair.hpp"

template< typename Value>
inline size_t hash_function( const std::string& key, size_t capacity) {
    size_t sum = 0;
    for (char letter : key ) {
        sum += (static_cast<size_t>(letter) % capacity); 
    }
    return sum;
}

template< typename Value>
inline size_t quadratic_probing(const std::vector<Pair<Value>*> key, size_t length, size_t hash_value) {
    auto new_hash = hash_value;
    for (size_t i : range_square(length)) {
        new_hash = (new_hash + i * i) % length;  
        if (key[new_hash] == nullptr) {
           break;
        }
        else {
            new_hash = 0;
        }
    }
    return new_hash;
}
