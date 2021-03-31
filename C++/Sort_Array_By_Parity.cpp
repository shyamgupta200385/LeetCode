/*
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int loop = 0;
        int size = A.size()-1;
        for(loop;loop<size;)
        {
            if((A[loop]%2))
            {
                swap(A[loop], A[size]);
                --size;
            }
            else
                ++loop;
        }
        return A;
    }
};