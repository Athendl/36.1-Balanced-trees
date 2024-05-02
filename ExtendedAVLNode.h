//My Code (Edited from teachers)
#ifndef EXTENDEDAVLNODE_H
#define EXTENDEDAVLNODE_H

#include "AVLNode.h"

class ExtendedAVLNode : public AVLNode {
protected:
   int subtreeKeyCount;

public:
   ExtendedAVLNode(int nodeKey) : AVLNode(nodeKey) {
      subtreeKeyCount = 1;
   }
   
   virtual int GetSubtreeKeyCount() override {
      return subtreeKeyCount;
   }
   
   // Update the subtree key count recursively
   virtual void UpdateSubtreeKeyCount() {
      // Initialize with 1 for the current node
      subtreeKeyCount = 1;
      
      // If left child exists, add its subtree count
      if (GetLeft()) {
         subtreeKeyCount += ((ExtendedAVLNode*)GetLeft())->GetSubtreeKeyCount();
      }
      
      // If right child exists, add its subtree count
      if (GetRight()) {
         subtreeKeyCount += ((ExtendedAVLNode*)GetRight())->GetSubtreeKeyCount();
      }
   }
   // Update the subtree key count of a node
	virtual void UpdateSubtreeKeyCount(ExtendedAVLNode* node) {
	    int leftCount = (node->GetLeft()) ? static_cast<ExtendedAVLNode*>(node->GetLeft())->GetSubtreeKeyCount() : 0;
	    int rightCount = (node->GetRight()) ? static_cast<ExtendedAVLNode*>(node->GetRight())->GetSubtreeKeyCount() : 0;
	    node->subtreeKeyCount = leftCount + rightCount + 1; // Directly modify the private member
	}

};

#endif

