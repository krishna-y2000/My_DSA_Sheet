
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


// Level Order traversal 
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> cur;
            for(int i=0;i<size;i++){
                Node* tmp=q.front();q.pop();
                cur.push_back(tmp->val);
                for(Node* child:tmp->children)
                    if(child) q.push(child);
            }
            res.push_back(cur);
        }
        return res;
    }
};


// Preorder traversal 
class Solution {
private:
    void travel(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        result.push_back(root -> val);
        for (Node* child : root -> children) {
            travel(child, result);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        travel(root, result);
        return result;
    }
};




int main() {
   Node *root = newNode(1);
   root->children.push_back(newNode(2));
   root->children.push_back(newNode(3));
   root->children.push_back(newNode(4));
   root->children[0]->children.push_back(new newNode(5));  // In 2 -> 5
   root->children[0]->children.push_back(new newNode(6));  // In 2 -> 6
   root->children[1]->children.push_back(new newNode(7));  // In 3 -> 7
   root->children[2]->children.push_back(new newNode(8));  // In 4 -> 8
   cout << findDepthOfTree(root) << endl;
   return 0;
}