#include <iostream>
#include <vector>
using namespace std;

class solution{
public:

    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return nums.size();
    }
};

int main()
{
    solution sol;

    vector<int> nums = {1,3,5,7};
    int target = 6;
    cout << "Insert position: " << sol.searchInsert(nums, target) << endl;

    return 0;
}