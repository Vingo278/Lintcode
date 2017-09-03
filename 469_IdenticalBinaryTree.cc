#include <iostream>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right =NULL;
  }
};

/*
 * 递归遍历即可，左右子树一样，当前结点一样，就是一样
 * @param a: the root of binary tree a.
 * @param b: the root of binary tree b.
 * @return: true if they are identical, or false.
 */
bool isIdentical(TreeNode * a, TreeNode * b) {
  // 都为NULL，说明一样
  if (!a && !b) return true;
  // 一个为NULL，一个不是，说明不一样
  if (!a || !b) return false;
  // 剩下的就是两个都不是NULL
  if (a->val == b->val && isIdentical(a->left, b->left) &&
      isIdentical(a->right, b->right)) {
    return true;
  } else {
    return false;
  }
}
