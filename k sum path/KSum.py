class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def dfs(node, currentSum, k, prefix):
    if not node:
        return 0

    currentSum += node.val

    count = prefix.get(currentSum - k, 0)

    prefix[currentSum] = prefix.get(currentSum, 0) + 1

    count += dfs(node.left, currentSum, k, prefix)
    count += dfs(node.right, currentSum, k, prefix)

    prefix[currentSum] -= 1

    return count


def pathSum(root, k):
    prefix = {0: 1}
    return dfs(root, 0, k, prefix)


# -------- main --------

# build example tree
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(-3)
root.left.left = TreeNode(3)
root.left.right = TreeNode(2)
root.right.right = TreeNode(11)
root.left.left.left = TreeNode(3)
root.left.left.right = TreeNode(-2)
root.left.right.right = TreeNode(1)

k = 8

result = pathSum(root, k)

print(result)