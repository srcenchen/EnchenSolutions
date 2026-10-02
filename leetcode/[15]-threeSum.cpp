//
// Created by sanenchen on 2026/09/24.
//
// 15. 三数之和
// https://leetcode.cn/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i +1; j<n;++j) {
            for (int k = j + 1; k < n; ++k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    sort(tmp.begin(), tmp.end());
                    ans.insert(tmp);
                }
            }
        }
    }
    vector<vector<int>> ans1;
    for (auto& i : ans) {
        ans1.push_back(i);
    }
    return ans1;
}

int main() {
    // 改这个数字切换官方样例：1 .. 3
    const int CASE = 1;

    vector<int> nums;
    if (CASE == 1) {
        nums = {-1, 0, 1, 2, -1, -4};
    } else if (CASE == 2) {
        nums = {0, 1, 1};
    } else {
        nums = {0, 0, 0};
    }

    auto ans = threeSum(nums);
    cout << "[";
    for (size_t i = 0; i < ans.size(); i++) {
        if (i) cout << ",";
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); j++) {
            if (j) cout << ",";
            cout << ans[i][j];
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}
