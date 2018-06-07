class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        seen_map = {}
        max_len = 0
        len_last = 0
        for i in range(len(s)):
            l = s[i]
            if l in seen_map:
                len_last = min(i - seen_map[l] - 1, len_last) + 1
                seen_map[l] = i
            else:
                len_last += 1
                seen_map[l] = i
            if len_last >= max_len:
                max_len = len_last
        return max_len


