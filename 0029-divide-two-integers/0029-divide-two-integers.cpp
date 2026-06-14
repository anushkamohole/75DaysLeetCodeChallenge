class Solution {
public:
    int divide(int dividend, int divisor) {
        // 1. Handle the strict overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // 2. Determine the sign of the result using XOR
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // 3. Convert to long long to prevent overflow issues
        long long absDividend = std::abs((long long)dividend);
        long long absDivisor = std::abs((long long)divisor);

        long long quotient = 0;

        // 4. Outer loop: Keep going as long as we can subtract the divisor
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // 5. Inner loop: Keep doubling until it's too big
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // 6. Subtract the massive chunk we found
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        // 7. Apply the correct sign to the result
        return isNegative ? -quotient : quotient;
    }
};