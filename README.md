Complete an AVL tree Nth largest operation as described below, based on the partially completed files provided below.

Step 1: Inspect the BSTNode.h and BinarySearchTree.h files
Inspect the BSTNode class declaration for a binary search tree node in BSTNode.h. The BSTNode class has private member variables for the key, parent pointer, left child pointer, and right child pointer. Accessor functions exist for each.

Inspect the BinarySearchTree class declaration for a binary search tree node in BinarySearchTree.h. The GetNthKey() function is the only pure virtual function that exists.

Step 2: Inspect other classes related to the inheritance hierarchy
Classes AVLNode and AVLTree inherit from BSTNode and BinarySearchTree, respectively. Each class is implemented in a read only header.

Classes ExtendedAVLNode and ExtendedAVLTree are declared, but implementations are incomplete. Both classes must be implemented in this lab.



Step 3: Understand the purpose of the subtreeKeyCount variable
The ExtendedAVLNode class inherits from AVLNode and adds one integer member variable, subtreeKeyCount. Each node's subtree key count is the number of keys in the subtree rooted at that node. Example:



ExtendedAVLNode's constructor and GetSubtreeKeyCount() member functions are already implemented and should not be changed. Additional member functions are needed to ensure that subtreeKeyCount remains accurate.

Step 4: Implement ExtendedAVLTree and ExtendedAVLNode
Each node in an ExtendedAVLTree must have a correct subtreeKeyCount after an insertion or removal operation. Determine which member functions in AVLTree and AVLNode must be overridden in ExtendedAVLTree and ExtendedAVLNode to keep each node's subtreeKeyCount correct. New functions can be added along with overridden functions, if desired.

Hint: Consider an UpdateSubtreeKeyCount() member function for the ExtendedAVLNode class. The function requires each child node's subtreeKeyCount to be correct, and updates the node's subtreeKeyCount appropriately. Overridden functions in both ExtendedAVLNode and ExtendedAVLTree can call a node's UpdateSubtreeKeyCount() function as needed.

Once determinations are made, complete the implementation of both the ExtendedAVLTree and ExtendedAVLNode classes. Do not implement ExtendedAVLTree's GetNthKey() in this step. GetNthKey() requires correct subtree counts at each node.

Step 5: Run tests
TreeTestCommand is an abstract base class defined in TreeCommands.h. A TreeTestCommand object is an executable command that operates on a binary search tree. Classes inheriting from TreeTestCommand are also declared in TreeCommands.h:

TreeInsertCommand inserts keys into the tree
TreeRemoveCommand removes keys from the tree
TreeVerifyKeysCommand verifies the tree's keys using an inorder traversal
TreeVerifySubtreeCountsCommand verifies that each node in the tree has the expected subtree key count
TreeGetNthCommand verifies that GetNthKey() returns an expected value
Code in main.cpp contains three automated test cases. Each test executes a vector of TreeTestCommand objects in sequence. The third test includes TreeGetNthCommands and will not pass until the completion of Step 6. The first two tests should pass after completion of step 4.

Before proceeding to Step 6, ensure that the first two tests in main.cpp pass.

Step 6: Implement ExtendedAVLTree's GetNthKey() member function (worst case O(log n))
GetNthKey() must return the tree's nth-largest key. The parameter n starts at 0 for the smallest key in the tree. Ex: Suppose a tree has keys:

10, 19, 20, 30, 42, 55, 77
Then GetNthKey(0) returns 10, GetNthKey(1) returns 19, ..., GetNthKey(5) returns 55, and GetNthKey(6) returns 77.

Determine an algorithm that uses the subtree key counts so that GetNthKey() operates in worst case O(log n) time.
