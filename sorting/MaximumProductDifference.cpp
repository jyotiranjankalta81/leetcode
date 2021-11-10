class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int result = 0, n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        result = (nums[n] * nums[n - 1]) - (nums[0] * nums[1]);

        return result;
    }
};