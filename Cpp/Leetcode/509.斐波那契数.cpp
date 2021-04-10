/*
 * @Author       : Darcy
 * @Date         : 2021-04-10 09:12:57
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-10 09:23:12
 * @FilePath     : \HelloWorld\Cpp\Leetcode\509.斐波那契数.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
  public:
    int fib(int n) {
        int a = 1, b = 1, c = 0;
        for (int i = 2; i <= n; ++i) {
            a = b + c;
            c = b;
            b = a;
        }
        if (n == 0)
            return 0;
        return a;
    }
};
// @lc code=end
