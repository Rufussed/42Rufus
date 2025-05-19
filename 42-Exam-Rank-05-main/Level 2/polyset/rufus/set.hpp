#pragma once

#include "searchable_bag.hpp"

// the set needs to have constructor, destructor, print, clear, insert int, insert array with size, has, and get_bag

class set {
	private :
	searchable_bag &bag;

	public :

	set(searchable_bag &oth): bag(oth) {}
	~set() {
		bag.clear();
	}

	void print() const{
		bag.print();
	}

	void clear() {
		bag.clear();
	}

	void insert(int val) {
		if (!bag.has(val))
			bag.insert(val);
	}

	void insert(int *arr, int size) {
		for (int i = 0; i < size; i++) {
			if (!bag.has(arr[i]))
				bag.insert(arr[i]);
		}
	}

	bool has(int val) const {
		return bag.has(val);
	}

	searchable_bag &get_bag() const {
		return bag;
	}
};