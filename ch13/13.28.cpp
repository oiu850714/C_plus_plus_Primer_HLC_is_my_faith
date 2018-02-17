#include <string>

class TreeNode {
private:
  std::string value;
  int *count;
  // SEE:
  // https://github.com/Mooophy/Cpp-Primer/tree/master/ch13#exercise-1328-hpp--cpp
  // It's make more sense if count is declared as int*
  TreeNode *left;
  TreeNode *right;

public:
  TreeNode(const std::string &s = std::string())
      : value(s), count(new int(0)), left(nullptr), right(nullptr) {}
  TreeNode(const TreeNode &node)
      : value(node.value), count(node.count), left(node.left),
        right(node.right) {
    ++*count;
  }

  ~TreeNode() {
    if (--*count == 0) {
      delete count;
      delete left; // delete left and right will call destructor of objects
                   // recursively to which left and right point to respectively.
      delete right; // So tree rooted at this node will be deleted entirely.
    }
  }
  TreeNode &operator=(const TreeNode &rhs) {
    ++*rhs.count;
    if (--*count == 0) {
      delete count;
      delete left;
      delete right;
    }
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
  }
};

class BinStrTree {
private:
  TreeNode *root;

public:
  BinStrTree() : root(new TreeNode()) {}
  BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) {
    // After copy BinStrTree, two BinStrTree object will point to same
    // underlying tree(reference count will be incremented), but the whole tree
    // will be automatically deleted when no BinStrTree object points to it.
    // if root's initializer is just bst.root, root will also point to same
    // tree, but the associated counter will not be incremented
  }

  ~BinStrTree() { delete root; }
  BinStrTree &operator=(const BinStrTree &bst) {
    TreeNode *newroot = new TreeNode(*bst.root);
    delete root;
    root = newroot;
    return *this;
  }
};