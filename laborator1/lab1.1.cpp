#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    Solution s;
    vector<int> result = s.runningSum(nums);

    for (int x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}