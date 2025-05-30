#pragma once
#include <iostream>
#include <string>

class vect2 {
    private :
    int x;
    int y;

    public :
    vect2() : x(0), y(0) {}
    vect2(int x, int y) : x(x), y(y) {}
    vect2(const vect2 &other) : x(other.x), y(other.y) {}
    vect2 operator=(const vect2 &other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    ~vect2() {}

    friend std::ostream& operator<<(std::ostream &s, const vect2 v) {
        s << v.x << ", " << v.y;
        return s;
    }

    //getter
    int operator[](int index) const {
        return (index == 0 ? x : y);
    }

    //setter
    int& operator[](int index) { // not a const function because content of referenced int can be changed by caller
        return (index == 0 ? x : y);
    }

    //preinc
    vect2& operator++() {
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
    vect2& operator--() {
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
        vect2 result;
        result.x = x + other.x;
        result.y = y + other.y;     
        return result;
    }

    vect2& operator+=(const vect2 &other) {
        *this = *this + other;   
        return *this;
    }

    vect2 operator-(const vect2 &other) const {
        vect2 result;
        result.x = x - other.x;
        result.y = y - other.y;     
        return result;
    }

    vect2 operator-() {
        return vect2(-x, -y);
    }

    vect2& operator-=(const vect2 &other) {
        *this = *this - other;   
        return *this;
    }

    vect2 operator*(int scalar) const {
       
        return vect2(x * scalar, y *scalar);
    }

    friend vect2 operator*(int scalar, const vect2 &v) {
        return vect2(v.x * scalar, v.y * scalar);
    }

    vect2& operator*=(int scalar) {
        x *= scalar;
        y *= scalar;
        return *this;       
    }

    bool operator==(const vect2 &other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const vect2 &other) const {
        return !(x == other.x && y == other.y);
    }

};