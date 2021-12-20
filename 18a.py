from __future__ import annotations
from dataclasses import dataclass
from json import loads
from itertools import chain
from math import ceil
from typing import Generator


@dataclass
class TreeNode:
    parent: None | TreeNode = None
    val: int = 0
    left: None | TreeNode = None
    right: None | TreeNode = None


def calc_depth(node):
    d = 0
    while node.parent is not None:
        d += 1
        node = node.parent
    return d


def traverse_node(node: TreeNode) -> Generator[TreeNode, TreeNode, None]:
    if type(node.left) is not TreeNode:
        yield node
    if type(node.left) is TreeNode:
        yield from traverse_node(node.left)
    if type(node.right) is TreeNode:
        yield from traverse_node(node.right)


def to_tree_node(node: TreeNode, data) -> None:
    if type(data) is int:
        node.val = data
    else:
        node.left = TreeNode(node)
        node.left.parent = node
        to_tree_node(node.left, data[0])

        node.right = TreeNode(node)
        node.right.parent = node
        to_tree_node(node.right, data[1])


def addition(node1: None | TreeNode, node2: None | TreeNode) -> None | TreeNode:
    if node1 is None:
        return node2
    if node2 is None:
        return node1
    parent = TreeNode()
    node1.parent = parent
    node2.parent = parent
    parent.left = node1
    parent.right = node2
    return parent


def print_tree(tree: None | TreeNode) -> None:
    if tree is None:
        print("[]")
        return
    for node in traverse_node(tree):
        print(node.val, end=" ")
    print()


def explode(tree: None | TreeNode) -> bool:
    if tree is None:
        return False

    it = iter(chain(traverse_node(tree), [None]))
    prev_node = None
    node = None
    for node in it:
        if node is None or calc_depth(node) <= 4:
            prev_node = node
            continue

        # Add values to left
        if prev_node is not None:
            prev_node.val += node.val
        # Exploding values are in pairs
        pair_node = next(it)
        next_node = next(it)
        if next_node is not None:
            next_node.val += pair_node.val

        # Delete node
        parent = node.parent
        parent.left = None
        parent.right = None
        parent.val = 0

        return True

    return False


def split(tree: None | TreeNode) -> bool:
    if tree is None:
        return False

    for node in traverse_node(tree):
        if node.val >= 10:
            node.left = TreeNode(node, node.val // 2)
            node.right = TreeNode(node, ceil(node.val / 2))
            node.val = 0
            return True
    return False


def reduce(tree: TreeNode) -> None:
    if explode(tree) or split(tree):
        print("=", end=" ")
        print_tree(tree)
        reduce(tree)
    return tree


def calc_magnitude(tree: TreeNode) -> int:
    tree_list = [(calc_depth(node), node.val) for node in traverse_node(tree)]

    def reduce_pair():
        next_tree_list = []
        it = iter(tree_list)
        prev_dep = 0
        prev_val = 0
        for t in it:
            dep, val = t
            if dep == prev_dep:
                next_tree_list.pop()
                next_tree_list.append((dep-1, 3*prev_val+2*val))
                next_tree_list += [*it]
            else:
                next_tree_list.append(t)
            prev_dep, prev_val = t
        return next_tree_list

    while len(tree_list) > 1:
        tree_list = reduce_pair()
    return tree_list[0][1]


def main() -> None:
    tree = None
    try:
        while line := input():
            data = loads(line)
            tree0 = TreeNode()
            to_tree_node(tree0, data)

            print_tree(tree)
            print("+", end=" ")
            print_tree(tree0)

            tree = addition(tree, tree0)
            reduce(tree)
            print()
    except EOFError:
        pass
    print(calc_magnitude(tree))

main()