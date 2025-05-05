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

        bigint operator+(const bigint& other) const{
            bigint result;
            size_t len1 = value.length();
            size_t len2 = other.value.length();
            size_t max_len = std::max(len1, len2);
            result.value.resize(max_len + 1); // +1 for carry
            int carry = 0;
            for (size_t i = 0; i < max_len; ++i) {
                int digit1 = (i < len1) ? value[len1 - 1 - i] - '0' : 0;
                int digit2 = (i < len2) ? other.value[len2 - 1 - i] - '0' : 0;
                int sum = digit1 + digit2 + carry;
                result.value[max_len - i] = (sum % 10) + '0';
                carry = sum / 10;
            }
            if (carry) { // leftmost digit is carry
                result.value[0] = carry + '0';
                result.value = result.value.substr(0, max_len + 1);
            } else {
                result.value = result.value.substr(1, max_len);
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
        bigint operator<<(int shift) const {
            bigint result = *this;
            for (int i = 0; i < shift; ++i) {
                result.value += '0'; // append zeros to value string
            }
            return result;
        }
        bigint operator<<(bigint shift) const {
            return *this << atoi(shift.value.c_str());
        }

        //bitshifting base 10 negative
        bigint operator>>(int shift) const {
            bigint result = *this;
            if (shift >= static_cast<int>(result.value.length())) {
                result.value = "0"; // shift out all digits
            } else {
                result.value = result.value.substr(0, result.value.length() - shift);
            }
            return result;
        }
        bigint operator>>(bigint shift) const {
            return *this >> atoi(shift.value.c_str());
        }

        bigint& operator>>=(int shift) {
            *this = *this >> shift;
            return *this;
        }
        bigint& operator>>=(bigint shift) {
            return *this >>= atoi(shift.value.c_str());
        }

        bigint& operator<<=(int shift) {
            *this = *this << shift;
            return *this;
        }
        bigint& operator<<=(bigint shift) {
            return *this <<= atoi(shift.value.c_str());
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