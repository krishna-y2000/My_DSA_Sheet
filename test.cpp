//  // base case: tree is empty
//     if (root == nullptr) {
//         return 0;
//     }
 
//     // calculate the maximum node-to-leaf sum for the left child
//     int left = getRootToLeafSum(root->left);
 
//     // calculate the maximum node-to-leaf sum for the right child
//     int right = getRootToLeafSum(root->right);
 
//     // consider the maximum sum child
//     return (left > right? left : right) + root->data;