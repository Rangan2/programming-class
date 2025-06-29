#include <bits/stdc++.h>
using namespace std;

int searchInsertPos (vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return nums[mid];
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main () {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};

    int target = 11;

    int insertPos = searchInsertPos(nums, target);

    cout << "the inserted position should be : " << insertPos;
    
    return 0;
}


