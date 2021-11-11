Intution :

    Idea is really very simple.Since the contraints are very small i.e value of m,
    we can use brute force approach.

    For every range,
    we need to first store the subarray in a temporary vector.Range will be l[i] to r[i]

    vector<int>
        temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
Then, sort this vector to get a proper increasing seq. so that we can check for common difference d. Also, it should be equal to difference of first two elements.

  sort(temp.begin(), temp.end());          // Sort to get a increasing AP sequence
int diff = temp[1] - temp[0];              // Common Difference
Now for every consecutive element i.e temp[i] - temp[i-1] check if their difference is equal to common difference or not. If no, then break and add false to result. Otherwise continue checking.

  for(int j=2; j <= r[i]-l[i]; j++)
{
    if (temp[j] - temp[j - 1] != diff)
    {
        flag = true;
        break;
    }
}
res.push_back(!flag);
Also, in the beginning we can check if range from l[i] to r[i] is less than 2, then simply add true.Because a sequence of size less that 2 is always a AP.

                                                                               if (r[i] - l[i] < 2) res.push_back(true);

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{

    vector<bool> res;
    for (int i = 0; i < l.size(); i++) // O(m)
    {
        if (r[i] - l[i] < 2)
            res.push_back(true);
        else
        {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1); // O(n) , creating subarray
            sort(temp.begin(), temp.end());                                 // O(n^2 * log(n))  , sorting
            bool flag = false;
            int diff = temp[1] - temp[0];
            for (int j = 2; j <= r[i] - l[i]; j++) // O(n) , check if subarray is AP
            {
                if (temp[j] - temp[j - 1] != diff)
                {
                    flag = true;
                    break;
                }
            }
            res.push_back(!flag);
        }
    }
    return res;
}
Time : O(m * n * log n)
-> O(m) to iterate over the range vector,
-> O(n + n log n + n) = O(2n + nlogn) ~ O(n log(n)) to form subarray and sort and checking for every range.
Space : O(n) -> worst case when r[i] - l[i] = n