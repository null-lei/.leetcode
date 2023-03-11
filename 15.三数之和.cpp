/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (36.73%)
 * Likes:    5726
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
 * k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 *
 * 你返回所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution
{
public:
    // 暴力法三重循环，时间复杂度O(N^3),会超时
    // 以用例[-1,0,1,2,-1,-4]为例
    // 排序后[-4,-1,-1,0,1,2],当有两个-1，当循环到第二个i不跳过的话会有两组相同的三元组
    // vector<vector<int>> threeSum(vector<int> &nums)
    // {
    //     int length = nums.size();
    //     vector<vector<int>> result;
    //     sort(nums.begin(), nums.end()); // 排序方便剔除相同三元组

    //     for (int i = 0; i < length - 2; ++i)
    //     {
    //         if (0 != i && nums[i] == nums[i - 1])
    //             continue; //排查相同的数，避免重复循环做无用功
    //         for (int j = i + 1; j < length; ++j)
    //         {
    //             if (i != j - 1 && nums[j] == nums[j - 1])
    //                 continue;
    //             for (int k = j + 1; k < length; ++k)
    //             {
    //                 if (!(j != k - 1 && nums[k] == nums[k - 1])
    //                 && 0 == nums[i] + nums[j] + nums[k])
    //                 {
    //                     vector<int> threeNums = {nums[i], nums[j], nums[k]};
    //                     result.push_back(threeNums);
    //                 }
    //             }
    //         }
    //     }

    //     return result;
    // }

    // 双指针法，要求数组是有序的，固定i的位置，后两位数j，k为左右指针
    // vector<vector<int>> threeSum(vector<int> &nums)
    // {
    //     int length = nums.size();
    //     vector<vector<int>> result;
    //     sort(nums.begin(), nums.end());

    //     for (int i = 0; i < length - 2; ++i)
    //     {
    //         int left = i + 1;
    //         int right = length - 1;
    //         if (0 != i && nums[i] == nums[i - 1]) // 剔除重复元素
    //             continue;
    //         while (left < right)
    //         {
    //             if (0 == nums[i] + nums[left] + nums[right])
    //             {
    //                 result.push_back({nums[i], nums[left], nums[right]});
    //                 ++left;
    //                 --right;
    //                 while (left < right && nums[left] == nums[left - 1]) // 左指针不做重复运算
    //                     ++left;
    //                 while (left < right && nums[right] == nums[right + 1]) // 右指针不做重复运算
    //                     --right;
    //             }
    //             else if (0 > nums[i] + nums[left] + nums[right])    //三数和<0时，nums[left]太小，右移
    //                 ++left;
    //             else    //三数和>0时，nums[right]太大，左移
    //                 --right;
    //         }
    //     }

    //     return result;
    // }

    // 哈希法
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int length = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < length; i++)
        {
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1]) // 三元组元素a去重
                continue;

            unordered_set<int> set;
            for (int j = i + 1; j < length; j++)
            {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                { // 三元组元素b去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end())
                {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c); // 三元组元素c去重
                }
                else
                {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};
// @lc code=end
