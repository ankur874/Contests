template <typename t>
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return (nums[nums.length()-1]*nums[nums.length()-2])-(nums[0]*nums[1]);
    }
};