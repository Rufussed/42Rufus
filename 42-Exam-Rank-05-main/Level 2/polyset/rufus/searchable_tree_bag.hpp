#pragma once

#include "searchable_bag.hpp"
#include "tree_bag.hpp"

//   struct node {
//     node *l;
//     node *r;
//     int value;
//   };
//   node *tree;

class searchable_tree_bag : public tree_bag, public searchable_bag {


public:
  searchable_tree_bag();
  searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}
  searchable_tree_bag &operator=(const searchable_tree_bag &other){
    if (this != &other)
      tree_bag::operator=(other);
    return *this;
  }
  ~searchable_tree_bag();


  bool has(int val) const {
    node *current = tree;
    while (current != nullptr)
    {
      if (current->value == val)
        return true;
      else if (val < current->value)
        current = current->l;
      else
        current = current->r;
    }
    return false;
  }
};

// constructor and destructor = default;
// assign other to tree_bag
// operator= use the tree_bag::operator=  

//in tree search if val is lower the search left otherwise right