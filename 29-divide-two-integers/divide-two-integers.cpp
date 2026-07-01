class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        
        bool sign = true;
        if (dividend >= 0 && divisor < 0) sign = false;
        else if (dividend <= 0 && divisor > 0) sign = false;
        
        // Use long long to completely prevent absolute value overflow
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        
        long long quotient = 0;
        while (n >= d) {
            int cnt = 0;
            // Prevent overflow by making sure we don't shift past n
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += (1LL << cnt);
            n -= (d << cnt);
        }
        
        // Handle 32-bit integer overflow edge cases
        if (quotient == (1LL << 31) && sign) return INT_MAX;
        if (quotient == (1LL << 31) && !sign) return INT_MIN;
        
        return sign ? quotient : -quotient;
    }
};