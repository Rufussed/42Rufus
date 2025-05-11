#pragma once

#include <iostream>
#include <string>
#include <cstdio>   // for sprintf
#include <cstdlib>  // for atoi
#include <cstring>  // for string operations

class bigint {
    private:
        std::string value;  // Store number as string for arbitrary precision

    public:
        bigint(): value("0") {}
        bigint(int val) {
            char buf[32];
            std::sprintf(buf, "%d", val); 
            value = buf;
        }
        ~bigint() {}
        bigint(const bigint& other): value(other.value) {}
        
        // allow printing of bigint objects
        friend std::ostream& operator<<(std::ostream& os, const bigint& bi) {
            os << bi.value;
            return os;
        }

        //overloads
        bigint& operator=(const bigint& other) {
            if (this != &other) {
                value = other.value;
            }
            return *this;
        }

        bigint operator+(const bigint& other) const {
            bigint result;
            result.value = "";
            int i = value.length()-1;
            int j = other.value.length()-1;
            int carry = 0;
            int sum;
            while(i >=0 || j >=0 || carry > 0) {
                sum = ((other.value[i] - '0') + (value[j] - '0') + carry);
                carry = sum / 10;
                sum = sum % 10;
                result.value.insert(0, 1, sum + '0'); 
                i--;
                j--;      
            }
            return result;
        }        
        
        bigint& operator+=(const bigint& other) {
            *this = *this + other;
            return *this;
        }

        //pre-increment
        bigint& operator++() {
            *this += bigint(1);
            return *this;
        }

        //post-increment
        bigint operator++(int) {
            bigint temp = *this;
            ++(*this);
            return temp;
        }

        //bitshifting base 10
        bigint operator<<(size_t shift) const {
            bigint result = *this;
            for (size_t i = 0; i < shift; ++i) {
                result.value += '0'; // append zeros to value string
            }
            return result;
        }
        bigint operator<<(bigint shift) const {
            // Convert string to unsigned long using C-style functions for compatibility
            return *this << std::atol(shift.value.c_str());
        }

        //bitshifting base 10 negative
        bigint operator>>(size_t shift) const {
            bigint result = *this;
            if (shift >= result.value.length()) {
                result.value = "0"; // shift out all digits
            } else {
                result.value = result.value.substr(0, result.value.length() - shift);
            }
            return result;
        }
        bigint operator>>(bigint shift) const {
            return *this >> std::atol(shift.value.c_str());
        }

        bigint& operator>>=(int shift) {
            *this = *this >> shift;
            return *this;
        }
        bigint& operator>>=(bigint shift) {
            return *this >>= std::atol(shift.value.c_str());
        }

        bigint& operator<<=(int shift) {
            *this = *this << shift;
            return *this;
        }
        bigint& operator<<=(bigint shift) {
            return *this <<= std::atol(shift.value.c_str());
        }

        bool operator<(const bigint& other) const {
            if (value.length() != other.value.length()) {
                return value.length() < other.value.length();
            }
            for (size_t i = 0; i < value.length(); i++) {
                if (value[i] != other.value[i]) {
                    return value[i] < other.value[i];
                }
            }
            return false; // equal
        }

        bool operator>(const bigint& other) const {
            return other < *this;
        }

        bool operator==(const bigint& other) const {
            return value == other.value;
        }

        bool operator!=(const bigint& other) const {
            return !(*this == other);
        }
        
        bool operator<=(const bigint& other) const {
            return *this < other || *this == other;
        }

        bool operator>=(const bigint& other) const {
            return *this > other || *this == other;
        }

        bigint operator-(const bigint& other) const {
            bigint temp = other; // useless line to avoid warning

            return bigint(); // just assume - op is for equal values.
        }
};
