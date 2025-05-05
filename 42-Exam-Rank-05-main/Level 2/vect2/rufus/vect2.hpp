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

    vect2 &operator=(const vect2 &other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    bool operator!=(const vect2& other)
    {
        return (x != other.x || y != other.y);
    }

    int operator[](int index) const
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
    }

    vect2 operator-(const vect2& other)
    {
        return vect2(x - other.x, y - other.y);
    }
    vect2 operator-=(const vect2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    vect2 operator+(const vect2& other)
    {
        return vect2(x + other.x, y + other.y);
    }
    vect2 operator+=(const vect2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    vect2 operator*(const int& scalar)
    {
        return vect2(x * scalar, y * scalar);
    }
    vect2 operator*=(const int& scalar)
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
        vect2 temp = *this;
        ++(*this);
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
        vect2 temp = *this;
        --(*this);
        return temp;
    }


    



    
    




};
