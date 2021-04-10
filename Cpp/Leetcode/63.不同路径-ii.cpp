/*
 * @Author       : Darcy
 * @Date         : 2021-04-10 11:32:09
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-04-10 16:17:03
 * @FilePath     : \HelloWorld\Cpp\Leetcode\63.不同路径-ii.cpp
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (37.94%)
 * Likes:    526
 * Dislikes: 0
 * Total Accepted:    133.9K
 * Total Submissions: 353K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 *
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 *
 *
 *
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 * 解释：
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 *
 *
 * 示例 2：
 *
 *
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1
 * obstacleGrid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        auto m = obstacleGrid.size();
        auto n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        int solu[m][n];
        if (obstacleGrid[0][0] == 0)
            solu[0][0] = 1;
        else
            solu[0][0] = 0;
        for (int i = 1; i < static_cast<int>(n); ++i) {
            if (obstacleGrid[0][i] == 1)
                solu[0][i] = 0;
            else
                solu[0][i] = solu[0][i - 1];
        }

        for (int i = 1; i < static_cast<int>(m); ++i) {
            if (obstacleGrid[i][0] == 1)
                solu[i][0] = 0;
            else
                solu[i][0] = solu[i - 1][0];
        }
        for (int x = 1; x < static_cast<int>(m); ++x)
            for (int y = 1; y < static_cast<int>(n); ++y) {
                if (obstacleGrid[x - 1][y] == 0)
                    solu[x][y] = solu[x - 1][y];
                else
                    solu[x][y] = 0;
                if (obstacleGrid[x][y - 1] == 0)
                    solu[x][y] += solu[y][y - 1];
            }
        return solu[m - 1][n - 1];
    }
};
// @lc code=end
