
#'A': Absent.
#'L': Late.
#'P': Present.

#You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

#Input: s = "PPALLP"
#Output: true
#Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.

#Input: s = "PPALLL"
#Output: false
#Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.

class Solution:
    def checkRecord(self, s: str) -> bool:
        P1 = '[L]{3}'
        P2 = '[A]'
        match2 = len(re.findall(P2, s))
        if re.search(P1, s) or (match2 >= 2 ):
            return False
        else:
            return True
