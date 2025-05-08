#pragma once

#include <iostream>

class vect2
{
private:
    int x, y;

public:
    vect2() : x(0), y(0) {};
    vect2(int x, int y) : x(x), y(y) {};
    vect2(const vect2 &other) : x(other.x), y(other.y) {};

    //output to output stream
    friend std::ostream& operator<<(std::ostream& os, const vect2& v)
    {
        os << v.x << ", " << v.y;
        return os;
    }
    
    vect2 &operator=(const vect2 &other)
    {
        if (this != &other)
        {typedef struct s_life
            {
                int* map;
                int width;
                int height;
                int iterations;
                char *setup;
                int max_iterations;
            } t_life;
            
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    bool operator==(const vect2& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const vect2& other) const {
        return !(*this == other);
    }

    // retrieve x and y values
    int operator[](int index) const
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        return 0;
    }

    // set x and y values
    int& operator[](int index)
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        return x; //default return
    }

    vect2 operator-(const vect2& other)
    {
        return vect2(x - other.x, y - other.y);
    }
    vect2& operator-=(const vect2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    //unary : meaning one operand before the operator
    vect2 operator-() const {
        return vect2(-x, -y);
    }

    vect2 operator+(const vect2& other) const {
        return vect2(x + other.x, y + other.y);
    }
    vect2& operator+=(const vect2& other) {    
        x += other.x;
        y += other.y;
        return *this;
    }

    vect2 operator*(const int& scalar) const {
        return vect2(x * scalar, y * scalar);
    }

     // Friend function for int * vect2
     friend vect2 operator*(const int& scalar, const vect2& v) {
        return v * scalar;  // Reuse the member operator*
    }

    vect2& operator*=(const int& scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // Preincrement
    vect2& operator++() { 
        x++;
        y++;
        return *this;
    }

    // Post-increment 
    vect2 operator++(int) { 
        vect2 temp(*this);
        x++;
        y++;
        return temp;
    }

    //pre-decrement
    vect2& operator--()
    {
        x--;
        y--;
        return *this;
    }

    //post-decrement
    vect2 operator--(int) {
        vect2 temp(*this);
        x--;
        y--;
        return temp;
    }
};
