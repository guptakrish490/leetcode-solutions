class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int t0 = 0, t2 = 1, t3 = 1;

        for (int i = 3; i <= n; i++) {
            int curr = t0 + t2 + t3;

            t0 = t2;
            t2 = t3;
            t3 = curr;
        }

        return t3;
    }
};