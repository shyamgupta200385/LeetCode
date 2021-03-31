/*
Input: nums = [1,2,0]
Output: 3

Input: nums = [3,4,-1,1]
Output: 2
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int smallestMissingPositive = 1;
        int size = nums.size();
        
        while(size)
        {
        	if ( find(nums.begin(), nums.end(), smallestMissingPositive) != nums.end() )
        	{
        		smallestMissingPositive +=1;
        	}
        	else
        	{
        		return smallestMissingPositive;
        	}
        }
        return smallestMissingPositive;
        
    }
};
