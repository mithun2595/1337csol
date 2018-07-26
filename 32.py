def longestValidParentheses(self, s):
    """
    :type s: str
    :rtype: int
    """
    maxans = 0
    dp = [0]*len(s)
    for i in range(len(s)):
        if s[i] == ')':
            if i > 0 and s[i-1] == '(':
                dp[i] = dp[i-2] + 2
            if i > 0 and s[i-1] == ')':
                if i - dp[i-1] > 0 and s[i - dp[i-1] - 1] == '(':
                    if i - dp[i-1] - 1 > 0:
                        dp[i] = dp[i-1] + dp[i - dp[i-1] - 2] + 2
                    else:
                        dp[i] = dp[i-1] + 2
            if maxans < dp[i]:
                maxans = dp[i]
    return maxans