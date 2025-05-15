/*
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1; // Any number raised to the power 0 is 1
        if (x == 0) return 0; // 0 raised to any power is 0

        long long exp = n; // Use long long to handle INT_MIN
        if (exp < 0) {
            x = 1 / x;
            exp = -exp; // Make the exponent positive
        }
        double ans = 1;

        while (exp > 0) {
            if (exp % 2 == 1) { // If the current exponent is odd
                ans *= x;
            }
            x *= x; // Square the base
            exp /= 2; // Halve the exponent
        }

        return ans;
    }
};
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1 || (x == -1 && n%2 == 0)) return 1.0;
        if (x == 0) return 0.0;
        if (x == -1 && n %2 != 0) return -1.0;
        long binForm = n;
        if(n<0){
            x = 1/x;
            binForm = -binForm;
        }
        double ans = 1;

        while(binForm > 0){
            if(binForm % 2 == 1){
                ans = ans * x;
            }
            x = x * x;
            binForm = binForm / 2;
        }

        return ans;
    }
};



