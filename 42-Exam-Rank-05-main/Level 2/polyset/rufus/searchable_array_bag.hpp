# pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"
#include "iostream"


class searchable_array_bag : public array_bag, public  searchable_bag {
    public:
    searchable_array_bag() = default;
    searchable_array_bag(const searchable_array_bag &other) : array_bag(other) {}
    searchable_array_bag operator=(const searchable_array_bag &other) {
         if (this != &other)
            array_bag::operator=(other);
         return *this;
    }
    ~searchable_array_bag() = default;

    bool has(int value) const {
        for(int i=0; i < size; i++)
            if (data[i] == value)
                return true;
        return false;
    }
};