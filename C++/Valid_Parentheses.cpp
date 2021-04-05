/**
 Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 An input string is valid if:

 Open brackets must be closed by the same type of brackets.
 Open brackets must be closed in the correct order.
  

 Example 1:

 Input: s = "()"
 Output: true
 Example 2:

 Input: s = "()[]{}"
 Output: true
 Example 3:

 Input: s = "(]"
 Output: false
 Example 4:

 Input: s = "([)]"
 Output: false
 Example 5:

 Input: s = "{[]}"
 Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        unsigned long strlen = s.length();
        char buff[strlen];
        int top = -1;
        int loop = 0;
        const string comp = "()[]{}";
        if(strlen == 1)
            return false;
        if(s[0] == comp[1] || s[0] == comp[3] || s[0] == comp[5] )
            return false;
        while(loop < strlen)
        {
            if (top == (strlen - 1))
                return false;
            else if(s[loop] == comp[0] || s[loop] == comp[2] || s[loop] == comp[4] )
                buff[++top] = s[loop];
            else
            {
                if(top != -1)
                {
                    if(s[loop] == comp[1])
                    {
                        if(buff[top--] != comp[0])
                            return false;
                    }
                    else if(s[loop] == comp[3])
                    {
                        if(buff[top--] != comp[2])
                            return false;
                    }
                    else if(s[loop] == comp[5])
                    {
                        if(buff[top--] != comp[4])
                            return false;
                    }
                    else{
                        return false;
                    }
                }
                else
                    return false;
            }
            loop +=1;
        }
        if(top != -1)
            return false;
        else
            return true;
    }
};
