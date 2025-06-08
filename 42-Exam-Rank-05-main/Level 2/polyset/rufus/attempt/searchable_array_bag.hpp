#pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"
#include <string>
#include <iostream>


class searchable_array_bag :  public searchable_bag, public array_bag {
  
public:

	searchable_array_bag() {}
	searchable_array_bag(const searchable_array_bag &other): array_bag(other) {}
	searchable_array_bag &operator=(const searchable_array_bag &other) {
	if (this != &other)
		array_bag::operator=(other);
		return *this;
	}
	~searchable_array_bag() {}
	
	bool has(int value) const {
		for(int i = 0; i < size; i++)
			if (value == data[i]) return true;
		return false;
	}	
};
