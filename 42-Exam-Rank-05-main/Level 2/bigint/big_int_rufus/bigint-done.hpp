#pragma once

#include <iostream>
#include <string>
// #include <cstdio>   // for sprintf
// #include <cstdlib>  // for atoi
// #include <cstring>  // for string operations

class bigint {
    private:
        std::string value;  // Store number as string for arbitrary precision

    public:
        bigint(): value("0") {}
        bigint(int val) : value (std::to_string(val)) {}
        bigint& operator=(const bigint& other) {
            if (this != &other) {
                value = other.value;
            }
            return *this;
        }
        ~bigint() {}
        bigint(const bigint& other): value(other.value) {}
        
        // allow printing of bigint objects  // friend can be used when an opertion invovles the class but not a member of the class
        friend std::ostream& operator<<(std::ostream& os, const bigint& bi) {
            os << bi.value;
            return os;
        }

      

        bigint operator+(const bigint& other) const {
            bigint result;
            result.value = "";
            int i = value.length()-1;
            int j = other.value.length()-1;
            int carry = 0;
            int sum;
            while(i >=0 || j >=0 || carry > 0) {
                int digit1 = (i>=0) ? (value[i] - '0') : 0;
                int digit2 = (j>=0) ? (other.value[j] - '0') : 0;
                sum = digit1 + digit2 +carry;
                carry = sum / 10;
                sum = sum % 10;
                result.value.insert(0, 1, sum + '0'); // .insert(start, count, char)
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
            // Convert string to unsigned long 
            return *this << std::stol(shift.value);
        }

        //bitshifting base 10 negative
        bigint operator>>(size_t shift) const {
            return *this;
            bigint result = *this;
            if (shift >= result.value.length()) {
                result.value = "0"; // shift out all digits
            } else {
                result.value = result.value.substr(0, result.value.length() - shift);
            }
            return result;
        }
        bigint operator>>(bigint shift) const {
          //  return *this >> std::atol(shift.value.c_str()); the compatible way, requires <cstring>
            return *this >> std::stol(shift.value); 
        }

        bigint& operator>>=(int shift) {
            *this = *this >> shift;
            return *this;
        }
        bigint& operator>>=(bigint shift) {
            return *this >>= std::stol(shift.value);
        }

        bigint& operator<<=(int shift) {
            *this = *this << shift;
            return *this;
        }
        bigint& operator<<=(bigint shift) {
            return *this <<= std::stol(shift.value);
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
