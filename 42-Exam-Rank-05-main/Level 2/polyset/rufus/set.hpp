#pragma once

#include "searchable_bag.hpp"

class set {
    private :
    searchable_bag &bag;

    public :
    set(searchable_bag &other) : bag(other) {}
    set(const set &other) : bag(other.bag) {}
    ~set() {
        bag.clear();
    }
    





};