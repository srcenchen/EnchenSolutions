#include <bits/stdc++.h>
using namespace std;

// 哈希表做法
int findFinalValue1(vector<int>& nums, int original) {
    unordered_map<int, int> cnt;
    for (auto& i : nums) {
        cnt[i]++;
    }
    while (cnt[original] != 0) {
        original *= 2;
    }
    return original;
}

int lowerBound(vector<int>& nums, int target) {
    int left = -1, right = nums.size(); // (left, right) 开区间
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid; // 答案在左侧或就是mid，收缩右边界
        else 
            left = mid;  // 答案在右侧，收缩左边界
    }
    return right; 
}

// 返回最后一个 <= target 的下标 (Upper Bound)
int upperBound(vector<int>& nums, int target) {
    int left = -1, right = nums.size(); // (left, right) 开区间
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
            left = mid;  // 答案在右侧或就是mid，收缩左边界
        else 
            right = mid; // 答案在左侧，收缩右边界
    }
    return left; 
}
// 二分查找做法
int findFinalValue(vector<int>& nums, int original) {
    sort(nums.begin(), nums.end());
    while (lowerBound(nums, original) != nums.size() && nums[lowerBound(nums, original)] == original) {
        original *= 2;
    }
    return original;
}
// [LC-2164]
int main() {
    vector<int> nums = {2,7,9};
    cout << findFinalValue(nums, 4);
    return 0;
}