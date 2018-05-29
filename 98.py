# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def testValidity(self, root, maxVal, minVal):
        if root is None: return True
        if minVal < root.val < maxVal:
            return self.testValidity(root.left, root.val, minVal) and self.testValidity(root.right, maxVal, root.val)
        else: return False

    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        maxVal = sys.maxint
        minVal = -sys.maxint-1
        return self.testValidity(root, maxVal, minVal)