/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode.cn/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.42%)
 * Likes:    1190
 * Dislikes: 0
 * Total Accepted:    605.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 *
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 *
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 *
 *
 * 示例 2：
 *
 *
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 *
 *
 * 示例 3：
 *
 *
 * 输入：digits = [0]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 */

// @lc code=start
class Solution
{
public:
    // vector<int> plusOne(vector<int> &digits)
    // {
    //     int length = digits.size();
    //     for (int i = length - 1; i >= 0; --i)
    //     {
    //         //从后往前找到第一个不为9的元素，将该元素加一
    //         if (digits[i] != 9)
    //         {
    //             ++digits[i];
    //             for (int j = ++i; j < length; ++j)
    //             {
    //                 digits[j] = 0; //将后续所有的9都变为0
    //             }
    //             return digits;
    //         }
    //     }
    //     //若是所有数都为9，那么重新申请一块+1的内存，首位为1即可
    //     vector<int> result(++length);
    //     result[0] = 1;
    //     return result;
    // }

    // 学习优秀代码
    vector<int> plusOne(vector<int> &digits)
    {
        int length = digits.size();
        // 从后向前判断，为9当前位置0，并向前判断
        // 若不为9则当前为加1退出循环得到题意答案
        while (length && 10 == ++digits[--length])
            digits[length] = 0;
        // 不排除出现999这类数据，按上述循环最后得到000
        // 此时在最前面插入1即可
        if (0 == digits[0])
            digits.insert(begin(digits), 1);
        return digits;
    }
};
// @lc code=end
