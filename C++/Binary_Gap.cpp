/*
Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.
*/

class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0, mask = 1, counter = 0;
        if (n == 1)
            return maxGap;
        while(n)
        {
            if((n & mask) && counter == 0)
            {
                counter +=1;
            }
            else if ((n & mask) && (counter != 0))
            {
                if(maxGap < counter)
                {
                    maxGap = counter;
                }
                counter = 1;
            }
            else if(counter != 0)
            {
                counter +=1;
            }

            n = n >> 1;
        }
        return maxGap;
    }
};