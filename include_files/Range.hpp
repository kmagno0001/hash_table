#pragma once
#include<vector>

std::vector<size_t> range_square( const size_t end) {
    std::vector<size_t> array(end);
    for (size_t i=1; i < end; i++) {
        array[i] = i * i;
    }
    
    return array;
}