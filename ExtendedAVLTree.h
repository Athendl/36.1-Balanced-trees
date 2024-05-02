//My Code (Edited from teachers)
#ifndef EXTENDEDAVLTREE_H
#define EXTENDEDAVLTREE_H

#include "AVLTree.h"
#include "ExtendedAVLNode.h"

class ExtendedAVLTree : public AVLTree {
protected:
   // Each node in an ExtendedAVLTree is an ExtendedAVLNode
   virtual BSTNode* MakeNewNode(int key) override {
      return new ExtendedAVLNode(key);
   }

   // Update the subtree key count of a node
   virtual void UpdateSubtreeKeyCount(ExtendedAVLNode* node) {
      int leftCount = (node->GetLeft()) ? static_cast<ExtendedAVLNode*>(node->GetLeft())->GetSubtreeKeyCount() : 0;
      int rightCount = (node->GetRight()) ? static_cast<ExtendedAVLNode*>(node->GetRight())->GetSubtreeKeyCount() : 0;
      node->SetSubtreeKeyCount(leftCount + rightCount + 1); // Use a setter function to update the private member
   }

   // Override InsertNode to update subtree key counts
   virtual void InsertNode(BSTNode* node) override {
      // AVL insertion starts with the standard BST insertion
      AVLTree::InsertNode(node);

      // Then rebalancing occurs along a path from the new node's parent up to the root.
      node = static_cast<AVLNode*>(node->GetParent());
      while (node) {
         Rebalance(static_cast<AVLNode*>(node));
         node = static_cast<AVLNode*>(node->GetParent());
      }

      // Update subtree key counts
      while (node) {
         UpdateSubtreeKeyCount(static_cast<ExtendedAVLNode*>(node));
         node = static_cast<ExtendedAVLNode*>(node->GetParent());
      }
   }

   // Override RemoveNode to update subtree key counts
   virtual bool RemoveNode(BSTNode* nodeToRemove) override {
      bool removed = AVLTree::RemoveNode(nodeToRemove);

      // Update subtree key counts
      while (nodeToRemove) {
         UpdateSubtreeKeyCount(static_cast<ExtendedAVLNode*>(nodeToRemove));
         nodeToRemove = static_cast<ExtendedAVLNode*>(nodeToRemove->GetParent());
      }

      return removed;
   }

public:
   virtual int GetNthKey(int n) override {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }

    return GetNthKeyRecursive(static_cast<AVLNode*>(root), n); // Cast root to AVLNode*
}

// Recursive helper function to find the nth largest key
int GetNthKeyRecursive(AVLNode* node, int& n) {
    // Check if there's a right subtree
    if (node->GetRight()) {
        // Determine the number of keys in the right subtree
        int rightSubtreeKeys = static_cast<ExtendedAVLNode*>(node->GetRight())->GetSubtreeKeyCount(); // Cast right child to ExtendedAVLNode*

        // If the count is greater than or equal to n, the nth largest key is in the right subtree
        if (rightSubtreeKeys >= n) {
            return GetNthKeyRecursive(static_cast<AVLNode*>(node->GetRight()), n); // Cast right child to AVLNode*
        }

        // Adjust n to search in the left subtree
        n -= rightSubtreeKeys;
    }

    // Check if the current node is the nth largest
    if (--n == 0) {
        return node->GetKey();
    }

    // Search in the left subtree
    if (node->GetLeft()) {
        return GetNthKeyRecursive(static_cast<AVLNode*>(node->GetLeft()), n); // Cast left child to AVLNode*
    }

    // This should not be reached
    throw std::runtime_error("Error finding nth key");
}

};

#endif

