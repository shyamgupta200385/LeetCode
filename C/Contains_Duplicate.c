/*
Input: nums = [1,2,3,1]
Output: true

Input: nums = [1,2,3,4]
Output: false
*/

bool containsDuplicate(int* nums, int numsSize){

    int result, outerloop, innerloop;
    int* local = nums;
    for(outerloop = numsSize-1;outerloop>=0;outerloop--)
    {
        for(innerloop = outerloop;innerloop>=0;innerloop--)
        {
            result = local[outerloop] ^ local[innerloop-1];
            if(result == 0)
                return true;
        }
    }
    
    return false;
}
