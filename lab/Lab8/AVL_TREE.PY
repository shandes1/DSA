class AVLNode:
    def __init__(self, key):
        self.key = key
        self.height = 1
        self.left = None
        self.right = None

def getHeight(node):
    return node.height if node else 0

def getBalance(node):
    return getHeight(node.left) - getHeight(node.right) if node else 0

def rightRotate(y):
    x = y.left
    T2 = x.right

    # Perform rotation
    x.right = y
    y.left = T2

    # Update heights
    y.height = 1 + max(getHeight(y.left), getHeight(y.right))
    x.height = 1 + max(getHeight(x.left), getHeight(x.right))

    return x

def leftRotate(x):
    y = x.right
    T2 = y.left

    # Perform rotation
    y.left = x
    x.right = T2

    # Update heights
    x.height = 1 + max(getHeight(x.left), getHeight(x.right))
    y.height = 1 + max(getHeight(y.left), getHeight(y.right))

    return y

def insert(node, key):
    # Normal BST insert
    if not node:
        return AVLNode(key)
    elif key < node.key:
        node.left = insert(node.left, key)
    elif key > node.key:
        node.right = insert(node.right, key)
    else: 
        return node 

    node.height = 1 + max(getHeight(node.left), getHeight(node.right))
    balance = getBalance(node)

    # Left Left case
    if balance > 1 and key < node.left.key:
        return rightRotate(node)

    # Right Right case
    if balance < -1 and key > node.right.key:
        return leftRotate(node)

    # Left Right case
    if balance > 1 and key > node.left.key:
        node.left = leftRotate(node.left)
        return rightRotate(node)

    # Right Left case
    if balance < -1 and key < node.right.key:
        node.right = rightRotate(node.right)
        return leftRotate(node)

    return node

def preOrder(root):
    if root:
        print(root.key, end=" ")
        preOrder(root.left)
        preOrder(root.right)


# Example usage
root = None
nums = [10, 20, 30, 40, 50, 25]
for num in nums:
    root = insert(root, num)

print("Preorder traversal after insertion:")
preOrder(root)
