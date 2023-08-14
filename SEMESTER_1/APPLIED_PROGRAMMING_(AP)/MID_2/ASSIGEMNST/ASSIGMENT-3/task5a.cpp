#include <iostream>
#include <vector>

using namespace std;

#define LL long long
const int mod = 1000000007;

class Solution {
private:
    vector<LL> fact;

    LL power(LL x, LL y) 
    {
        LL tot = 1, p = x;
        for (; y; y >>= 1) 
        {
            if (y & 1)
                tot = tot * p % mod;
            p = p * p % mod;
        }

        return tot;
    }

    LL select(int n, int m) 
    {
        return fact[n] * power(fact[m], mod - 2) % mod * power(fact[n - m], mod - 2) % mod;
    }

    int solve(const vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 1;

        vector<int> lo, hi;
        const int n = nums.size();

        for (int i = 1; i < n; i++) 
        {
            if (nums[i] < nums[0]) lo.push_back(nums[i]);
            else hi.push_back(nums[i]);
        }

        return select(n - 1, lo.size()) * solve(lo) % mod * solve(hi) % mod;
    }

public:
    int numOfWays(vector<int>& nums) 
    {
        const int n = nums.size();
        fact.resize(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i % mod;

        return (solve(nums) - 1 + mod) % mod;
    }
};

int main()
{
    vector<int> vec = { 3,4,5,1,2 };

    Solution solution;
    int num_of_ways = solution.numOfWays(vec);
    cout << "number of ways: " << num_of_ways << endl;

    return 0;
}