#pragma once
#include <string>
#include <iostream>
#include <algorithm>

class bigint {
    private:
    std::string value;
    public:
    bigint(): value("0") {}
    bigint(size_t num): value(std::to_string(num)) {}
    bigint(const std::string &str) {
        if (str.empty() || !std::all_of(str.begin(), str.end(), ::isdigit)) {
            value = "0";
            return;
        }
        
        // Find first non-zero digit
        size_t firstNonZero = str.find_first_not_of('0');
        
        // If string is all zeros or empty
        if (firstNonZero == std::string::npos) {
            value = "0";
        } else {
            value = str.substr(firstNonZero);
        }
    }
    bigint(const bigint &other) : value(other.value) {}
    ~bigint() {}
    bigint& operator=(const bigint &other)
    {
        if (!(this == &other))
        value = other.value;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os, const bigint &bi) {
        os << bi.value;
        return os;
    }

    bigint operator+(const bigint &other) const {
        bigint result;
        result.value = "";
        int sum = 0;
        int carry = 0;
        int i = this->value.length() - 1;
        int j = other.value.length() - 1;
        int n1, n2;
        while(i >= 0 || j >=0 || carry > 0) {
            n1 = (i >= 0) ? this->value[i] - '0' : 0;
            n2 = (j >= 0) ? other.value[j] - '0' : 0;
            sum = (n1 + n2 + carry);
            carry = sum / 10;
            sum %= 10;
            result.value.insert(0, 1, sum + '0');
            i--;
            j--;
        }
        return result;
    }

    bigint& operator+=(const bigint &other)  {
        *this = *this + other;
        return *this;
    }

    //pre inc
    bigint& operator++() {
        *this += bigint(1);
        return *this;
    }

    //post inc
    bigint operator++(int) {
        bigint temp = *this;
        *this += bigint(1);
        return temp;
    }

    bigint operator<<(long shift) const {
        bigint temp = *this;
        if (value == "0") return *this;
        for(int i = 0; i < shift; i++)
            temp.value += "0";
        return temp;
    }

    bigint operator<<(const bigint &shift) const {
        return *this << stol(shift.value);      
    }

    
    bigint operator>>(size_t shift) const {
        if (shift >= value.length())
            return bigint(0);
        bigint temp = *this;
        temp.value = temp.value.substr(0, value.length() - shift);
        return temp;
    }

    bigint operator>>(const bigint &shift) const {
        return *this >> std::stol(shift.value);      
    }


    bigint& operator<<=(size_t shift)  {
        *this = *this << shift;
        return *this;
    }

    bigint operator<<=(const bigint &shift)  {
        *this = * this << std::stol(shift.value);  
        return *this;    
    }

    bigint& operator>>=(size_t shift)  {
        *this = *this >> shift;
        return *this;
    }

    bigint operator>>=(const bigint &shift)  {
        *this = *this >> std::stol(shift.value);  
        return *this;    
    }

    bool operator>(const bigint &other) const {
        if (value.length() != other.value.length())
            return value.length() > other.value.length();
        return value > other.value;       
    }

    bool operator<(const bigint &other) const {
        return other > *this;       // the operator here is expecing bigints
    }

    bool operator==(const bigint &other) const {
        return value == other.value;
    }
    
    bool operator!=(const bigint &other) const {
        return value != other.value;
    }

    bool operator>=(const bigint &other) const {
        if (*this == other)
            return true;
        else 
            return *this > other;
    }

    bool operator<=(const bigint &other) const {
        if (*this == other)
            return true;
        else 
            return *this < other;
    }

    bigint operator-(const bigint &other) {
        (void) other;
        return bigint(0);
    }

};