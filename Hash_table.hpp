#include <vector>
#include <iostream>
#include "Pair.hpp"
#include "hash_function.hpp"

template< typename Value>
class Hash_Map {
public:
    Hash_Map() = default;
    template<typename... Args >
    Hash_Map( const Args... values);

    const Pair<Value>* operator[] (const std::string param);

    void add(const Pair<Value> pair);
    void remove(const std::string);
    size_t size(); 
    
private:
    size_t length;
    std::vector<Pair< Value>*> map;
};

template< typename Value>
template< typename... Args > 
Hash_Map<Value>::Hash_Map(const Args... values) :
    length{sizeof...(values)},
    map(length * 2, nullptr)
{
    const Pair<Value> array[length] { std::move(values)...};

    size_t hash_value;
    for (Pair<Value> pair : array) {
        hash_value = hash_function<Value>(pair.key, length);

        if (map[hash_value] == nullptr) { 
            map[hash_value] = new Pair<Value>(pair);
        }
        else {
           map[quadratic_probing<Value>( map, length, hash_value)] = new Pair<Value>(pair); 
        } 
    }
}


template< typename Value>
size_t Hash_Map< Value>::size() {
    return length;
}

template< typename Value>
const Pair<Value>* Hash_Map<Value>::operator[] ( const std::string param ) {
    const size_t hashKey = hash_function<Value>( param, length);
    return map[hashKey];
}