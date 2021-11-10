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

// another approach
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (auto it : nums)
        {
            if (max1 < it)
            {
                max1 = it;
                if (max2 < max1)
                {
                    max1 = max2;
                    max2 = it;
                }
            }
            if (min1 > it)
            {
                min1 = it;
                if (min2 > min1)
                {
                    min1 = min2;
                    min2 = it;
                }
            }
        }
        return ((max1 * max2) - (min1 * min2));
    }
};
" i'll explain for the max only min will work same :)" nums = [ 5, 6, 2, 7, 4 ]

    i hope you've understand the declaration part of variable

    after for loop 1)
    it = 5;
max1 = INT_MIN;
max2 = INT_MIN;
the first if condition will true;
so,
    max1 = 5;

2ns nested conditon is also true so,
    max1 = max2 // max2 = INT_MIN
        max2 = 5;

2) 
it = 6;
max1 = INT_MIN;
max2 = 5;
so,
    max1 < it(yes) // max1 = INT_MIN < 6
        max1 = 6;
max2 < max1(yes)
           max1 = max2 // max2 = 5;
    max2 = 6;

3) 
it = 2;
max1 = 5;
max2 = 6;
for 2 the condition is not true.

4) 
it = 7;
max1 = 5;
max2 = 6;
so,
    max1 < it // max1 = 5 < 7
               max1 = 7;
max2 < max1            // max2 = 6 < 7
           max1 = max2 // max2 = 6
    max2 = 7;

5)
it = 4;
max1 = 6;
max2 = 7;
so the condition is not true 
so we have the highest and the 2nd highest element from the vecotr 

for min it will work the same
