#pragma once
#include <iostream>
#include <string>

class vect2 {
	private:
		int x, y;
	public:
	
	vect2(): x(0), y(0) {}
	vect2(int x, int y): x(x), y(y) {}
	vect2(const vect2 &other) : x(other.x), y(other.y) {}
	vect2 &operator=(const vect2 &other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}
	
	friend std::ostream &operator<<(std::ostream &os, const vect2 &vec) {
		os << vec.x << ", " << vec.y;
		return os;
	}
	//get
	int operator[](int i) const {
		if (i) return y;
		return x;
	}
	//set
	int &operator[](int i) {
		if (i) return y;
		return x;
	}
	//preinc
	vect2 &operator++() {
		x += 1;
		y += 1;
		return *this; 	
	}
	
	//postinc
	vect2 operator++(int) {
		vect2 temp = *this;
		x += 1;
		y += 1;
		return temp; 	
	}
	
		//predec
	vect2 &operator--() {
		x -= 1;
		y -= 1;
		return *this; 	
	}
	
	//postdec
	vect2 operator--(int) {
		vect2 temp = *this;
		x -= 1;
		y -= 1;
		return temp; 	
	}
	
	vect2 operator+(const vect2 &other) const {
		return vect2(x + other.x, y + other.y);
	}
	
	vect2 operator-(const vect2 &other) const {
		return vect2(x - other.x, y - other.y);
	}
    
    vect2 &operator+=(const vect2 &other)  {
    	x += other.x;
    	y += other.y;
    	return *this;
    }
    
     vect2 &operator-=(const vect2 &other)  {
    	x -= other.x;
    	y -= other.y;
    	return *this;
    }
    	
    vect2 operator*(int scalar) const  {
    	return vect2(x*scalar, y*scalar);
    }
    	
    	
    friend vect2 operator*(int scalar, const vect2 &vec) {
    	return vect2(vec.x*scalar, vec.y*scalar);
    }
    	
    vect2 &operator*=(int scalar) {
    	x *= scalar; y *=scalar;
    	return *this;
    }
    	
        // Equality operator
    bool operator==(const vect2 &other) const {
        return x == other.x && y == other.y;
    }

    // Inequality operator
    bool operator!=(const vect2 &other) const {
        return x != other.x || y != other.y;
    }

    // Unary minus
    vect2 operator-() const {
        return vect2(-x, -y);
    }

    
};
