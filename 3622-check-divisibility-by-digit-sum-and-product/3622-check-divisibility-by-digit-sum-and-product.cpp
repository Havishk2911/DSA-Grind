#include <iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;

        while (temp > 0) {
            int digit = temp % 10;

            sum += digit;
            product *= digit;

            temp /= 10;
        }

        int value = sum + product;

        return n % value == 0;
    }
};