class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        i=0
        j=0
        star_p = -1
        star_s = -1
        while i<len(s):
            if j<len(p) and (p[j] == '?' or s[i] == p[j]):
                i = i + 1
                j = j + 1
                continue
            if j<len(p) and p[j] == '*':
                star_p = j
                star_s = i
                j = j + 1
                continue
            if star_p != -1:
                star_s = star_s + 1
                i = star_s
                j = star_p + 1
                continue
            return False

        while j<len(p):
            if p[j] != '*':
                return False
            j = j + 1
        return True