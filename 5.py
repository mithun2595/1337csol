class Solution(object):
    def longestPalindrome(self, s):
        N=len(s)
        max_str=''
        for i in range(N):
            j=1
            while i-j>=0 and i+j<N and s[i-j]==s[i+j]:
                j+=1
            mstr=s[i-j+1:i+j]
            if len(mstr)>len(max_str):
                max_str=mstr

            j=0
            while i-j-1>=0 and i+j<N and s[i-j-1]==s[i+j]:
                j+=1
            mstr=s[i-j:i+j]
            if len(mstr)>len(max_str):
                max_str=mstr

        return max_str