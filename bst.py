def insert(tree, value):
    index = 0  # Start from root
    while index < len(tree):
        if tree[index] == -1:
            tree[index] = value
            return
        elif value < tree[index]:
            index = 2 * index + 1  # Go to left child
        else:
            index = 2 * index + 2  # Go to right child

def collect_subtree_values(tree, index):
    if index >= len(tree) or tree[index] == -1:
        return []
    left = collect_subtree_values(tree, 2 * index + 1)
    right = collect_subtree_values(tree, 2 * index + 2)
    return left + [tree[index]] + right

def left_tree_size(tree):
    tree_left_node = [-1] * len(tree)
    for i in range(len(tree)):
        if tree[i] == -1:
            continue
        subtree = collect_subtree_values(tree, i)
        smaller = [val for val in subtree if val < tree[i]]
        tree_left_node[i] = len(smaller) + 1  # +1 includes itself
    return tree_left_node


# Main program
data = [15, 6, 24, 18, 12, 3, 7, 1, 4, 17, 9, 10]
SIZE = 2 ** 4
tree = [-1] * SIZE

for val in data:
    insert(tree, val)

print("\nBinary Search Tree as array:")
print(tree)

print("\nLeft tree size (count of smaller values in subtree + 1):")
print(left_tree_size(tree))