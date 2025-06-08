#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"
#include <string>
#include <iostream>


class searchable_tree_bag :  public searchable_bag, public tree_bag {

/*  struct node {
    node *l;
    node *r;
    int value;
  };
  node *tree;*/
  
public:

	searchable_tree_bag() {}
	searchable_tree_bag(const searchable_tree_bag &other): tree_bag(other) {}
	searchable_tree_bag &operator=(const searchable_tree_bag &other) {
	if (this != &other)
		tree_bag::operator=(other);
		return *this;
	}
	~searchable_tree_bag() {}
	
	bool has(int value) const {
	node *current = tree;
	while(current != nullptr)
	{
		if (value == current->value) return true;
		if (value < current->value) current = current->l;
		else current = current->r;
	}
	return false;
	}
};
