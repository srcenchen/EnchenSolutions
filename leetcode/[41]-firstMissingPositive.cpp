//
// Created by sanenchen on 2026/09/24.
//
// 41. 缺失的第一个正数
// https://leetcode.cn/problems/first-missing-positive/

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] >= 1 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i]-1]);
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i+1) {
            return i+1;
        }
    }
    return nums.size()+1;
}

int main() {
    // 改这个数字切换官方样例：1 .. 3
    const int CASE = 1;

    vector<int> nums;
    if (CASE == 1) {
        nums = {1, 2, 0};
    } else if (CASE == 2) {
        nums = {3, 4, -1, 1};
    } else {
        nums = {7, 8, 9, 11, 12};
    }

    cout << firstMissingPositive(nums) << endl;
    return 0;
}
