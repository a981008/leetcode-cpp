/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 * 
 * 找规律，找不到就背
 * 
 * n = k 时
 * 1. 先复制 n = k - 1 的一份
 * 2. 做个上下对称
 * 3. 上面补 0， 下面补 1
 * 
 * 举例：
 * n = 0, 什么都没有
 * n = 1, 0
 *        1
 * n = 2, 0 0  
 *        1 0
 *        1 1
 *        0 1
 * n = 3, 0 0 0
 *        1 0 0
 *        1 1 0
 *        0 1 0
 *        0 1 1
 *        1 1 1
 *        1 0 1
 *        0 0 1
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        while (n--) {
            for (int i = res.size() - 1; i >= 0; i--) {
                res[i] <<= 1;
                res.push_back(res[i] | 1);
            }
        }
        return res;
    }
};
// @lc code=end

