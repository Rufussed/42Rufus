#pragma once
#include <iostream>
#include <string>
#include "searchable_bag.hpp"

// array bag
//  int *data;
//  int size;

/*  
tree bag
struct node {
    node *l;
    node *r;
    int value;
  };
  node *tree;*/


class set {
private :
	searchable_bag &bag;
	
public :
	set(searchable_bag &other) : bag(other) {}
	~set() {
		bag.clear();
	}
	
	void insert(int value) {
	if (!bag.has(value))
		bag.insert(value);
	}
	
	void insert(int *arr, int size) {
		for (int i = 0; i < size; i++)
		{
			if (!bag.has(arr[i]))
				bag.insert(arr[i]);
		}
	}
	
	void print() const {
		bag.print();
	}
	
	void clear () {
		bag.clear();
	}
	
	bool has(int value) const {
		return bag.has(value);
	}
	
	searchable_bag &get_bag() const {
		return bag;
	}
	
};
