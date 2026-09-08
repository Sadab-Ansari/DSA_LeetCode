class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        
        for (int digits = 4; digits <= 10; digits++) {
            long long start = 1;
            
            for (int i = 1; i < digits; i++) {
                start *= 10;
            }
            
            long long end = start * 10 - 1;
            
            if (start > n)
                break;
            
            end = min((long long)n, end);
            
            long long count = end - start + 1;
            int commas = (digits - 1) / 3;
            
            ans += count * commas;
        }
        
        return ans;
    }
};