/**
 Note:
 It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

 You may assume that the input format is always valid.

 For example, it could never contain two consecutive commas, such as "1,,3".
 
 Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
 Output: true
 
 Input: preorder = "1,#"
 Output: false
 
 Input: preorder = "9,#,#,1"
 Output: false
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        unsigned long strlength = preorder.length();
        int rootNode = 1;
        for (int loop = 0 ;loop < strlength;loop++)
        {
            if(preorder.at(loop) == ',') continue;
            if((preorder.at(loop) != '#') && (loop != strlength-1)) {
                if (preorder.at(loop + 1)!=',')
                    continue;
            }
            if (--rootNode < 0) return false;
            if (preorder.at(loop) != '#') rootNode += 2;
        }
        return rootNode == 0;
    }
};

